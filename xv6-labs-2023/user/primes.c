#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void
prime(int fd) {
    int status;
    int prime_num;
    if(read(fd, &prime_num, sizeof(int)) == 0) {
        exit(0);
    }
    printf("prime: %d\n", prime_num);
    int p[2];
    pipe(p);
    int pid = fork();
    if(pid == 0) {
        close(p[1]);
        prime(p[0]);
        exit(0);
    } else if(pid > 0) {
        close(p[0]);
        int n;
        while(read(fd, &n, sizeof(int))) {
            if(n % prime_num != 0) {
                write(p[1], &n, sizeof(int));
            }
        }
        close(p[1]);
        close(fd);
        wait(&status);
    } else {
        fprintf(2, "Error: fork failed.\n");
        exit(1);
    }
}

int
main(int argc, char *argv[]) {
    int status;
    int parent_fd[2];
    pipe(parent_fd);
    int pid = fork();
    if(pid == 0) {
        // child
        close(parent_fd[1]);
        prime(parent_fd[0]);
    } else if(pid > 0) {
        close(parent_fd[0]);  // 关闭读写端
        int i;
        for(i=2; i<=35; ++i) {
            write(parent_fd[1], &i, sizeof(int));
        }
        close(parent_fd[1]);  // 关闭写入端
        wait(&status);
    } else {
        fprintf(2, "Error: fork failed.\n");
        exit(1);
    }
    exit(0);
}