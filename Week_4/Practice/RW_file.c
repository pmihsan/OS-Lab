#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(){
    creat("sample.txt", S_IRUSR | S_IWUSR);
    int fd = open("1.txt", O_RDONLY);
    char *c = (char *)calloc(100, sizeof(char));
    if(fd < 0){
        perror("r1");
        exit(1);
    }
    int sz = read(fd,c,100);
    c[sz] = '\0';
    close(fd);
    int fd1 = open("sample.txt",O_WRONLY);
    if(fd1 < 0){
        perror("r1");
        exit(1);
    }
    sz = write(fd1, c, strlen(c));
    close(fd1);
    return 0;
}
