void F_Limpar() {
  system("clear");
}

void F_MenuPrincipal() {
int MP_Opcao;
    printf("===== MENU PRINCIPAL =====");
    printf("\n[1] Vender produto");
    printf("\n[2] Listar produtos do caixa");
    printf("\n[3] Buscar Produto");
    printf("\n[9] Menu Gerencial");
    printf("\n[0] Sair");
    printf("\n\nEscolher: ");
        scanf(" %d", &MP_Opcao);
  switch (MP_Opcao) {
    case 1:
        F_Limpar();
        F_Vender();
    break;
    case 2:
        F_Limpar();
        F_Comprar();
    break;
    case 3:
        F_Limpar();
        ListarCaixa();
    break;
    case 9:
        F_Limpar();
        F_MenuGerencial();
    break;
  default:
    F_Sair(2);
    break;
  }

}

void F_MenuGerencial() {
int MG_Opcao;
    printf("===== MENU GERENCIAL =====");
    printf("\n[1] Cadastro de Produtos");
    printf("\n[2] Comprar Produto");
    printf("\n[3] Excluir Produto");
    printf("\n[4] Alterar Preço de Produto");
    printf("\n[0] Retornar ao Menu Principal");
    printf("\n\nEscolha sua Opção: ");
        scanf(" %d", &MG_Opcao);
  switch (MG_Opcao) {
    case 1:
        F_Limpar();
        F_CadProduto();
    break;
    case 2:
        F_Limpar();
        F_Comprar();
    break;
    case 3:
        F_Limpar();
        F_ExcluirProduto();
    break;
    case 4:
        F_Limpar();
        //F_AlterarPreço();
    break;
    case 5:
        F_Limpar();
        F_MenuPrincipal();
    break;
  default:
    F_Sair(2);
    break;
  }

}

void F_Sair(int opSair) {
    int opSair;
    printf("\nDeseja sair do programa? [1] Continuar [0] Sair");
     scanf("%d", &opSair);
    if (opSair == 1)
    return;
    else {
        if (opSair == 0)
        F_MenuPrincipal();
        else
        break;
    }
}

void F_CadProduto() {
  int Quant_Cadastros, op;
  Quant_Cadastros = F_CodVazio();
  int Cod_Temp = Cod_Base + Quant_Cadastros;

  do{
  F_Limpar();
  printf("===== CADASTRO DE PRODUTOS =====\n\n");
  Produto.codigo[Quant_Cadastros] = Cod_Temp;
  printf("\nDigite  o nome do produto: ");
  scanf(" %[^\n]s", Produto[Quant_Cadastros].descricao);
  printf("\nDigite a Quantidade Inicial do Produto: ");
  scanf(" %d", Produto[Quant_Cadastros].qtd_Disponivel);
  printf("\nDigite o Preço de Custo: ");
  scanf(" %f", Produto[Quant_Cadastros].preco_custo);
  printf("\nDigite o Preço de Venda: ");
  scanf(" %f, Produto[Quant_Cadastros].preco_venda);
  printf("\n\n%d %s cadastrado com sucesso!\n", Produto[Quant_Cadastros].codigo, Produto[Quant_Cadastros].descricao);
  Quant_Cadastros++;
  printf("\nDeseja cadastrar outro produto? [1] Novo Cadastro [0] Sair");
  scanf("%d", & op);
  }while(op != 0);
  F_MenuGerencial();
}
void F_CodVazio(){
    int cont, Cod_Vazio = 0;
    F_Limpar();
    for(cont = 0; cont <= Quant_Max; cont++)
    {
        if(Produto.codigo[cont] == NULL){
            Cod_Vazio = Produto.codigo[cont];
        }
        else
        printf("Voce nao pode adicionar mais produtos.\nEntre em contato com o Administrador.");
    }
return(Cod_Vazio);
}
void F_Listar() {
  printf("\nPRODUTOS REGISTRADOS NO ESTOQUE\n");
  int i;
  for (i = 0; i != produtosCadastrados; i++) {
    if (Produto[i].codigo != NULL )
      printf("Codigo do produto: %d\n\nNome: %s\nQuantidade: %d\nPreco de compra: %.2f\nPreco de venda: %.2f\n", Produto[i].codigo, Produto[i].descricao, Produto[i].qtd_Disponivel, Produto[i].preco_custo, Produto[i].preco_venda);
  }
  printf("\n");
  F_MenuPrincipal();
}
