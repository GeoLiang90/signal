#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
static void sighandler(int signo){
  if (signo == SIGUSR1){
    printf("My Parent PID: %d \n", getppid());
  }
  if (signo == SIGINT){

    int crash = open("status.txt", O_CREAT|O_RDWR, 0777);
    
    if (crash < 0){
      perror("ERROR with status.txt");
      return;
    }
    lseek(crash,0,SEEK_END);
    int stats = write(crash,"SIGINT Program Terminated.\n",27);
    close(crash);
    exit(0);

  }
}

int main(){
   signal(SIGUSR1,sighandler);
   signal(SIGINT,sighandler);
  while(1){
    printf("I am currently running: %d \n", getpid());
    kill(getpid(),SIGUSR1);
    sleep(1);
  }
  return 0;
}
