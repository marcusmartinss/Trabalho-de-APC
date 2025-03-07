#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

// Cabecalho usado durante o cadastro do voo
void menu_cadastrarvoo() {
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Cadastrar voo                        |\n");
    printf("    |______________________________________|\n\n");
}

// Cabecalho usado durante o cadastro da reserva
void menu_cadastrarreserva() {
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Cadastrar reserva                    |\n");
    printf("    |______________________________________|\n\n");
}

// Cabecalho usado durante a consulta do voo
void menu_consultar_voo() {
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Consultar voo                        |\n");
    printf("    |______________________________________|\n\n");  
}

// Cabecalho usado durante a consulta de uma reserva
void menu_consultar_reserva() {
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Consultar reserva                    |\n");
    printf("    |______________________________________|\n\n");                      
}

// Cabecalho usado durante a consulta de uma reserva
void menu_consultar_passageiro() {
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Consultar passageiro                 |\n");
    printf("    |______________________________________|\n\n");                      
}

// Cabecalho para o cancelamento dos voos
void menu_cancelarvoo() {
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Cancelar voo                         |\n");
    printf("    |______________________________________|\n\n");
}

// Cabecalho para cancelamento de reservas
void menu_cancelarreserva() {
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Cancelar reserva                     |\n");
    printf("    |______________________________________|\n\n");;
}

// Cabecalho para exclusao de voos
void menu_excluirvoo() {
    printf("     ______________________________________\n");
    printf("    |            Galactic Birds            |\n");
    printf("    |    'Sua confianca sob nossas asas'   |\n");
    printf("    |--------------------------------------|\n");
    printf("    | Excluir voo                          |\n");
    printf("    |______________________________________|\n\n");
}

// Cabecalho do menu principal do programa.
char menu(int repeat)
{
    char num_menu;

    do
    {
        repeat = 0;
        fflush(stdin);  
        printf("\n");
        printf("     ______________________________________\n");
        printf("    |            Galactic Birds            |\n");
        printf("    |    'Sua confianca sob nossas asas'   |\n");
        printf("    |--------------------------------------|\n");
        printf("    | Menu de reservas espaciais           |\n");
        printf("    |--------------------------------------|\n");
        printf("    | 1) Cadastrar voo.                    |\n");
        printf("    | 2) Cadastrar reserva.                |\n");
        printf("    | 3) Consulta voo.                     |\n");
        printf("    | 4) Consultar reserva.                |\n");
        printf("    | 5) Consultar passageiro.             |\n");
        printf("    | 6) Cancelar voo.                     |\n");
        printf("    | 7) Cancelar reserva.                 |\n");
        printf("    | 8) Excluir voo.                      |\n");
        printf("    | 9) Sair do programa.                 |\n");
        printf("    |______________________________________|\n\n");


        printf("           Qual menu deseja acessar?\n");
        printf("                      "); scanf(" %c", &num_menu);

        if ( num_menu >= '1' && num_menu <= '9' )
        {
            system("cls || clear");

            if (num_menu == '9')
                printf("\n\n    Obrigado pela preferencia, volte sempre!\n");
        }
        else
        {
            repeat = 1;
            system("cls || clear");
            printf("\n             ERRO! Valor invalido!");
        }

    } while(repeat == 1);

 return num_menu;
}