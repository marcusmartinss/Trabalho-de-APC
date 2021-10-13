#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char menu_consultarvoo2()
{
    char opcao_consult;
    fflush(stdin);
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Consultar voo                        |\n");
    printf("    |--------------------------------------|\n");
    printf("    | 1) Consultar por nome                |\n");
    printf("    | 2) Consultar por CPF                 |\n");
    printf("    |______________________________________|\n\n");

    printf("               Digite sua opcao: \n");
    printf("                       "); opcao_consult = getchar();

 return opcao_consult;
}

int main()
{
    printf("%c\n", menu_consultarvoo2());

 return 0;
}