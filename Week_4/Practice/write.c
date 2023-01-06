#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
    int sz;
    int fd = open("Hello", O_WRONLY, 0644);
    if(fd < 0){
        perror("r1");
        exit(1);
    }
    sz = write(fd, "Hello World!", strlen("Hello World!"));
    close(fd);
    return 0;
}


