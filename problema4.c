#include <stdio.h>

//Int més llarg que 10 decimals

void multiplicar(int [2]);

int main()
{
    int maxim=32;
    int nombre[2];
    nombre[0]=2;
    nombre[1]=0;
    for(int i=0; i<maxim;i++)
    {
        if(nombre[1]==0)
        {
            printf("%d bit: %d numeros\n", i+1,nombre[0]);
        }
        else
        {
            printf("%d bit: %d%d numeros\n", i+1, nombre[1],nombre[0]);
        }
        
        multiplicar(nombre);
    }
    
    return 0;
}

void multiplicar(int nombre[2])
{
    int decimals=0, copia;
    int max=1e8;

    nombre[0]*=2;
    nombre[1]*=2;
    
    copia=nombre[0];
    
    while(copia!=0)
    {
        copia/=10;
        decimals+=1;
    }
    
    if(decimals==9)
    {
        nombre[1]+=1;
        nombre[0]=nombre[0]%max;
    }
}