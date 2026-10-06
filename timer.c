/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile sig_atomic_t hand_executed = 0;
int alarms_delivered = 0;
time_t start_time;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  alarms_delivered++;
  hand_executed = 1;
}
void sigint_handler(int signum){
  time_t end_time = time(NULL);
  double total_time = difftime(end_time,start_time);

  printf("\nTotal alarms delivered: %d\n", alarms_delivered);
  printf("Total execution time: %.0f seconds \n",total_time);

}

int main(int argc, char * argv[])
{
  start_time = time(NULL);
  signal(SIGALRM,handler);
  signal(SIGINT, sigint_handler); //register handler to handle SIGALRM
  while(1){
    hand_executed = 0;
    alarm(1);
    while(!hand_executed){
    
  }; 
    printf("Turing was right !\n")//busy wait for signal to be delivered

  };  
  return 0; //never reached
}