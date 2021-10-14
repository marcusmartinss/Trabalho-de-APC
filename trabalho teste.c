#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void cadastrar_voo();
int consult_vooData();
void cadastrar_reserva();
void consultar_voo();
int valida_CPF(char* array);

struct Reserva {
    int id;
    int nome_voo;
    char cpf[14];
    char nome[255];
    char data_nascimento[12];
    int status_voo; // 1 representa ativo, 0 cancelado.
};

struct Voo {
    char data_voo[20]; // xx/xx/xxxx xx:xx
    int nome_voo;
    int qtd_passageiros;
    int status_voo; // 1 representa ativo, 0 cancelado.
    struct Reserva reservas[100];
    int nReservas;
};

int main(){
    printf("Reserva de viagens espaciais.\n\n");
    printf("Catálogo de ações:\n");
    printf("1: Cadastrar vôo\n");
    printf("2: Cadastrar Reserva\n");
    printf("3: Consultar vôo\n");
    printf("4) Consultar reserva\n");
    printf("5) Consultar passageiro\n");
    printf("6) Cancelar voo\n");
    printf("7) Cancelar reserva\n");
    printf("8) Excluir voo\n");
    printf("9) Sair do programa\n");
    int escolha;
    printf("Insira um número de ação para prosseguir.\n");
    scanf("%d",&escolha);
    switch (escolha){
        case 1:{
            cadastrar_voo();
            break;
        }
        case 2:{
            cadastrar_reserva();
            break;
        }
        case 3:{
            consultar_voo();
            break;
        }
         case 4:{
            printf("OPCAO INDISPONIVEL");
            break;
        }
        case 5:{
            printf("OPCAO INDISPONIVEL");
            break;
        }
        case 6:{
            printf("OPCAO INDISPONIVEL");
            break;
        case 7:{
            printf("OPCAO INDISPONIVEL");
            break;
        }
        case 8:{
            printf("OPCAO INDISPONIVEL");
            break;
        }
        case 9:{
            exit(0);
            break;
        }
    }
    return 0;
}

void consultar_voo(){
    printf("Insira o numero do voo a ser consultado.\n");
    char consult_voo[25];
    scanf("%s", consult_voo);
    int tam_Nvoo = strlen(consult_voo);
    if (tam_Nvoo != 8){
        printf("Numero de voo incorreto, utilize o formato JEB-XXXX, sendo XXXX números de 0 até 9.\n");
        exit(0);
    } else {
        if (consult_voo[0] == 'J' && consult_voo[1] == 'E' && consult_voo[2] == 'B' && consult_voo[3] == '-'){
            for (int i = 4; i < 8; i++){
                if (consult_voo[i] >= '0' && consult_voo[i] <= '9') {
                } else {
                    printf("Numero de voo incorreto, utilize JEB-XXXX, sendo XXXX números de 0 até 9.\n ");
                    exit(0);
                }
            }
            struct Voo v;
            if (access(consult_voo, W_OK) == 0){
                FILE * file= fopen(consult_voo, "r");
                if (file != NULL){
                    fread(&v, sizeof(struct Voo), 1, file);
                    printf("Data vôo: ");
                    for (int i = 0; i < strlen(v.data_voo); ++i) printf("%c",v.data_voo[i]);
                    printf("\n");
                    printf("Código(Id) do voo: %d\n",v.nome_voo);
                    printf("Número de passageiros MÁXIMO: %d\n",v.qtd_passageiros);
                    printf("Número de passageiros registrados: %d\n",v.nReservas);
                    printf("Status do voo: " [ (v.status_voo == 1)] ? "Ativo\n" : "Cancelado\n");
                    fclose(file);
                    sleep(1);
                    main();
                }
            } else {
                printf("O vôo não foi cadastrado.\n");
                exit(0);
            }
        }
    }
}

void cadastrar_reserva() {
    printf("Insira o número da reserva.\n");
    char consult_voo[25];
    scanf("%s", consult_voo);
    int tam_Nvoo = strlen(consult_voo);
    if (tam_Nvoo != 9){
        printf("Formato de reserva incorreto, utilize GB-XXXXXX, sendo XXXXXX números de 0 até 9.\n");
        exit(0);
    } else {//GB-XXXXXX
        if (consult_voo[0] == 'G' && consult_voo[1] == 'B' && consult_voo[2] == '-') {
            for (int i = 3; i < 9; i++) {
                if (consult_voo[i] >= '0' && consult_voo[i] <= '9'){
                } else {
                    printf("Numero de voo incorreto, utilize JEB-XXXX, sendo XXXX números de 0 até 9.\n ");
                    exit(0);
                }
            }
            struct Voo v;

            char xy[25];
            printf("Insira o numero do voo\n");
            scanf("%s",xy);
            if (access(xy, W_OK) == 0) { // file alconsult_vooy exists.
                FILE * file= fopen(xy, "r");
                if (file != NULL){
                    fread(&v, sizeof(struct Voo), 1, file);
                    struct Reserva* reserva=malloc(sizeof(struct Reserva));

                    char n[5];

                    n[0] = consult_voo[4];
                    n[1] = consult_voo[5];
                    n[2] = consult_voo[6];
                    n[3] = consult_voo[7];
                    n[4] = consult_voo[8];

                    reserva->id= atoi(n);

                    char n2[5];

                    n2[0] = xy[4];
                    n2[1] = xy[5];
                    n2[2] = xy[6];
                    n2[3] = xy[7];

                    reserva->nome_voo= atoi(n2);
                    char cpf[25];
                    printf("Insira o CPF a ser cadastrado na reserva.\n");
                    scanf("%s",cpf);
                    while (strlen(cpf) != 14) {
                        printf("Insira o CPF novamente, desta vez com formato correto!\n");
                        scanf("%s", cpf);
                    }
                    while (!valida_CPF(cpf)){
                        printf("Insira o CPF novamente, desta vez com formato correto!\n");
                        scanf("%s", cpf);
                    }
                    for (int i = 0; i <14; ++i) {
                        reserva->cpf[i]=cpf[i];
                    }
                    printf("CPF verificado.");
                    v.nReservas=v.nReservas + 1;
                    v.reservas[v.nReservas] = *reserva;
                    file = freopen(xy,"w",file);
                    fwrite(&v, sizeof(struct Voo), 1, file);
                    fclose(file);
                }
            } else {
                printf("O vôo não foi cadastrado anteriormente.");
                exit(0);
            }
        }
    }
}

void cadastrar_voo(){
    printf("Insira o número do vôo.\n");
    char consult_voo[25];
    scanf("%s",consult_voo);
    int tam_Nvoo = strlen(consult_voo);
    if (tam_Nvoo != 8){
        printf("Numero do voo incorreto, utilize JEB-XXXX, sendo XXXX números de 0 até 9.\n");
        exit(0);
    } else {
        if (consult_voo[0] == 'J' && consult_voo[1] == 'E' && consult_voo[2] == 'B' && consult_voo[3] == '-'){
            for (int i = 4; i < 8; i++){
                if (consult_voo[i] >= '0' && consult_voo[i] <= '9'){
                } else{
                    printf("Numero do voo incorreto, utilize JEB-XXXX sendo XXXX números de 0 até 9.\n ");
                    exit(0);
                }
            }
            if(access( consult_voo, W_OK) == 0){
                printf("O vôo já foi cadastrado.\n ");
                exit(0);
            } else {
                struct Voo *vject=malloc(sizeof(struct Voo));
                consult_vooData(vject);

                printf("Insira o número de passageiros...\n");
                int passengers;
                scanf("%d",&passengers);
                char n[4];
                n[0] = consult_voo[4];
                n[1] = consult_voo[5];
                n[2] = consult_voo[6];
                n[3] = consult_voo[7];
                vject->nome_voo=atoi(n);
                vject->qtd_passageiros=passengers;
                vject->status_voo=1;
                vject->nReservas = 0;
                FILE * fPtr = fopen(consult_voo, "w");
                printf("nome_voo: %d", atoi(n));
                fwrite(vject, sizeof(struct Voo), 1, fPtr);
                fclose(fPtr);
                printf("Vôo cadastrado.\n");
                main();
            }
        } else {
            printf("Formato incorreto, utilize JEB-XXXX, sendo XXXX números de 0 até 9.\n");
            exit(0);
        }

    }
}

int consult_vooData(struct Voo*x){

    //verificar o ano
    int ano;
    printf("Insira o ano da viagem.\n");
    scanf("%d", &ano);

    //verificar o mês
    printf("Insira o mês da viagem.\n");
    int mes;
    scanf("%d", &mes);
    while (mes > 12 || mes < 1){
        printf("Insira o mês da viagem corretamente.");
        scanf("%d", &mes);
    }

    // verificar o dia
    printf("Insira o dia da viagem.\n");
    int dia;
    scanf("%d", &dia);
    while (((ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) && mes == 2 && dia > 29) || dia > 31){
        printf("Insira o dia do voo.\n");
        scanf("%d\n", &dia);
    }

    //verificar o horario do voo
    int hora;
    printf("Insira a hora da viagem.\n");
    scanf("%d", &hora);
    while (hora > 24){
        printf("Insira a hora da viagem (Máximo 23, mínimo 1).\n");
        scanf("%d", &hora);
    }

    int minutos;
    printf("Insira o(s) minuto(s) da viagem.\n");
    scanf("%d", &minutos);
    while (minutos > 59){
        printf("Insira a hora da viagem.\n");
        scanf("%d", &minutos);
    }

    int milhares = ano/1000;
    int centenas = (int)((int)ano/100 - (int)10*(int)(ano/1000));
    int dezenas = (int)(ano/10) - ((int)(milhares*100) +(int)(centenas*10));
    int unidades = ano - ((milhares*1000) + (centenas*100) + dezenas*10);

    // assignando os caracteres de data a array
    x->data_voo[0] = '0'+(int) dia / 10;
    x->data_voo[1] = '0'+((int) dia - 10*((int) dia / 10));
    x->data_voo[2] = '/';
    x->data_voo[3] = '0' +(int) (mes > 9);
    x->data_voo[4] = '0' +(int) (mes > 9 ? mes-10 : mes);
    x->data_voo[5] = '/';
    x->data_voo[6] = '0' +milhares;
    x->data_voo[7]= '0' + centenas;
    x->data_voo[8] = '0' + (int)(dezenas);
    x->data_voo[9] = '0'+unidades;
    x->data_voo[10] = '-';
    //08/04/2002 18:35
    x->data_voo[11] = '0' + (int)( hora > 9 ? (int) hora/10 : 0);
    x->data_voo[12] = '0' + (int)( hora > 9 ? (int)(hora - (10*((int)hora/10))): hora);
    x->data_voo[13] = ':';
    x->data_voo[14] = '0' + (int)( minutos > 9 ? (int) minutos/10 : 0);
    x->data_voo[15] = '0' + (int)( minutos > 9 ? (int)(minutos - (10*((int)minutos/10))): minutos);
    printf("Data vôo: ");
    for (int i = 0; i < strlen(x->data_voo); ++i) printf("%c",x->data_voo[i]);
    printf("\n");
    return 1;
}

int valida_CPF(char* array){
    if (strlen(array) != 14) return 0;
    if (array[11] != '-') return 0;
    for (int i = 0; i < 3; ++i){
        if (array[i] < '0' || array[i] > '9'){
            return 0;
        }
    }
    // 000.000.000-20
    for (int i = 4; i < 7; ++i){
        if (array[i] < '0' || array[i] > '9'){
            return 0;
        }
    }
    for (int i = 8; i < 11; ++i){
        if (array[i] < '0' || array[i] > '9'){
            return 0;
        }
    }
    if (array[12] < '0' || array[12] >'9')return 0;
    if (array[13] < '0' || array[13] >'9')return 0;
    return 1;
}