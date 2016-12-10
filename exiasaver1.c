#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
  int pid;
  
  printf("l'argument 1 est: %s\n", argv[0]);
  
  pid = fork();
  if (pid == 0)
    {
      printf("Salut du fils\n");
      execl("Afficheur",argv[0],NULL);
    }
  else
    {
      printf("Salut du pere\n");
      wait(NULL);
    }
  
  return (0);
}
