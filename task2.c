#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

        int NUMBER_OF_PROCESSES = 1;
	pid_t pid = 0;

        while(NUMBER_OF_PROCESSES < 5){
       
     	 pid = fork();
	 if(pid < 0){
	   printf("couldnt create process");
	   exit(1);
	 }
      	 else if(pid == 0){
		sleep(1);
        	printf("process: %d, pid = %d\n ",NUMBER_OF_PROCESSES, getpid());
       		return 0;
         }
         else if(pid > 0){
        	printf("hello from parent process\n");
         }

         NUMBER_OF_PROCESSES++;
        }

	pid = fork();

	if(pid == 0){
	   execl("/bin/ps", "ps", "-l", NULL);
	   printf("shouldnt run");
	}


        return 0;
}