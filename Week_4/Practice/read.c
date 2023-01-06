#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
    int sz;
    int fd = open("Hello", O_RDONLY);
    char *c = (char *)calloc(100, sizeof(char));
    if(fd < 0){
        perror("r1");
        exit(1);
    }
    sz = read(fd,c,100);
    c[sz] = '\0';
    printf("%s\n",c);
    close(fd);
    return 0;
}


