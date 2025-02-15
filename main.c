// Implemente uma lista est�tica de inteiros em C. A lista deve ter um
// tamanho m�ximo predefinido. Implemente fun��es para adicionar,
// remover e buscar elementos.

#include <stdio.h>
#include <locale.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

int adicionar(int n) {
  if(tamanho < MAX_SIZE) {
    lista[tamanho++] = n;
    return 1; // 1 � para quando retornar com sucesso
  }
  return 0; // Falha (lista cheia)
}

int remover(int n) {
  for(int i = 0; i < tamanho; i++) {
    if(lista[i] == n) {
      for(int j = i; j < tamanho - 1; j++) {
        lista[j] = lista[j + 1];
      }
      tamanho--;
      return 1; // Sucesso
    }
  }
  return 0; // Falha (elemento n�o encontrado)
}

int buscar(int n) {
  for(int i = 0; i < tamanho; i++) {
    if(lista[i] == n) {
      return i; // Retorna a posi��o do elemento
    }
  }
  return -1; // Elemento n�o encontrado
}

void exibir_lista() {
  printf("Lista: ");
  for(int i = 0; i < tamanho; i++) {
    printf(" %d", lista[i]);
  }
  printf("\n");
}

int main() {
  setlocale(LC_ALL, "Portuguese");

  adicionar(5);
  adicionar(10);
  adicionar(15);

  printf("Ap�s a adi��es:\n");
  exibir_lista();

  remover(10);

  printf("Ap�s a remo��o do 10:\n");
  exibir_lista();

  int pos = buscar(15);
  if(pos != -1) {
    printf("Elemento 15 encontrado na posi��o %d\n", pos);
  } else {
    printf("Elemento 15 n�o encontrado\n");
  }

  return 0;
}