//
// Created by igor on 27/03/18.
//
#include "Fisica.hpp"
#include <cmath>
#include <stdio.h>

void Atualiza(Lista2D *A, Key norma, int angulo){
    int i;
    if(!IsVazia(A)){
        for(i = 0; i <= A->i; i++){
            if(A->vetores[i].norma > 0){
                A->vetores[i].norma--;
            }
            if(A->vetores[i].norma < 0){
                A->vetores[i].norma++;
            }
            A->vetores[i].x = -A->vetores[i].norma*sin((A->vetores[i].angulo*3.141592/180));
            A->vetores[i].y = A->vetores[i].norma*cos((A->vetores[i].angulo*3.141592/180));
            if(A->vetores[i].norma == 0)
            {
                RemoveVetorByIndex(i,A);
                i--;
            }
        }
    }
    AddVetor(norma, angulo, A);
    CalculaResultante(A);
}
