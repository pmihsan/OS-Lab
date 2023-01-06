#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
int main(){
	struct dirent *de;
	struct stat file_info;
	DIR *dr = opendir(".");
	if(dr == NULL){
		printf("Could not open the current directory\n");
		return 0;
	}
	printf("The current directory contents are\n");
	while( (de = readdir(dr)) != NULL){
		printf("%s\n",de->d_name);
		lstat(de->d_name, &file_info); // get the file info
		printf("file mode: %d => ",file_info.st_mode);
		if ((file_info.st_mode  & S_IFMT ) == S_IFDIR) puts("directory\n");
	        if ((file_info.st_mode  & S_IFMT ) == S_IFREG) puts("regular file\n");
		if ((file_info.st_mode   & S_IFMT) == S_IFLNK) puts("symbolic link\n");
		
		//if ((file_info.st_mode   & S_IFMT) == S_IFCHR) puts("character device\n");

		//if ((file_info.st_mode   & S_IFMT) == S_IFBLK) puts("block device\n");
		//if ((file_info.st_mode   & S_IFMT) == S_IFSOCK) puts("socket\n");
		//if ((file_info.st_mode   & S_IFMT) == S_IFIFO) puts("pipe\n");
		//else	puts("unknown\n");
	}
	closedir(dr);
	return 0;
}
