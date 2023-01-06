#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

void main(){
	struct stat fs;
	if( lstat("hello.txt" , &fs) < 0 ){
		return;
	}
	printf("File size => %d\nFile mode => %d\n",fs.st_size,fs.st_ino);
}
