#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>
void main(){
	struct dirent *de;
	struct stat fi;
	DIR *dr = opendir(".");
	if(dr == NULL){
		printf("Unable to open the specified directory\n");
		return;
	}
	printf("The files in the current directory are\n");
	while((de = readdir(dr)) != NULL){
		lstat(de->d_name,&fi);
		if((fi.st_mode & S_IFMT) == S_IFREG){

			printf("\n%s\nFile Mode - %d\n",de->d_name,fi.st_mode);
			printf("I node number - %ld\n",(long)fi.st_ino);
			printf("Link Count - %ld\n",(long)fi.st_nlink);

			printf("Ownership: UID=%ld   GID=%ld\n",(long) fi.st_uid, (long) fi.st_gid);
           		printf("File size: %lld bytes\n",(long long) fi.st_size);
         	        printf("Blocks allocated: %lld\n",(long long) fi.st_blocks);

           		printf("Last status change:       %s", ctime(&fi.st_ctime));
         		printf("Last file access:         %s", ctime(&fi.st_atime));
        	        printf("Last file modification:   %s", ctime(&fi.st_mtime));
		}
	}	
	closedir(dr);
}
