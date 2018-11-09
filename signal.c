#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
static void sighandler(int signo){
  if (signo == SIGUSR1){
    printf("My PID: %d \n", getpid());
  }
  if (signo == SIGINT){
    printf("Worked");

    int crash = open("status.txt", O_WRONLY||O_RDONLY);
    if (crash < 0){
      perror("ERROR");
      return;
    }
    int stats = write(crash, "You're program was terminated. \n",35);
    exit(1);

  }
}

int main(){
  while(1){
    printf("I am currently running: %d \n", getpid());
    signal(SIGUSR1,sighandler);
    signal(SIGINT,sighandler);
    kill(getpid(),SIGUSR1);
    sleep(1);
  }
  return 0;
}
