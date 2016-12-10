#include<stdio.h>
#include<stdlib.h>

int main()
{
        FILE *F;
        int c;
	if (NULL==(F=fopen("nom.txt","r")))
		return EXIT_FAILURE;

c = fgetc(F);
        F=fopen("nom.txt","r");
                printf("%c\n",c);
		printf("%c\n",c);

if(strcmp(c, "1") == 0)
{
printf("reussi");
}
fclose(F);
return EXIT_SUCCESS;
}
