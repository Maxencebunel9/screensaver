#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        FILE *F;
        char c[2]="";
	if ((F=fopen("nom.txt","r"))==NULL)
		return EXIT_FAILURE;

c[0] = fgetc(F);
        F=fopen("nom.txt","r");
                printf("%s\n",c);
		printf("%s\n",c);

if(strcmp(c, "1") == 0)
{
printf("reussi");
}
fclose(F);
return EXIT_SUCCESS;
}
