#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

struct Triangulo {
  int lado1;
  int lado2;
  int lado3;
};

int calcPerimetro(int a, int b, int c) {
  int result;
  result = a + b + c;
  return(result);
};

int calcArea(int a, int b) {
  int result;
  result = (a + b)/2;
  return(result);
};

int calcHipotenusa(int a, int b) {
    int result, parcial;
    parcial = pow(a,2) + pow(b,2);
    result = sqrt(parcial);
    return(result);
}

struct tNo {
  int resultados;
  tNo* proximo;
};

tNo* criaNo(int triangulo) {
  tNo* no = new tNo;

  no -> resultados = triangulo;
  no -> proximo = NULL;
  return no;
}

struct tLista {
  tNo* primeiro;
  tNo* ultimo;
  tNo* marcador;
  int tamanho;
};

void inicializaLista(tLista* pLista) {
  pLista -> primeiro = NULL;
  pLista -> ultimo = NULL;
  pLista -> marcador = NULL;
  pLista -> tamanho = 0;
}

int obterTamanho(tLista* pLista) {
  return pLista -> tamanho;
}

bool listaVazia (tLista* pLista) {
  return (pLista -> tamanho == 0);
}

bool finalLista (tLista* pLista) {
  return (pLista -> marcador == NULL);
}

void incluirNaLista (tLista* pLista, int info) {
  tNo* no;
  no = criaNo(info);

  if (listaVazia(pLista)) {
    pLista -> primeiro = no;
  }
  else {
    pLista -> ultimo -> proximo = no;
  }

  pLista -> ultimo = no;
  pLista -> marcador = no;
  pLista -> tamanho++;
}

void varrerLista (tLista* pLista) {
  listaVazia(pLista);

  ofstream dbTriangulo;
  dbTriangulo.open ("dbTriangulo.txt");
  int tamanho = obterTamanho(pLista);
  tNo* atual = pLista->primeiro;

  for (int  i; i < tamanho; i++) {
    dbTriangulo << atual->resultados << endl;
    if(atual->proximo != NULL){
      atual = atual ->proximo;
    }

  }

  dbTriangulo.close();
}


void lerArquivo() {
  ifstream dbTriangulo("dbTriangulo.txt");
  string line;

  if (dbTriangulo.is_open()) {
    while (! dbTriangulo.eof()) {
      getline(dbTriangulo, line);
      cout << line << endl;
    }
  }
  dbTriangulo.close();
}