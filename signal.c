#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void sighandler(int signo){
  
}

int main(){
  while(1){
    printf("I am currently running: %d \n", getpid());
    signal(SIGUSR1,sighandler);
    signal(SIGINT,sighandler);
    sleep(1);
  }
  return 0;
}
