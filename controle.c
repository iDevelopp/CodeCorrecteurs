#include "code_correcteur.h"

SYNDROME syndrome(MATRICE h, VECTEUR c, unsigned int k, unsigned int n){
	//retourne le syndrome du vecteur c par la matrice h
    SYNDROME s = 0;
    for (unsigned int i=0; i<n-k; i++){
        for(unsigned int j=0; j<n; j++){
            s ^= ((((c >> j)&1) * ((h[i]>>j)&1))<<i); //c[j] & h[j][i]
        }
    }
    return s;
}