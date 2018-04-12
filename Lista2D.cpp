//
// Created by igor on 26/03/18.
//
#include "Lista2D.hpp"
#include <cmath>
#include <stdio.h>

#define GetNorma(x,y) sqrt((x*x)+(y*y))


void Inicializar(Lista2D *A){
    A->i = -1;
}

int IsCheia(Lista2D *A){
    if(A->i == MAX-1)
        return TRUE;
    return FALSE;
}

int IsVazia(Lista2D *A){
    if(A->i == -1)
        return TRUE;
    return FALSE;
}

int AddVetor(Key norma, int angle, Lista2D *A){
    if(!IsCheia(A)){
        A->i++;
        A->vetores[A->i].norma = norma;
        A->vetores[A->i].angulo = angle;
        A->vetores[A->i].x = -norma*sin((angle*3.141592/180));
        A->vetores[A->i].y = norma*cos((angle*3.141592/180));

        return SUCESSO;
    }
    return ERRO;
}

int RemoveVetorByIndex(Indice i, Lista2D *A){
    if(!IsVazia(A) && i <= A->i){
        while(i < A->i){
            A->vetores[i] = A->vetores[i+1];
            i++;
        }
        A->i--;
        return SUCESSO;
    }
    return ERRO;
}

void CalculaResultante(Lista2D *A){
    int i;

    A->resultante.x = 0;
    A->resultante.y = 0;
    A->resultante.angulo = 0;
    A->resultante.norma = 0;

    if(!IsVazia(A)){
        for(i = 0; i <= A->i; i++)
        {
            A->resultante.x += A->vetores[i].x;
            A->resultante.y += A->vetores[i].y;
        }
        A->resultante.x = A->resultante.x/(A->i+1);
        A->resultante.y = A->resultante.y/(A->i+1);
        A->resultante.norma = (Key)GetNorma(A->resultante.x,A->resultante.y);
    }
}