#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    char *c = (char *)calloc(100, sizeof(char));
    int fd = open("Hello", O_RDWR);
    printf("fd = %d\n",fd);
    if(fd == -1){
        printf("Error Number %d\n",errno);
        perror("Program\n");
    }
    int sz = read(fd,c,100);
    c[sz] = '\0';
    printf("%s\n",c);
    sz = write(fd, "\nHow are you?", strlen("\nHow are you?"));
    close(fd);
    return 0;
}


