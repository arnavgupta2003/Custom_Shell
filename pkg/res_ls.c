#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{

	if(strcmp(argv[1],"nop")==0){
		DIR *di;
		struct dirent *directory;
		di = opendir(".");
		if(di){
			while((directory = readdir(di))!=NULL){
				if(strcmp(directory->d_name,".")==0){
				}else if(strcmp(directory->d_name,"..")==0){
				}else{
					printf(directory->d_name);printf("\n");
				}
				
			}
			closedir(di);
		}
	}else if(strcmp(argv[1],"-d")==0 || strcmp(argv[1],"--directory")==0){
		printf(".\n");
	}else if(strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0){
		printf("Usage: ls [OPTION] \n");
		printf("Allowed arguments.\n");
		printf("\t -d, --directory \t list directories themselves, not their contents\n");
		printf("\t -a, --all \t\t do not ignore entries starting with .\n");
		printf("\t -h, --help \t\t help \n");
	}else if(strcmp(argv[1],"-a")==0 || strcmp(argv[1],"--all")==0){
		DIR *di;
		struct dirent *directory;
		di = opendir(".");
		if(di){
			while((directory = readdir(di))!=NULL){
				
				printf(directory->d_name);printf("\n");
				
			}
			closedir(di);
		}
	}else{
		printf("Wrong ls usage\n");
	}
	return 0;
}

