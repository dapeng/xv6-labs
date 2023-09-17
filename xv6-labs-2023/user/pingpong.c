#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if(argc > 1) {
        fprintf(2, "Usage: pingpong\n");
        exit(1);
    }
    
    const char* ping="ping";
    const char* pong="pong";
    
    int p2c[2];
    int c2p[2];
    pipe(p2c);  // create a pipe
    pipe(c2p);
    
    int pid = fork();  // create a child process
    char buf[100];
    if(pid < 0) {
        fprintf(2, "Error: fork failed.\n");
        exit(1);
    } else if(pid == 0) {
        // child
        close(p2c[1]);  // 关闭写入端
        if(read(p2c[0], buf, 4)) {
            fprintf(1, "%d: received %s\n", getpid(), buf);
            close(p2c[0]);

            close(c2p[0]);
            write(c2p[1], pong, 4);
            close(c2p[1]);
        }
    } else {
        // parent
        close(p2c[0]);
        write(p2c[1], ping, 4);
        close(p2c[1]);

        close(c2p[1]);
        if(read(c2p[0], buf, 4)) {       
            fprintf(1, "%d: received %s\n", getpid(), buf);
            close(c2p[0]);
        }
    }
    exit(0);
}
