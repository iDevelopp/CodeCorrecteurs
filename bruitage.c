#include "code_correcteur.h"

VECTEUR bruite(VECTEUR *v, unsigned int n, unsigned int b){
    // prends en paramètre un vecteur v de taille n et inverse le bit situé à l’indice b (0 <= b < n)
    // attention modifie directement le vecteur
    if(b>=0 && b<n){
        *v ^= (1<<b);
    }
    return *v;
}
