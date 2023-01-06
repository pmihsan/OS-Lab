#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
void main(){
	creat("sample.txt", S_IRUSR | S_IWUSR | S_IXUSR);
}
