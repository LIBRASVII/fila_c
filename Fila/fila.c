#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct fila {
  int n;
  int ini;
  char vet[N];
} Fila;

Fila *ini_fila(void);
void inserir_fila(Fila *, char);
char remover_fila(Fila *);
int fila_vazia(Fila *);
void libera_fila(Fila *);
void imprimir_fila(Fila *);

int main() {
  Fila *fila = ini_fila();

  inserir_fila(fila, 'A');
  inserir_fila(fila, 'B');
  inserir_fila(fila, 'E');

  imprimir_fila(fila);

  printf("Item removido %c\n", remover_fila(fila));

  imprimir_fila(fila);

  inserir_fila(fila, 'K');

  imprimir_fila(fila);

  return 0;
}

Fila *ini_fila(void) {
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->n = 0;
  f->ini = 0;
  return f;
}

void inserir_fila(Fila *f, char elem) {
  if (f->n == N) {
    printf("\nFila cheia");
    exit(1);
  }
  int fim = f->n + f->ini;
  f->vet[fim] = elem;
  f->n++;
}

char remover_fila(Fila *f) {
  char elem;
  if (fila_vazia(f)) {
    printf("\nFila vazia");
    exit(1);
  }
  elem = f->vet[f->ini];
  f->ini++;
  f->n--;
  return elem;
}

int fila_vazia(Fila *f) { return (f->n == 0); }

void libera_fila(Fila *f) { free(f); }

void imprimir_fila(Fila *f) {
  if (fila_vazia(f)) {
    printf("\nFila vazia");
    exit(1);
  }
  printf("\nElementos ==> ");
  int i, pos = f->ini;

  for (i = 0; i < f->n; i++) {
    printf("\n%c", f->vet[pos]);
    pos++;
    pos = pos % N;
  }
  printf("\n");
}
