#include "code_correcteur.h"

void affiche_matrice(MATRICE mat, unsigned int l, unsigned int c, unsigned int order){
	for(uint i=0; i<l; i++){
		printf("[");
		for(uint j=0; j<c; j++){
			if (order){
				printf("%u", (mat[j]>>i)&1);//en ligne
			}else{
				printf("%u", (mat[i]>>j)&1);//en colone
			}
		}
		printf("]\n");
	}
}

VECTEUR encode(MATRICE g, VECTEUR v, unsigned int k, unsigned int n) {
	// produit l’ensemble des vecteurs de taille n obtenus en encodant tous les vecteurs v de dimension k
    if (k <= 0 || n <= 0) return 0; 
    VECTEUR c = 0;
    for (unsigned int i = 0; i < k; i++) {
        for (unsigned int j = 0; j < n; j++) {
            VECTEUR bit_v = (v >> i) & 1;
            VECTEUR bit_g = (g[i] >> j) & 1;
            c ^= (bit_v * bit_g << j);
        }
    }
    return c;
}

unsigned int dist_min(VECTEUR* vects, unsigned int n, unsigned int nb_vect){
	//retourne la distance de Hamming minimale entre deux vecteurs distincts de l’ensemble de nb_vect vecteurs passé en paramètres
    if(nb_vect<2) return 0;
    unsigned int min = n;
    for(unsigned int i=0; i<nb_vect-1; i++){
        for(unsigned int j=i+1; j<nb_vect; j++){
            unsigned int dist = hamming(vects[i], vects[j], n);
            if (dist<min){
                min = dist;
            }
        }
    }
    return min;
}

uint capacite_decodage(uint d){
	return (d-1)/2;
}
