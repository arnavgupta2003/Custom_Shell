#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(strcmp(argv[1],"nop")==0){
		time_t t = time(NULL);
		printf("%s\n",ctime(&t));
	}else if(strcmp(argv[1],"-d")==0 || strcmp(argv[1],"--show-date")==0){
		time_t t = time(NULL);
		struct tm tn = *localtime(&t);
		printf("%d-%02d-%02d\n\n",tn.tm_mday,tn.tm_mon+1,tn.tm_year+1900);
	}else if(strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0){
		printf("Usage: date [OPTION]\nDisplay the current time.\n");
		printf("Allowed arguments.\n");
		printf("\t -t, --show-time \t display only time \n");
		printf("\t -d, --show-date \t\t display only date\n");   
		printf("\t -h, --help \t\t help \n");
	}else if(strcmp(argv[1],"-t")==0 || strcmp(argv[1],"--show-time")==0){
		time_t t = time(NULL);
		struct tm tn = *localtime(&t);
		printf("%02d:%02d:%02d\n\n",tn.tm_hour,tn.tm_min,tn.tm_sec);
	}else{
		printf("Wrong date usage\n");
	}
	return 0;
}