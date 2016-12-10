#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void choixFichier(int n,char* chemin)
{
  DIR* repPBM;
  struct dirent* fichierLu;
  int i = 0;
  char containerFileName[256];
  
  repPBM = opendir(getenv("EXIASAVER1_PBM"));
  if (repPBM == NULL)
    {
      perror("");
    }

  while(i != n)
    {
      fichierLu = readdir(repPBM);
      if (strcmp(fichierLu->d_name,".")!=0 && strcmp(fichierLu->d_name,"..")!=0)
	{
	  strcpy(containerFileName,fichierLu->d_name);
	  i++;
	}
    }

  closedir(repPBM);
  
  strcat(chemin,"EXIASAVER1_PBM/");
  strcat(chemin,containerFileName);
}
