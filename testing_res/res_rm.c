#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(strcmp(argv[1],"nop")==0){
		remove(argv[2]);
	}else if(strcmp(argv[1],"-f")==0 || strcmp(argv[1],"--force")==0){
		remove(argv[2]);
	}else if(strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0){
		printf("Usage: rm [OPTION]\nRemove the FILE\n");
		printf("Allowed arguments.\n");
		printf("\t -f, --force \t ignore nonexistent files and arguments, never prompt \n");
		printf("\t -v, --verbos \t\t Explain what is being done\n");   
		printf("\t -h, --help \t\t help \n");
	}else if(strcmp(argv[1],"-v")==0 || strcmp(argv[1],"--verbose")==0){
		if(remove(argv[2])==0){
			printf("File %s removed sucessfully\n",argv[2]);
		}else{
			printf("File not deleted\n Maybe beacuse no such file");
		}
	}else{
		printf("Wrong rm usage\n");
	}
	return 0;
}