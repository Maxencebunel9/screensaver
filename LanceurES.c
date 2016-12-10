#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "BibliLanceurES.h"

int main(int argc, char* argv[])
{
  //Déclaration de variables d'environnement
  setenv("EXIASAVER_HOME","/EXIASAVER_HOME",1);
  setenv("EXIASAVER1_PBM","EXIASAVER1_PBM",1);
  setenv("EXIASAVER2_PBM","/EXIASAVER2_PBM",1);
  setenv("EXIASAVER2_TAILLE","5x3",1);
  setenv("EXIASAVER2_SLEEP","10",1);
  setenv("EXIASAVER3_PBM","/EXIASAVER3_PBM",1);
  
  //Déclaration de variables utilisées dans ce programme
  int nbProgramme = 0; //variable stockant le numero du programme a executé
  int pid; //variable permettant de savoir s'il s'agit du proccesus père ou fils
  int fichierChoisi;
  char chemin[256]="";
  
  system("clear");
  if (argc == 1)
    {
      //détermination aléatoire du programme a lancé
      srand(time(NULL));
      nbProgramme = (rand() % 3) + 1;
      printf("le programme à lancer est le numero %d\n", nbProgramme);
      pid = fork();
      if (pid == 0)
	{
	  if (nbProgramme == 1)
	    {
	      fichierChoisi = (rand() % 5) + 1 ;
	      printf("le fichier a affiche est le %d\n", fichierChoisi);
	      choixFichier(fichierChoisi,chemin);
	      printf("%s variable recup\n",chemin);
	      execl("EXIASAVER_HOME/exiasaver1",chemin,NULL);
	      exit(1);
	    }
	}
      else
	{
	  wait(NULL);
	}
    }
  else if(argc == 2 && strcmp(argv[1],"-stats") == 0)
    {
      printf("lancement du programme statistique\n");
    }
  else
    {
      printf("les arguments sont incorrect\n");
    }
  return (0);
}
