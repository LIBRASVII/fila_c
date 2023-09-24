#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct fila_circ {
  int n;
  int ini;
  char vet[N];
} Fila_circ;

Fila_circ *ini_fila();
void inserir(Fila_circ *, char);
char remover(Fila_circ *);
int fila_vazia(Fila_circ *);
void libera_fila(Fila_circ *);
void imprimir(Fila_circ *f);

int main() {
  Fila_circ *fila_c = ini_fila();

  inserir(fila_c, 'Y');
  inserir(fila_c, 'U');
  inserir(fila_c, 'K');

  imprimir(fila_c);

  printf("Elemento removido %c\n", remover(fila_c));

  imprimir(fila_c);

  libera_fila(fila_c);

  return 0;
}

void imprimir(Fila_circ *f) {
  if (fila_vazia(f)) {
    printf("\nFila vazia");
    exit(1);
  }
  printf("\nElementos ==> \n");
  int i, pos = f->ini;

  for (i = 0; i < f->n; i++) {
    printf("%c\n", f->vet[pos]);
    pos = (pos + 1) % N;
  }
  printf("\n");
}

void libera_fila(Fila_circ *f) { free(f); }

int fila_vazia(Fila_circ *f) { return (f->n == 0); }

char remover(Fila_circ *f) {
  char elem;
  if (fila_vazia(f)) {
    printf("\nFila vazia");
    exit(1);
  }
  elem = f->vet[f->n];
  f->ini = (f->ini + 1) % N;
  f->n--;
  return elem;
}

void inserir(Fila_circ *f, char elem) {
  int fim;
  if (f->n == N) {
    printf("\nFila cheia");
    exit(1);
  }
  fim = (f->n + f->ini) % N;
  f->vet[fim] = elem;
  f->n++;
}

Fila_circ *ini_fila(void) {
  Fila_circ *f = (Fila_circ *)malloc(sizeof(Fila_circ));
  f->n = 0;
  f->ini = 0;
  return f;
}
