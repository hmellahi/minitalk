#include <stdio.h>
#include <signal.h>
#include <time.h>

/* Ssshhh! Global variables!  We need
   these so that main() and sh1 & sh2
   can communicate. */
char sym = 'X';
FILE *fp = NULL;

void sh1(int st)
{
  signal(SIGUSR1,sh1);
  fscanf(fp,"%c",&sym);
}

void sh2(int st)
{
  fp = fopen("foo","r");
  setbuf(fp,NULL);
}

int main()
{
  /* Register signal handlers. */
  signal(SIGUSR2,sh2);
  signal(SIGUSR1,sh1);

  /* Print sym forever: Uncomment the stuff below if you
                        are running this remotely! */
  setbuf(stdout,NULL);
  /*struct timespec T, D; T.tv_sec = 0; T.tv_nsec = 5000000;*/
  while(1)
    printf("     %c",sym)/*,nanosleep(&T,&D)*/;
  return 0;
}