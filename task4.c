#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

long int getDifferenceInMilliSeconds(struct timeval start, struct
timeval end);
long int getDifferenceInMicroSeconds(struct timeval start, struct
timeval end);

int main(){

	struct timeval startTime, currentTime;
        int NUMBER_OF_PROCESSES = 1;
	pid_t pid = 0;
	

        while(NUMBER_OF_PROCESSES < 5){
         gettimeofday(&startTime, NULL);
     	 pid = fork();
	 if(pid < 0){
	   printf("couldnt create process");
	   exit(1);
	 }
      	 else if(pid == 0){
		gettimeofday(&currentTime, NULL);
        	printf("Hello from the child: %d with pid: %d at time: %ld \n" ,NUMBER_OF_PROCESSES, getpid(),getDifferenceInMicroSeconds(startTime,currentTime));
       		return 0;
         }
         else if(pid > 0){
        	//printf("hello from parent process\n");
         }

         NUMBER_OF_PROCESSES++;
        }


        return 0;
}


long int getDifferenceInMilliSeconds(struct timeval start, struct
timeval end) {
	int seconds = end.tv_sec- start.tv_sec;
	int useconds = end.tv_usec- start.tv_usec;
	
	int mtime = (seconds * 1000 + useconds / 1000.0);
	return mtime;
	}

long int getDifferenceInMicroSeconds(struct timeval start, struct
timeval end) {
int seconds = end.tv_sec- start.tv_sec;
int useconds = end.tv_usec- start.tv_usec;
int mtime = (seconds * 1000000 + useconds);
return mtime;
}