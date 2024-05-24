#include "code_correcteur.h"

int indice_colonne(SYNDROME s, MATRICE h, unsigned int k, unsigned int n){
    // retourne pour la matrice h de taille n-k, n l’indice se sa colonne égale au syndrome s de taille n-k passé en paramètre
    if(s==0||h==NULL) return -1;
    uint tmat=n-k;
    for(uint i=0; i<n; i++){
        uint est_egale = 1;
        for(uint j=0; j<tmat; j++){
            if( ((h[j]>>i)&1) != ((s>>j)&1)){
                //different
                est_egale = 0;
            }
        }
        if(est_egale){
            return i;
        }
    }
    return -1;
}

VECTEUR corrige(VECTEUR v, MATRICE h, unsigned int k, unsigned int n){
    //corrige le vecteur v de taille n selon le code correcteur de matrice de contrôle h de taille n-k, n
    
    SYNDROME s = syndrome(h,v,k,n); 
    //si syndrome indique une erreur, ses bits correspondent à une colone de H : il faut le detecter
    uint detecter_erreur = indice_colonne(s, h, k, n); 
    if (detecter_erreur == -1){
        return v; //pas d'erreur, rien à corriger
    }
    else{
        //on ne modifie pas directement v
        v^=(1<<detecter_erreur); 
    }
    return v;
}

VECTEUR decode(VECTEUR v, unsigned int k, unsigned int n){
    //décode le vecteur v. On considère que le vecteur v est un mot du code
    return v&((1<<(k-n))-1);
}
