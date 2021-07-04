#include <iostream>
#include "tTriangulo.cpp"

using namespace std;

int main() {
  int result, hip, numTriangulo;
  char operacao;
  string decisao;
  struct Triangulo t;

  cout << "Deseja gravar ou ler no banco de dados? " << endl;
  cin >> decisao;

  if (decisao == "gravar") {

    cout << "Quantos triangulos deseja salvar? " << endl;
    cin >> numTriangulo;

    for (numTriangulo; numTriangulo < 0; numTriangulo--) {       
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
      }
      
      else if (operacao == 'a') {
        cout << "Ótimo, agora vamos para os lados do triângulo" << endl;
        cout << "Digite o valor do lado 1: "<< endl;
        cin >> t.lado1;
        cout << "Digite o valor do lado 2: " << endl;
        cin >> t.lado2;

        result = calcArea(t.lado1, t.lado2);
        cout << "O resultado da operação é " << result << endl;
      }

      else if (operacao == 'h') {
        cout << "Ótimo, agora vamos para os lados do triângulo" << endl;
        cout << "Digite o valor do lado 1: "<< endl;
        cin >> t.lado1;
        cout << "Digite o valor do lado 2: " << endl;
        cin >> t.lado2;

        hip = calcHipotenusa(t.lado1, t.lado2);
        cout << "A hipotenusa é igual a " << hip << endl;
      }

      cout << "Deseja continuar? (s ou n) " << endl;
      cin >> decisao;

    }
  }
}