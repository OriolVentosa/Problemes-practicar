#include <stdio.h>
#include <math.h>

//CREAR TAULA MULTIPLICATIVA

int main(int arg, char* fitxer[])
{
    int taula[12][12];
    for(int i=0; i<12;i++)
    {
        for(int j=0;j<12;j++)
        {
            taula[i][j]=(i+1)*(j+1);
        }
    }
    
    FILE* f;
    
    if((f=fopen(fitxer[1],"w"))==NULL)
    {
        printf("Error \n");
        return 1;
    }

    for(int i=0; i<12; i++)
    {
        for(int j=0;j<12;j++)
        {
            fprintf(f, " %d ", taula[i][j]);
        }
        fprintf(f, "\n");
    }
    
    fclose(f);
    return 0;
}