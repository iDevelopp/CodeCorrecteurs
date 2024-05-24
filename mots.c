#include "code_correcteur.h"


VECTEUR* mots(uint k){
	//génère sous forme de tableau de vecteurs tous les 2**k vecteurs binaires possibles de taille k
	if (k<=0) return NULL;
	int puis = pow2(k);
	VECTEUR* v = (VECTEUR*)calloc(puis, sizeof(VECTEUR));
	for (uint i=0; i<puis; i++){
		v[i] = vecteur(k,i); //v[i]= i plus rapide mais pas sécurisé
	}
	return v;
}

uint poids(VECTEUR v, int n){
	uint p=0;
	for(uint i=0; i<n;i++)
		p+=(v>>i)&1;
	return p;
}

VECTEUR diff(VECTEUR u, VECTEUR v, int n){
    //retourne le vecteur binaire différence entre les vecteurs binaires u et v de taille n passés en paramètres
    return u^v;
}

unsigned int hamming(VECTEUR u, VECTEUR v, int n){
    //calcule la distance de Hamming entre les vecteurs binaires u et v
    if (n==0) return 0;
    return poids(diff(u, v, n),n);
}