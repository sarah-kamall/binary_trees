#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int X;
int *arr;
int n;
pid_t first_child;
pid_t second_child;

void sigusr1_handler(int signum) {
    int status;
    

    int child_pid = wait(&status);
    
   

    if (child_pid == first_child) {
      
            int position = WEXITSTATUS(status);
            printf("Child 1: Value %d found at position %d\n", X, position);
            kill(second_child, SIGKILL);
        
        
    } else if (child_pid == second_child) {
     
            int position = WEXITSTATUS(status);
            printf("Child 2: Value %d found at position %d\n", X, position);

            kill(first_child, SIGKILL);
        
    }

    kill(getpid(), SIGKILL);
 
}

void search_value(int start, int end, int child_num) {
    for (int i = start; i < end; i++) {
        if (arr[i] == X) {
            kill(getppid(), SIGUSR1);
            exit(i);
        }
    }
    sleep(3);
    printf("Child %d terminates\n", child_num);
    exit(0);
}

int main(int argc, char *argv[]) {
   
    if (argc < 3) {
        printf("Usage: %s <X> <list of integers>\n", argv[0]);
        return 1;
    }
    X = atoi(argv[1]);

    n = argc - 2;

    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 2]);
    }

    printf("I am the parent, PID = %d\n", getpid());
    signal(SIGUSR1, sigusr1_handler);
    first_child = fork();
    
    
    
    if (first_child < 0) {
        printf("Fork failed\n");
        return 1;
    }


    if (first_child==0) {
        printf("I am the first child, PID = %d, PPID = %d\n", getpid(), getppid());
        search_value(0, n / 2, 1);
    }
    second_child = fork();
     if (second_child < 0) {
        printf("Fork failed\n");
        return 1;
    }
    if (second_child==0) {
        printf("I am the second child, PID = %d, PPID = %d\n", getpid(), getppid());
        search_value(n / 2 , n, 2);
    }

    sleep(5);

    
    //parent becaus exit code is returned to parent
    wait(NULL);
    wait(NULL);

    printf("Value Not Found\n");

    free(arr);

    return 0;
}
