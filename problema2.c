#include <stdio.h>

//CREAR TAULA ASCII

//int main(int arg, char *fitxer[])
int main()
{
//    FILE* f;
    
//     if((f=fopen(fitxer[1],"w"))==NULL)
//     {
//         printf("ERROR\n");
//         return 1;
//     }
    
    for(int i=0; i<128;i++)
    {
        printf("%d : %c  %2x  \n", i,i,i);

    }
    
//    fclose(f);
    
    return 0;
}