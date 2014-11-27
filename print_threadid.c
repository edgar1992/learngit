#include <stdio.h>
#include <pthread.h>

pthread_t ntid;

void printids(const char *s)
{
  pid_t     pid;
  pthread_t tid;
  
  pid = getpid();
  tid = pthread_self();
  printf("%s \tpid : %u tid %u \n", s, (unsigned int)pid,(unsigned int)tid); 
}

void *thr_fn(void *arg)
{
  printids("new thread: ");
}

int main()
{
  pthread_create(&ntid, NULL, thr_fn, NULL);
  printids("main thread: ");
  sleep(1);
}
