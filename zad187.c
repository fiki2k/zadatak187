/* Program treba IP adresu pretvorit u 32 bita int.  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

union iptolint
{
    char ip[16];
    long  n;
};

long  pretvori(char []);

int main()
{
    union iptolint ipl;
    printf("Unesi IP adresu za pretvorbu : ");
    scanf("%s",ipl.ip);

    ipl.n=pretvori(ipl.ip);

    printf("\n32-bitno dugi int je : %lu \n",ipl.n);
}

long pretvori(char ipadr[])
{
    long br=0,vrijednost;
    int p=24;
    char *tok,*ptr;
    tok=strtok(ipadr,".");
    while( tok != NULL)
    {
        vrijednost=strtol(tok,&ptr,10); // strtol pretvori vrijednost str u long int.
        br+=  vrijednost * (long)pow(2,p);
        p=p-8;
        tok=strtok(NULL,"."); // strtok podjeli string prema danom znaku, u ovom slucaju tocka.
    }
    return(br);
}
