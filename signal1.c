/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


volatile sig_atomic_t hand_executed = 0;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  hand_executed = 1;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 seconds
  while(!hand_executed){
    
  }; 
  printf("Turing was right !\n")//busy wait for signal to be delivered
  return 0; //never reached
}