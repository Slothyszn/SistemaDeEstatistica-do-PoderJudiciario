#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "processo.h"

// Salva as linhas dos processos na struct
Processo lerProcesso(char *linha) {
    Processo p;

    sscanf(linha, "%d;%49[^;];%3[^;];%99[^;];%49[^;];%9[^;];%d;%d;%d;%10[^;];%d;%d;%d;%d;%d;%d;%d;%99[^;];%10[^;];%d;%d;%d;%d;%d;%d;%d;%d",
           &p.id_processo, p.numero_sigilo, p.sigla_grau, p.procedimento, p.ramo_justica, p.sigla_tribunal,
           &p.id_tribunal, &p.recurso, &p.id_ultimo_oj, p.dt_recebimento, &p.id_ultima_classe,
           &p.flag_violencia_domestica, &p.flag_feminicidio, &p.flag_ambiental, &p.flag_quilombolas,
           &p.flag_indigenas, &p.flag_infancia, p.decisao, p.dt_resolvido,
           &p.cnm1, &p.primeirasentm1, &p.baixm1, &p.decm1, &p.mpum1, &p.julgadom1, &p.desm1, &p.susm1);

    return p;
}

//o número de processos presentes na base de dados
int contarProcessos(FILE *arquivo) {
    char linha[1024];
    int contador = 0;

    // Pula o cabeçalho
    fgets(linha, sizeof(linha), arquivo);

    // Conta as linhas seguintes
    while (fgets(linha, sizeof(linha), arquivo)) {
        contador++;
    }

    // Volta o ponteiro do arquivo para o início
    rewind(arquivo);

    return contador;
}

//busca o id_ultimo_oj a partir de id_processo.
int buscarUltimoOj(Processo *processos,int totalProcessos, int id_processo) {
    int i = 0;
    for (i = 0; i < totalProcessos; i++) {
        if (processos[i].id_processo == id_processo) {
            return processos[i].id_ultimo_oj;
        }
    }

    return -1;
}

//o id_processo do processo com dt_recebimento mais antigo;
int processoMaisAntigo(Processo processos[], int n) {
    if (n == 0) return -1; // caso não haja processos

    int idx = 0; // assume o primeiro como mais antigo

    for (int i = 1; i < n; i++) {
        if (strcmp(processos[i].dt_recebimento, processos[idx].dt_recebimento) < 0) {
            idx = i;
        }
    }

    return processos[idx].id_processo;
}

//conta quantos processos estão relacionados a cada causa
void contarCausas(Processo processos[], int n){
 int vd = 0, fem = 0, amb = 0, quil = 0, ind = 0, inf = 0;

 for (int i = 0; i < n; i++)
 {
   if (processos[i].flag_violencia_domestica) vd++;
   else if (processos[i].flag_feminicidio) fem++;
   else if (processos[i].flag_ambiental) amb++;
   else if (processos[i].flag_quilombolas) quil++;
   else if (processos[i].flag_indigenas) ind++;
   else if (processos[i].flag_infancia) inf++;
 }
   printf("violencia domestica: %d\n", vd);
   printf("feminicidio: %d\n", fem);
   printf("ambiental: %d\n", amb);
   printf("quilombolas: %d\n", quil);
   printf("indigenas: %d\n", ind);
   printf("infantil: %d\n", inf);
 }

//o número de dias entre dt_recebimento e dt_resolvido
// int DiasEntreDatas(Processo *processos, int totalProcessos,int id_processo){
//     int dt_recebimento, dt_resolvido, i;
//     for (i = 0; i < totalProcessos; i++) {
//         if (processos[i].id_processo == id_processo) {
            
//         }
//     }

//     return -1;
// }