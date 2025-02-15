// Implemente uma lista estática de inteiros em C. A lista deve ter um
// tamanho máximo predefinido. Implemente funções para adicionar,
// remover e buscar elementos.

#include <stdio.h>
#include <locale.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

int adicionar(int n) {
  if(tamanho < MAX_SIZE) {
    lista[tamanho++] = n;
    return 1; // 1 é para quando retornar com sucesso
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
  return 0; // Falha (elemento não encontrado)
}

int buscar(int n) {
  for(int i = 0; i < tamanho; i++) {
    if(lista[i] == n) {
      return i; // Retorna a posição do elemento
    }
  }
  return -1; // Elemento não encontrado
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

  printf("Após a adições:\n");
  exibir_lista();

  remover(10);

  printf("Após a remoção do 10:\n");
  exibir_lista();

  int pos = buscar(15);
  if(pos != -1) {
    printf("Elemento 15 encontrado na posição %d\n", pos);
  } else {
    printf("Elemento 15 não encontrado\n");
  }

  return 0;
}