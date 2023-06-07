#include <iomanip>
#include <iostream>
using namespace std;

void faturamento(double total) {}

// função para o menu modo administrador
int menu_adm() {
  int op;
  cout << "\nO que deseja acessar? \n1 - Inventário \n2 - Reposição \n3 - "
          "Faturamento"
       << endl;
  cin >> op;

  return op;
}

// funcao para entrar no inventario
void inventario(int codigo[], string produto[], int quant_est[]) {
  for (int i = 0; i < 10; i++) {
    cout << codigo[i] << "\t|" << produto[i] << "\t\t" << quant_est[i] << endl;
  }
  cout << endl;
}

// funcao para adicionar itens na reposição
void reposicao(int codigos[], string produto[], int quant_est[]) {
  inventario(codigos, produto, quant_est);
  int codigo, qnt;

  cout << "Informe o codigo do produto: " << endl;
  cin >> codigo;
  codigo--;

  cout << "Informe quanto deseja adicionar: " << endl;
  cin >> qnt;

  if (qnt < 1) {
    cout << "Informe uma quantidade acima de 0" << endl;
  } else {
    quant_est[codigo] += qnt;
  }
}

// funcao para calcular o faturamento
double faturamento(double preco[], int quant_est[]) {
  double faturando = 0;
  for(int x=0; x <10; x++){
    faturando += preco[x]*quant_est[x];
  }

  return faturando;  
}

int main() {

  // Produtos disponíveis, preço de cada produto, quantidade, codigo...
  string produto[10] = {"Coca-Cola", "Guarana",    "Agua",   "Agua com gas",
                        "Doritos",   "Baconzitos", "Stiksy", "Ruffles",
                        "Kit Kat",   "Snickers"};
  double preco[10] = {5, 4, 3, 4, 7, 6, 6, 7, 4, 5};
  int quant_est[10] = {10, 10, 10, 10, 10, 10, 10, 10, 15, 15};
  int cod[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int i, j, pedido_cod[10], pedido_quant[10], sair, op, resp, k;
  double total = 0, pgto, senha, fattotal = 0;

  // CARDAPIO
  cout << endl
       << "NOME COMPLETO: LÍVIA MARIA CASSIMIRO DA SILVA - RA: 2840482213015";
    cout << endl
       << "NOME COMPLETO: AUDREY FRANCEZI - RA: 2840482313010";

  cout << endl
       << "____________________________CARDAPIO_____________________________"
       << endl
       << endl
       << endl
       << "CODIGO | PRECO | ESTOQUE | PRODUTO " << endl;

  j = 0;

  do {

    cout << fixed << setprecision(2);

    if (cod[j] < 10) {
      cout << " " << cod[j] << " | R$ " << preco[j] << " | " << quant_est[j]
           << " | " << produto[j] << endl;
    }

    else {
      cout << " " << cod[j] << " | R$ " << preco[j] << " | " << quant_est[j]
           << " | " << produto[j] << endl;
    }

    j++;

  } while (j < 10);

  // PEDIDO DE COMPRA

  i = 0;
  sair = 0;

  do {

    cout << endl
         << endl
         << ("Digite o codigo do produto que deseja comprar: ") << endl;
    cin >> pedido_cod[i];

    if (pedido_cod[i] > 0 and pedido_cod[i] < 11) { // Verificacao do codigo

      cout << ("Estoque disponivel = ") << quant_est[pedido_cod[i] - 1]
           << endl; // Mostra estoque disponível

      cout << ("Digite a quantidade: ") << endl;
      cin >> pedido_quant[i];

      if (pedido_quant[i] > quant_est[pedido_cod[i] - 1]) {
        cout << ("Estoque nao disponivel, digite novamente") << endl
             << endl; // Msg de erro, caso o pedido seja maior que o estoque
      } else {
        quant_est[pedido_cod[i] - 1] =
            (quant_est[pedido_cod[i] - 1] -
             pedido_quant[i]); // Vai diminuindo o estoque conforme o pedido
                               // está sendo realizado
        cout << endl << endl;
      }

      cout << ("Gostaria de incluir mais itens a compra? '1' - SIM, '2' - "
               "NAO?")
           << endl; // Confirmacao se deseja continuar a pedir
      cin >> sair;

      i++;
    } else {

      cout << ("Digite o codigo do produto corretamente")
           << endl; // Caso o codigo digitado esteja errado
    }

  } while (sair == 1);

  // RESUMO DO PEDIDO DE COMPRA

  cout << endl << "______________________PEDIDO______________________" << endl;

  cout << endl << "__________________NOVO INVENTÁRIO_________________" << endl;
  inventario(cod, produto, quant_est);
  
  j = 0;

  do {

    cout << fixed << setprecision(2);
    cout << endl
         << endl
         << " Codigo: " << cod[pedido_cod[j] - 1] << endl
         << " Produto: " << produto[pedido_cod[j] - 1] << endl
         << " Valor unid: R$ " << preco[pedido_cod[j] - 1] << endl
         << " Quantidade: " << pedido_quant[j] << endl
         << " Total Produto: R$ "
         << (pedido_quant[j] * preco[pedido_cod[j] - 1]) << endl
         << "__________________________________________________";

    total = (pedido_quant[j] * preco[pedido_cod[j] - 1]) + total;
    
    j++;

  } while (j < i);

  cout << endl << endl;

  // FORMA DE PGTO - senha oculta - confirmacao pgto

  cout << fixed << setprecision(2);
  cout << endl
       << endl
       << "Valor Total do Pedido: R$" << total << endl
       << " Qual sera a forma de pgto? '1' - Credito, '2' - Debito, '3' - "
          "Dinheiro? Ou '0' - CANCELAR: "
       << endl;
  cin >> pgto;

  if (pgto < 1) {
    cout << "PEDIDO CANCELADO!" << endl; // Se desistiu da compra
  }
  if (pgto > 0) {

    if (pgto == 1) {
      cout << "Opcao Credito selecionada - Por favor, digite sua senha: "
           << endl; // Se pgto for credito
      cin >> senha;
    }

    if (pgto == 2) {
      cout << "Opcao Debito selecionada - Por favor, digite sua senha: "
           << endl; // Se pgto for debito
      cin >> senha;
    }

    if (pgto == 3) {
      cout << "Insira o dinheiro no valor exato da COMPRA R$ " << total << endl
           << " e 1 para CONCLUIR" << endl
           << endl; // Se pgto for dinheiro
      cin >> senha;
    }
    cout << "Pagamento aprovado, por favor retire sua compra! - Agradecemos "
            "pela preferencia!"
         << endl; // Msg padrao quando concluir pedido
  }

  cout << endl << "Deseja algo mais?" << endl;
  cin >> resp;

  // Entrando no modo adm
    if (resp == 9876) {
    while(true){
      op = menu_adm();

      if (op == 1) {

        inventario(cod, produto, quant_est);

      } else {

        if (op == 2) {
          reposicao(cod, produto, quant_est);
        } else {

          if (op == 3) {
            fattotal = faturamento(preco, quant_est);
            
            cout << "O faturamento atual é: " << total
       << "\nO quanto a máquina ainda pode faturar é: " << fattotal << endl;
          } else {
            cout << "Informe uma operação válida!" << endl;
            return 0;
          }
        }
      }
    }
    } else {
      cout << "Tenha um ótimo dia!!!";
    }

  system("pause");
  return 0;
}
