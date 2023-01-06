#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/file.h>

int main(){
	creat("Hello",S_IXUSR | S_IRUSR | S_IWUSR);
	return 0;
}

