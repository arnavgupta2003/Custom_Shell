#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	if(strcmp(argv[1],"nop")==0){
		FILE *fptr;
		fptr = fopen(argv[2],"r");
		if(fptr==NULL){
			printf("Could not find the specified file\n");
		}else{
			char line[500];
			while(fgets(line,sizeof(line),fptr)){
				printf("%s",line );
			}
			printf("\n");
		}
		fclose(fptr);
	}else if(strcmp(argv[1],"-E")==0 || strcmp(argv[1],"--show-ends")==0){
		FILE *fptr;
		fptr = fopen(argv[2],"r");
		if(fptr==NULL){
			printf("Could not find the specified file\n");
		}else{
			char line[500];

			while(fgets(line,sizeof(line),fptr)){
				int len = strlen(line);
				if( line[len-1] == '\n' )
				    line[len-2] = '$';
				printf("%s",line);
			}
			printf("\n");
		}
		fclose(fptr);
	}else if(strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0){
		printf("Usage: cat [OPTION] [FILE]\n");
		printf("Allowed arguments.\n");
		printf("\t -E, --show-ends \t display $ at end of each line\n");
		printf("\t -n, --number \t\t number all output lines\n");   
		printf("\t -h, --help \t\t help \n");
	}else if(strcmp(argv[1],"-n")==0 || strcmp(argv[1],"--number")==0){
		FILE *fptr;
		fptr = fopen(argv[2],"r");
		if(fptr==NULL){
			printf("Could not find the specified file\n");
		}else{
			char line[500];
			int cnt=1;
			while(fgets(line,sizeof(line),fptr)){
				
				printf("%d %s",cnt,line);cnt++;
			}
			printf("\n");
		}
		fclose(fptr);
	}else{
		printf("Wrong cat usage\n");
	}
	return 0;
}