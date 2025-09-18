#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "processo.h"
 
#define max_processos 1000

//10485760 

int main() {
    char linha[1024];
    char cabecalho[1000];
    Processo processos[max_processos];
    int i = 0;
    
    FILE *arquivo;
    arquivo = fopen("TJDFT_amostra.csv", "r");
    
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(0);
    }

    // Lê e ignora o cabeçalho
    fgets(cabecalho, sizeof(cabecalho), arquivo);

    // Lê a linha inteira do processo e salva o processo em um vetor
    while (fgets(linha, sizeof(linha), arquivo) && i < max_processos) {
        linha[strcspn(linha, "\n")] = 0;  // remove o \n 
        processos[i] = lerProcesso(linha); // salva o processo em um vetor
        i++;
    }

    // Teste de funcionamento, pode apagar a vontade
    printf("primeiro id: %d\n", processos[0].id_processo);
    printf("primeiro numero sigiloso: %s\n", processos[0].numero_sigilo);
    printf("segundo id: %d\n", processos[1].id_processo);
    printf("segundo numero sigiloso: %s\n", processos[1].numero_sigilo);

    

    return 0;
}