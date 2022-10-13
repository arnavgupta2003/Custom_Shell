#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	if(strcmp(argv[1],"nop")==0){
		mkdir(argv[2],0777);
	}else if(strcmp(argv[1],"-p")==0 || strcmp(argv[1],"--parents")==0){
		mkdir(argv[2],0777);
	}else if(strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0){
		printf("Usage: mkdir [OPTION] DIRECTORY\nCreates the directory\n");
		printf("Allowed arguments.\n");
		printf("\t -p, --parents \t\t no error if existing, make parent directories as needed \n");
		printf("\t -v, --verbos \t\t Explain what is being done\n");   
		printf("\t -h, --help \t\t help \n");
	}else if(strcmp(argv[1],"-v")==0 || strcmp(argv[1],"--verbose")==0){
		
		if(mkdir(argv[2],0777)==-1){
			printf("Directory %s already exists\n",argv[2]);
		}else{
			printf("Directory created\n");
		}
	}else{
		printf("Wrong rm usage\n");
	}
	return 0;
}