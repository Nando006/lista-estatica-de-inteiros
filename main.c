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
    return 1;
  }
  return 0;
}

int remover(int n) {
  for(int i = 0; i < tamanho; i++) {
    if(lista[i] == n) {
      for(int j = i; j < tamanho - 1; j++) {
        lista[j] = lista[j + 1];
      }
      tamanho--;
      return 1;
    }
  }
  return 0;
}

int buscar(int n) {
  for(int i = 0; i < tamanho; i++) {
    if(lista[i] == n) {
      return lista[i];
    }
  }
  return -1;
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
  adicionar(20);
  adicionar(30);

  exibir_lista();

  printf("Buscar número = %d \n", buscar(10));

  remover(10);

  exibir_lista();

}