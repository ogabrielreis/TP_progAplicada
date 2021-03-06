#include <iostream>
#include "functions.cpp"

using namespace std;

int main() {
  int result, hip, numTriangulo;
  char operacao, cont;
  string decisao;
  bool continuar = true;
  struct Triangulo t;

  tLista* triangulos = new tLista;

  inicializaLista(triangulos);

  while (continuar == true) {

    cout << "Deseja gravar ou ler no banco de dados? " << endl;
    cin >> decisao;

    if (decisao == "gravar") {

      cout << "Quantos triangulos deseja salvar? " << endl;
      cin >> numTriangulo;

      for (numTriangulo; numTriangulo > 0; numTriangulo--) {    

        cout << "digite qual operação deseja efetuar (p = perimetro, a = area ou h = hipotenusa)" << endl;
        cin >> operacao;

        if (operacao == 'p') {
          cout << "Ótimo, agora vamos para os lados do triângulo" << endl;
          cout << "Digite o valor do lado 1: "<< endl;
          cin >> t.lado1;
          cout << "Digite o valor do lado 2: " << endl;
          cin >> t.lado2;
          cout << "Digite o valor do lado 3: " << endl;
          cin >> t.lado3;

          result = calcPerimetro(t.lado1, t.lado2, t.lado3);
          cout << "O resultado da operação é " << result << endl;

          incluirNaLista(triangulos, result);
        }
        
        else if (operacao == 'a') {
          cout << "Ótimo, agora vamos para os lados do triângulo" << endl;
          cout << "Digite o valor do lado 1: "<< endl;
          cin >> t.lado1;
          cout << "Digite o valor do lado 2: " << endl;
          cin >> t.lado2;

          result = calcArea(t.lado1, t.lado2);
          cout << "O resultado da operação é " << result << endl;

          incluirNaLista(triangulos, result);
        }

        else if (operacao == 'h') {
          cout << "Ótimo, agora vamos para os lados do triângulo" << endl;
          cout << "Digite o valor do lado 1: "<< endl;
          cin >> t.lado1;
          cout << "Digite o valor do lado 2: " << endl;
          cin >> t.lado2;

          hip = calcHipotenusa(t.lado1, t.lado2);
          cout << "A hipotenusa é igual a " << hip << endl;

          incluirNaLista(triangulos, result);
        }
      }
      varrerLista(triangulos);
    }

    else if (decisao == "ler") {
      lerArquivo();
    }

    cout << "Deseja continuar? (s ou n)" << endl;
    cin >> cont;

    if (cont == 's') {
      continuar = true;
    }
    else {
      continuar = false;
    }
  }
}