#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(){
    int fd = open("Hello", O_RDONLY, 0);
    printf("%d\n",fd);
    close(fd);
    return 0;
}
