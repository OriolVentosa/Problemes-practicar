#include <stdio.h>
#include <stdlib.h>

//UNIX a DOS i DOS a UNIX 

int detectar(FILE*);
void unix2dos(FILE*, FILE*);
void dos2unix(FILE*, FILE*);

int main(int arg, char *fitxers[])
{
    FILE* entrada;
    FILE* sortida;
    int tipus;
    if((entrada=fopen(fitxers[1],"r"))==NULL) return 1;
    if((sortida=fopen(fitxers[2],"w"))==NULL) return 2;
    tipus=detectar(entrada);
    if(tipus==0)
    {
        unix2dos(entrada,sortida);
        printf("De UNIX a DOS\n");
        return 0;        
    }
    
    printf("De DOS a UNIX\n");
    dos2unix(entrada,sortida);
    return 1;
    
    
}

int detectar(FILE* entrada)
{
    char element;
    while(fscanf(entrada, "%c" ,&element)!=EOF)
    {
        if(element == 14) 
        {
            fscanf(entrada, "%c" ,&element);
            if(element==10) 
            {
                fseek(entrada, 0, SEEK_SET);
                return 1;                
            }
            fseek(entrada, 0, SEEK_SET);
            return 0;
        }
    }
    
    fseek(entrada, 0, SEEK_SET);
    return 0;
}

void unix2dos(FILE* entrada, FILE* sortida)
{
    char element;
    while(fscanf(entrada, "%c" ,&element)!=EOF)
    {
        if(element == 10) fprintf(sortida, "%c%c",14,10);
            
        else fprintf(sortida, "%c", element);
    }
    
    fclose(entrada);
    fclose(sortida);
}

void dos2unix(FILE* entrada, FILE* sortida)
{
    char element;
    while(fscanf(entrada, "%c" ,&element)!=EOF)
    {
        if(element != 14) fprintf(sortida, "%c", element);
    }
    
    fclose(entrada);
    fclose(sortida);
}