#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    int fd[2];
    pid_t pid;
    char write_msg[] = "Greetings";
    char read_msg[64];

    if (pipe(fd) == -1)
	{
        perror("pipe");
        return 1;
    }
    
    pid = fork();
    
    if (pid < 0)
	{
        perror("fork");
        return 1;
    }
    if(pid > 0) 
	{ 
        close(fd[0]);
        ssize_t wrote = write(fd[1], write_msg, strlen(write_msg) + 1);
        if(wrote == -1)
		{
            perror("write");
            close(fd[1]);
            return 1;
        }
        close(fd[1]);
        waitpid(pid, NULL, 0);
    }
	else
	{
        close(fd[1]);
        ssize_t n = read(fd[0], read_msg, sizeof(read_msg));
        if (n == -1)
		{
            perror("read");
            close(fd[0]);
            return 1;
        }
        if (n >= (ssize_t)sizeof(read_msg)) read_msg[sizeof(read_msg)-1] = '\0';
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    }
    return 0;
}

