#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "processo.h"

Processo lerProcesso(char TJDFT_amostra, Processo **vetor, int *n){
    FILE *arquivo;
    arquivo = fopen(TJDFT_amostra, "r");
    
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }

    char linha[1024];
    int tamanho = 100;
    // *vetor = malloc(tamanho *sizeof(Processo));
    // *n = 0;
    
    
    

    char titulos[1000];
    fscanf(arquivo, "%[^\n]", titulos);

    fscanf(arquivo, "%[^\n]", linha);


    Processo p;
    fscanf(linha, "%d;%49[^;];%4[^;];%99[^;];%4[^;];%9[^;];%d;%d;%49[^;];%10[^;];%49[^;];"
                  "%d;%d;%d;%d;%d;%d;%99[^;];%10[^;];%d;%d;%d;%d;%d;%d;%d;%d",
           &p.id_processo, p.numero_sigiloso, p.sigla_grau, p.procedimento, p.ramo_justica, p.sigla_tribunal, &p.id_tribunal, &p.recurso, p.id_ultimo_oj, 
           p.data_recebimento, p.id_ultima_classe, &p.flag_violencia_domestica, &p.flag_feminicidio, &p.flag_ambiental, &p.flag_quilombolas, &p.flag_indigena, 
           &p.flag_infancia, p.decisao, p.data_resolvimenento, &p.cnm1, &p.primeirasentm1, &p.baixm1, &p.decm1, &p.mpum1, &p.julgadom1, &p.desm1, &p.susm1);


    fclose(arquivo);
    
    return p;
}
