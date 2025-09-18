#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "processo.h"

Processo lerProcesso(char *linha) {
    Processo p;

    sscanf(linha, "%d;%49[^;];%3[^;];%99[^;];%49[^;];%9[^;];%d;%d;%49[^;];%10[^;];%d;%d;%d;%d;%d;%d;%d;%99[^;];%10[^;];%d;%d;%d;%d;%d;%d;%d;%d",
           &p.id_processo, p.numero_sigilo, p.sigla_grau, p.procedimento, p.ramo_justica, p.sigla_tribunal,
           &p.id_tribunal, &p.recurso, p.id_ultimo_oj, p.dt_recebimento, &p.id_ultima_classe,
           &p.flag_violencia_domestica, &p.flag_feminicidio, &p.flag_ambiental, &p.flag_quilombolas,
           &p.flag_indigenas, &p.flag_infancia, p.decisao, p.dt_resolvido,
           &p.cnm1, &p.primeirasentm1, &p.baixm1, &p.decm1, &p.mpum1, &p.julgadom1, &p.desm1, &p.susm1);

    return p;
}

