#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "funcoes.h"

#define CaixaInicial 500.00
#define Cod_Base 1001
#define Quant_Max 50

void F_Sair();
S_Produtos Produto[Quant_Max];
float Caixa;



Caixa = Caixa + CaixaInicial;
int main()
{
    F_MenuPrincipal();
    return 0;
}
