#include <stdio.h>
#include <stdlib.h> 
#include "processo.h"
 
#define max_processos 1000

//10485760 

int main() {
    
    char linha[1024];
    
    Processo processos[max_processos];
    
   int i;

   // Salva os processos em um vetor
   for(i = 0; i < 26; i++) {
    processos[i] = lerProcesso("TJDFT_amostra.csv"); 
   }

    return 0;
}