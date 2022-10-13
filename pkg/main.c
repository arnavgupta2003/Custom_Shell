#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void kern();
void changeDir();
void* ls_thread();
void* cat_thread();
void* date_thread();
void* rm_thread();
void* mkdir_thread();
struct args{
	char* arg;
	char* para1;
	char* para2;
	char* para3;
};

int main(int argc, char const *argv[])
{
	printf("\n");
	kern();
	printf("\n");
	return 0;
}
void kern(){
	while(1){
		printf("ASH>");
		char s[100001];
		fgets(s,sizeof(s),stdin);
		if((strcmp(s,"\r")==0)||(strcmp(s,"\n")==0)){
			continue;
		}

		//Other param
		char *tokens = strtok(s," ");

		//cd CMD
		if(strcmp(tokens,"cd")==0){
			char *dir1=strtok(NULL," ");tokens=dir1;
			char *dir2=strtok(NULL," ");tokens=dir2;
			if(dir2==NULL){
				//Removing \n
				dir1=strtok(dir1,"\n");
				changeDir(dir1);
			}else{
				if(strcmp(dir1,"-v")==0 || strcmp(dir1,"-verbose")==0){
					dir2=strtok(dir2,"\n");
					changeDir(dir2);
				}else if(strcmp(dir1,"-f")==0){
					dir2=strtok(dir2,"\n");
					changeDir(dir2);
				}
			}
			

		}else if(strcmp(s,"cd\n")==0){
			printf("%s\n","cd USAGE: \ncd <Destination Directory>\n");
		}
		//End cd CMD

		//exit CMD
		else if(strcmp(s,"exit\n")==0){
			printf("Bye\n");
			return;
		}
		//End exit CMD
		//pwd CMD
		else if(strcmp(s,"pwd\n")==0){
			char dir[1000];
			printf("%s\n",getcwd(dir,1000));
		}else if(strcmp(tokens,"pwd")==0){
			char *para1=strtok(NULL," ");tokens=para1;
			//Removing \n
			para1=strtok(para1,"\n");
			if(strcmp(para1,"-P")==0 || strcmp(para1,"--physical")==0){
				char dir[1000];
				printf("%s\n",getcwd(dir,1000));
			}else if(strcmp(para1,"-h")==0 || strcmp(para1,"--help")==0){
				printf("Usage: pwd [OPTION]\n");
				printf("Allowed arguments.\n");
				printf("\t -L, --cwd \t print the value of $PWD if it names the current working directory\n");
				printf("\t -P, --physical  print the physical directory, without any symbolic links\n");   
				printf("\t -h, --help \t help \n");
			}else if(strcmp(para1,"-L")==0 || strcmp(para1,"--cwd")==0){
				char dir[1000];
				printf("%s\n",getcwd(dir,1000));
			}else{
				printf("Wrong pwd usage\n");
			}
		}
		//End pwd CMD
		//echo CMD
		else if(strcmp(tokens,"echo")==0){
			char *para1=strtok(NULL," ");tokens=para1;
			char *para2=strtok(NULL," ");tokens=para2;
			if(para2==NULL){
				para1=strtok(para1,"\n");
				if(strcmp(para1,"-h")==0 || strcmp(para1,"--help")==0){
					printf("Usage: echo [OPTION] [STATEMENT]\n");
					printf("Allowed arguments.\n");
					printf("\t -n,  \t\t do not output the trailing new line\n");
					printf("\t -v, --verbose \t Describe each event as it occurs\n");   
					printf("\t -h, --help \t help \n");
				}else{
					//Removing \n
					
					printf(para1);printf("\n\n");
				}
			}else if(strcmp(para1,"-n")==0){
				para2=strtok(para2,"\n");
				printf(para2);printf("\n");
			}else if(strcmp(para1,"-v")==0 || strcmp(para1,"--verbose")==0){

				para2=strtok(para2,"\n");
				printf("**Printing STATEMENT**\n");
				printf(para2);printf("\n\n");
				printf("**Printed STATEMENT**\n");
			}else{
				printf("Wrong echo usage\n");
			}
			
		}else if(strcmp(s,"echo\n")==0){
			printf("%s\n","echo USAGE: \necho <Data>\n");
		}
		//End echo CMD
		//ls CMD
		else if(strcmp(s,"ls\n")==0){
			ls_fork("nop");
		}//ls for Para
		else if(strcmp(tokens,"ls")==0){

			char *para1=strtok(NULL," ");tokens=para1;
			char *para2=strtok(NULL," ");tokens=para2;
			

			if(para2!=NULL){

				//PTHREAD_CREATE OP
				//TBd
				//printf("In main fpr pthread\n");
				para2=strtok(para2,"\n");
				pthread_t ptid;
				struct args *ag = (struct args*)malloc(sizeof(struct args));
				ag->arg = NULL;
				ag->para1=para1;


				pthread_create(&ptid,NULL,&ls_thread,(void *)ag);
				
				pthread_join(ptid,NULL);

			}else{
				if(strcmp(para1,"&t\n")==0){
					//PTHREAD_CREATE OP for basic ls
					pthread_t ptid;
					struct args *ag = (struct args*)malloc(sizeof(struct args));
					ag->arg = NULL;
					ag->para1="nop";


					pthread_create(&ptid,NULL,&ls_thread,(void *)ag);
					
					pthread_join(ptid,NULL);
					//printf("Pthread here\n");
				}else{
					ls_fork(para1);
				}
			}
		}
		//End ls CMD
		//cat CMD
		else if(strcmp(s,"cat\n")==0){
			printf("cat: invalid option\nTry 'cat --help' for more information \n");
		}else if(strcmp(tokens,"cat")==0){
			char *para1=strtok(NULL," ");tokens=para1;
			char *para2=strtok(NULL," ");tokens=para2;
			char *para3=strtok(NULL," ");tokens=para3;

			if(para3!=NULL){
				if(strcmp(para3,"&t\n")==0){
					//printf("Thread 1\n");
					//PTHREAD_CREATE OP
					//TBd
					//printf("In main fpr pthread\n");
					para2=strtok(para2,"\n");
					pthread_t ptid;
					struct args *ag = (struct args*)malloc(sizeof(struct args));
					ag->arg = NULL;
					ag->para1=para1;
					ag->para2=para2;

					pthread_create(&ptid,NULL,&cat_thread,(void *)ag);
					
					pthread_join(ptid,NULL);
				}else{
					printf("Wrong &t usage\n");
				}
			}else if(para2!=NULL){
				if(strcmp(para2,"&t\n")==0){
					//printf("Thread 2\n");
					//PTHREAD_CREATE OP for cat
					pthread_t ptid;
					struct args *ag = (struct args*)malloc(sizeof(struct args));
					ag->arg = NULL;
					ag->para1="nop";
					ag->para2=para1;

					pthread_create(&ptid,NULL,&cat_thread,(void *)ag);
					
					pthread_join(ptid,NULL);
					//printf("Pthread here\n");
				}else{
					para2=strtok(para2,"\n");
					cat_fork(para1,para2);
				}
			}else if(para1!=NULL){
				para1=strtok(para1,"\n");
				if(strcmp(para1,"-h")==0 || strcmp(para1,"--help")==0){
					cat_fork(para1,"redd");
				}else{
					cat_fork("nop",para1);
				}	
			}else{
				printf("cat :Specify file path\n");
			}
		}
		//End cat CMD
		//date CMD
		else if(strcmp(s,"date\n")==0){
			date_fork("nop");
		}else if(strcmp(tokens,"date")==0){
			char *para1=strtok(NULL," ");tokens=para1;
			char *para2=strtok(NULL," ");tokens=para2;
			

			if(para2!=NULL){
				if(strcmp(para2,"&t\n")==0){
					//PTHREAD_CREATE OP
					//TBd
					//printf("In main fpr pthread\n");
					para2=strtok(para2,"\n");
					pthread_t ptid;
					struct args *ag = (struct args*)malloc(sizeof(struct args));
					ag->arg = NULL;
					ag->para1=para1;

					pthread_create(&ptid,NULL,&date_thread,(void *)ag);
					
					pthread_join(ptid,NULL);
				}else{
					printf("Wrong date usage\n");
				}
			}else{
				if(strcmp(para1,"&t\n")==0){
					//PTHREAD_CREATE OP for date
					pthread_t ptid;
					struct args *ag = (struct args*)malloc(sizeof(struct args));
					ag->arg = NULL;
					ag->para1="nop";


					pthread_create(&ptid,NULL,&date_thread,(void *)ag);
					
					pthread_join(ptid,NULL);
					//printf("Pthread here\n");
				}else{
					date_fork(para1);
				}
			}
		}
		//End date CMD
		//rm CMD //check for error at rm -h
		else if(strcmp(s,"rm\n")==0){
			printf("rm: invalid option\nTry 'rm --help' for more information \n");
		}else if(strcmp(tokens,"rm")==0){
			char *para1=strtok(NULL," ");tokens=para1;
			char *para2=strtok(NULL," ");tokens=para2;
			char *para3=strtok(NULL," ");tokens=para3;

			if(para3!=NULL){
				if(strcmp(para3,"&t\n")==0){
					//printf("Thread 1\n");
					//PTHREAD_CREATE OP
					//TBd
					//printf("In main fpr pthread\n");
					// para2=strtok(para2,"\n");
					pthread_t ptid;
					struct args *ag = (struct args*)malloc(sizeof(struct args));
					ag->arg = NULL;
					ag->para1=para1;
					ag->para2=para2;

					pthread_create(&ptid,NULL,&rm_thread,(void *)ag);
					
					pthread_join(ptid,NULL);
				}else{
					printf("Wrong &t usage\n");
				}
			}else if(para2!=NULL){
				if(strcmp(para2,"&t\n")==0){
					//printf("Thread 2\n");
					//PTHREAD_CREATE OP for cat
					pthread_t ptid;
					struct args *ag = (struct args*)malloc(sizeof(struct args));
					ag->arg = NULL;
					ag->para1="nop";
					ag->para2=para1;

					pthread_create(&ptid,NULL,&rm_thread,(void *)ag);
					
					pthread_join(ptid,NULL);
					//printf("Pthread here\n");
				}else{
					para2=strtok(para2,"\n");
					rm_fork(para1,para2);
				}
			}else if(para1!=NULL){
				para1=strtok(para1,"\n");
				if(strcmp(para1,"-h")==0 || strcmp(para1,"--help")==0){
					rm_fork(para1,"redd");
				}else{
					rm_fork("nop",para1);
				}	
			}else{
				printf("rm :Specify file path\n");
			}
		}
		//End rm CMD
		//mkdir CMD
		else if(strcmp(s,"mkdir\n")==0){
			printf("mkdir: missing operand\nTry 'mkdir --help' for more information.\n");
		}else if(strcmp(tokens,"mkdir")==0){
			char *para1=strtok(NULL," ");tokens=para1;
			char *para2=strtok(NULL," ");tokens=para2;
			char *para3=strtok(NULL," ");tokens=para3;

			if(para3!=NULL){
				if(strcmp(para3,"&t\n")==0){
					//printf("Thread 1\n");
					//PTHREAD_CREATE OP
					//TBd
					//printf("In main fpr pthread\n");
					// para2=strtok(para2,"\n");
					pthread_t ptid;
					struct args *ag = (struct args*)malloc(sizeof(struct args));
					ag->arg = NULL;
					ag->para1=para1;
					ag->para2=para2;

					pthread_create(&ptid,NULL,&mkdir_thread,(void *)ag);
					
					pthread_join(ptid,NULL);
				}else{
					printf("Wrong &t usage\n");
				}
			}else if(para2!=NULL){
				if(strcmp(para2,"&t\n")==0){
					//printf("Thread 2\n");
					//PTHREAD_CREATE OP for cat
					pthread_t ptid;
					struct args *ag = (struct args*)malloc(sizeof(struct args));
					ag->arg = NULL;
					ag->para1="nop";
					ag->para2=para1;

					pthread_create(&ptid,NULL,&mkdir_thread,(void *)ag);
					
					pthread_join(ptid,NULL);
					//printf("Pthread here\n");
				}else{
					para2=strtok(para2,"\n");
					mkdir_fork(para1,para2);
				}
			}else if(para1!=NULL){
				para1=strtok(para1,"\n");
				if(strcmp(para1,"-h")==0 || strcmp(para1,"--help")==0){
					mkdir_fork(para1,"redd");
				}else{
					mkdir_fork("nop",para1);
				}	
			}else{
				printf("mkdir :Specify directory\n");
			}
		}
		//End mkdir CMD
	}
}
void changeDir(char *path){
	int retCode;

	if (path[0] == '.') {
		char temp[1000];
		getcwd(temp, sizeof(temp));
		strcat(temp,"/");
		strcat(temp,path);
		retCode = chdir(temp);	
	}else if(path[0] == '-' && path[1]=='h'){
		printf("Usage: cd [DIRECTORY]\n\n");
		printf("Allowed arguments.\n");
		printf("\t -v, --verbose \t display information regarding changes\n");
		printf("\t -f,  \t\t force changes\n");   
		printf("\t -h, --help \t help \n");
	}
	else {
		retCode = chdir(path);
	}


	if(retCode==-1){
		printf("Invalid Path.. Retry\n");
	}else if(retCode==0){
		char cdir[1000];
		printf("Changed working directory to: %s\n",getcwd(cdir,1000));
	}
}

void ls_fork(char *para1){
	//FORK OP
	para1=strtok(para1,"\n");

	//forking
	int r = fork();
	if(r<0){
		printf("Fork Failed\n");
		exit(1);
	}else if(r==0){
		//printf("hello, I am child (pid:%d)\n", (int) getpid());
		
		char *myargs[3];
		myargs[0] = strdup("./res_ls");
		myargs[1] = strdup(para1); 
		myargs[2] = NULL; 
		
		execvp(myargs[0], myargs);

		printf("Should nt\n");
		
	}else{
		int r_w = wait(NULL);
		//printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",r, r_w, (int) getpid());
	
	}
	return;
}
void* ls_thread(void* in){
	pthread_detach(pthread_self());

	//WPRK
	//printf("IN ls_thread\n");
	
	char* para1=((struct args*)in)->para1;
	para1=strtok(para1,"\n");
	
	char* temp[255];
	strcpy(temp,"./res_ls ");  
	strcat(temp,para1);
	
	system(temp);
	pthread_exit(NULL);

	//printf("%s\n",para1);
	// printf("{%s}\n",((struct args*)in)->arg);
	// printf("}%s{\n",((struct args*)in)->para1);
	//printf("{%s}\n",temp);
}
void cat_fork(char *para1,char *para2){
	//FORK OP

	//forking
	int r = fork();
	if(r<0){
		printf("Fork Failed\n");
		exit(1);
	}else if(r==0){
		//printf("hello, I am child (pid:%d)\n", (int) getpid());
		
		char *myargs[3];
		myargs[0] = strdup("./res_cat");
		myargs[1] = strdup(para1); 
		myargs[2] = strdup(para2);
		myargs[3] = NULL;
		
		execvp(myargs[0], myargs);

		printf("Should nt\n");
		
	}else{
		int r_w = wait(NULL);
		//printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",r, r_w, (int) getpid());
	
	}
	return;
}
void* cat_thread(void* in){
	pthread_detach(pthread_self());

	//WPRK
	//printf("IN ls_thread\n");
	
	char* para1=((struct args*)in)->para1;
	char* para2=((struct args*)in)->para2;
	para2=strtok(para2,"\n");
	
	char* temp[255];
	strcpy(temp,"./res_cat ");  
	strcat(temp,para1);//option
	strcat(temp," ");
	strcat(temp,para2);//file
	
	// printf("%s\n",para1);
	// printf("{%s}\n",((struct args*)in)->arg);
	// printf("}%s{\n",((struct args*)in)->para1);
	// printf("{%s}\n",temp);

	system(temp);
	pthread_exit(NULL);
}
void date_fork(char *para1){
	//FORK OP
	para1=strtok(para1,"\n");

	//forking
	int r = fork();
	if(r<0){
		printf("Fork Failed\n");
		exit(1);
	}else if(r==0){
		//printf("hello, I am child (pid:%d)\n", (int) getpid());
		
		char *myargs[3];
		myargs[0] = strdup("./res_date");
		myargs[1] = strdup(para1); 
		myargs[2] = NULL; 
		
		execvp(myargs[0], myargs);

		printf("Should nt\n");
		
	}else{
		int r_w = wait(NULL);
		//printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",r, r_w, (int) getpid());
	
	}
	return;
}
void* date_thread(void* in){
	pthread_detach(pthread_self());

	//WPRK
	//printf("IN ls_thread\n");
	
	char* para1=((struct args*)in)->para1;
	para1=strtok(para1,"\n");
	
	char* temp[255];
	strcpy(temp,"./res_date ");  
	strcat(temp,para1);
	
	system(temp);
	pthread_exit(NULL);

	//printf("%s\n",para1);
	// printf("{%s}\n",((struct args*)in)->arg);
	// printf("}%s{\n",((struct args*)in)->para1);
	//printf("{%s}\n",temp);
}
void rm_fork(char *para1,char *para2){
	//FORK OP

	//forking
	int r = fork();
	if(r<0){
		printf("Fork Failed\n");
		exit(1);
	}else if(r==0){
		//printf("hello, I am child (pid:%d)\n", (int) getpid());
		//printf("{%s} {%s}\n",para1,para2);
		char *myargs[3];
		myargs[0] = strdup("./res_rm");
		myargs[1] = strdup(para1); 
		myargs[2] = strdup(para2);
		myargs[3] = NULL;
		
		execvp(myargs[0], myargs);

		printf("Should nt\n");
		
	}else{
		int r_w = wait(NULL);
		//printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",r, r_w, (int) getpid());
	
	}
	return;
}
void* rm_thread(void* in){
	pthread_detach(pthread_self());

	//WPRK
	//printf("IN ls_thread\n");
	
	char* para1=((struct args*)in)->para1;
	char* para2=((struct args*)in)->para2;
	para2=strtok(para2,"\n");
	
	char* temp[255];
	strcpy(temp,"./res_rm ");  
	strcat(temp,para1);//option
	strcat(temp," ");
	strcat(temp,para2);//file
	
	// printf("%s\n",para1);
	// printf("{%s}\n",((struct args*)in)->arg);
	// printf("}%s{\n",((struct args*)in)->para1);
	// printf("{%s}\n",temp);

	system(temp);
	pthread_exit(NULL);
}
void mkdir_fork(char *para1,char *para2){
	//FORK OP

	//forking
	int r = fork();
	if(r<0){
		printf("Fork Failed\n");
		exit(1);
	}else if(r==0){
		//printf("hello, I am child (pid:%d)\n", (int) getpid());
		//printf("{%s} {%s}\n",para1,para2);
		char *myargs[3];
		myargs[0] = strdup("./res_mkdir");
		myargs[1] = strdup(para1); 
		myargs[2] = strdup(para2);
		myargs[3] = NULL;
		
		execvp(myargs[0], myargs);

		printf("Should nt\n");
		
	}else{
		int r_w = wait(NULL);
		//printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",r, r_w, (int) getpid());
	
	}
	return;
}
void* mkdir_thread(void* in){
	pthread_detach(pthread_self());

	//WPRK
	//printf("IN ls_thread\n");
	
	char* para1=((struct args*)in)->para1;
	char* para2=((struct args*)in)->para2;
	para2=strtok(para2,"\n");
	
	char* temp[255];
	strcpy(temp,"./res_mkdir ");  
	strcat(temp,para1);//option
	strcat(temp," ");
	strcat(temp,para2);//file
	
	// printf("%s\n",para1);
	// printf("{%s}\n",((struct args*)in)->arg);
	// printf("}%s{\n",((struct args*)in)->para1);
	// printf("{%s}\n",temp);

	system(temp);
	pthread_exit(NULL);
}