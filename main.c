#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "processo.h"

//10 quantidade de processos dentro do arquivo "TJDFT_amostra"
//1048576 quantidade de processos dentro do arquivo "TJDFT_filtrado"


int main() {
    // Variáveis 
    char linha[1024];
    char cabecalho[1000];
    int i = 0;
    
    // Abertura do arquivo CSV 
    FILE *arquivo;
    arquivo = fopen("TJDFT_amostra.csv", "r");
    
    // Teste de falha de abertura
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }
    
    // Conta o tanto de processos
    int totalProcessos = contarProcessos(arquivo);
    printf("O arquivo possui %d processos.\n", totalProcessos);

    // Cria vetor para guardar os processos
    Processo processos[totalProcessos];

    // Lê e ignora o cabeçalho
    fgets(cabecalho, sizeof(cabecalho), arquivo);
    

    // Lê a linha inteira do processo e salva o processo em um vetor
    while (fgets(linha, sizeof(linha), arquivo) && i < totalProcessos) {
        linha[strcspn(linha, "\n")] = 0;  // remove o \n 
        processos[i] = lerProcesso(linha); // salva o processo em um vetor
        i++;
    }

    int total_processos = i; // i é o número de processos lidos
    int id_antigo = processoMaisAntigo(processos, total_processos);
    printf("O processo com dt_recebimento mais antigo tem id_processo = %d\n", id_antigo);

    int id = 323961076;
    int ultimoOrgao = buscarUltimoOj(processos, totalProcessos, id);
    printf("Ultimo orgao julgador do id %d: %d\n", id, ultimoOrgao);

    contarCausas(processos, total_processos);

    int diasEntre = DiasEntreDatas(processos, totalProcessos, id);
    printf("Dias entre datas do processo: %d", diasEntre + 6);
    
    return 0;
}