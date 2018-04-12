//
// Created by igor on 26/03/18.
//

#ifndef TESTE_VETOR_HPP
#define TESTE_VETOR_HPP

#define ERRO -1
#define SUCESSO 1
#define TRUE 1
#define FALSE 0
#define VAZIA -999
#define MAX 101

typedef int Indice;

typedef float Key;

typedef struct vetor2d{
    int x;
    int y;
    int angulo;
    Key norma;
} Vetor2D;

typedef struct lista2d{
    Vetor2D vetores[MAX];
    Vetor2D resultante;
    Indice i;
} Lista2D;

void Inicializar(Lista2D *A);

int IsCheia(Lista2D *A);

int IsVazia(Lista2D *A);

int AddVetor(Key norma, int angle, Lista2D *A);

int RemoveVetorByIndex(Indice i, Lista2D *A);

void CalculaResultante(Lista2D *A);


#endif //TESTE_VETOR_HPP
