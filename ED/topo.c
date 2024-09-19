#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct _fila {
    int inicio;
    int itens[MAX];
    int fim;
} FILA;

void inicializaFila(FILA* f) {
    f->inicio = 0;
    f->fim = 0;
}

int filaVazia(FILA* f) {
    return f->inicio == f->fim;
}

void insereFila(FILA* f, int valor) {
    if (f->fim < MAX) {
        f->itens[f->fim++] = valor;
    }
}

int removeFila(FILA* f) {
    if (!filaVazia(f)) {
        return f->itens[f->inicio++];
    }
    return -1; 
}

void ordemTopologica(int n, int adj[MAX][MAX]) {
    int grauEnt[MAX] = {0};
    int ordem[MAX];
    FILA fila;
    inicializaFila(&fila);

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (adj[i][j] == 1) {
                grauEnt[j]++;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (grauEnt[i] == 0) {
            insereFila(&fila, i);
        }
    }

    int index = 0;

    while (!filaVazia(&fila)) {
        int v = removeFila(&fila);
        ordem[index++] = v;

        for (int u = 0; u < n; u++) {
            if (adj[v][u] == 1) {
                grauEnt[u]--;
                if (grauEnt[u] == 0) {
                    insereFila(&fila, u);
                }
            }
        }
    }

    for (int i = 0; i < index; i++) {
        printf("%d ", ordem[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int adj[MAX][MAX] = {0};

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    ordemTopologica(n+1, adj);
    
    return 0;
}
