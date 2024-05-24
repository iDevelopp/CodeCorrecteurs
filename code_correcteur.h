#ifndef CODE_CORRECTEUR_H
#define CODE_CORRECTEUR_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char VECTEUR;
typedef VECTEUR* MATRICE;
typedef unsigned char SYNDROME;

typedef unsigned char uchar;
typedef unsigned int uint;

int pow2(uint n);
VECTEUR vecteur_vide(uint n);
void affiche_vecteur(VECTEUR v, uint n);
VECTEUR vecteur(uint n, uint val);
int valeur(VECTEUR v, uint n);
VECTEUR* mots(uint k);
uint poids(VECTEUR v, int n);
VECTEUR diff(VECTEUR u, VECTEUR v, int n);
unsigned int hamming(VECTEUR u, VECTEUR v, int n);
void affiche_matrice(MATRICE mat, unsigned int l, unsigned int c, unsigned int order);
VECTEUR encode(MATRICE g, VECTEUR v, unsigned int k, unsigned int n);
unsigned int dist_min(VECTEUR* vects, unsigned int n, unsigned int nb_vect);
uint capacite_decodage(uint d);
SYNDROME syndrome(MATRICE h, VECTEUR c, unsigned int k, unsigned int n);
VECTEUR bruite(VECTEUR *v, unsigned int n, unsigned int b);
int indice_colonne(SYNDROME s, MATRICE h, unsigned int k, unsigned int n);
VECTEUR corrige(VECTEUR v, MATRICE h, unsigned int k, unsigned int n);
VECTEUR decode(VECTEUR v, unsigned int k, unsigned int n);

#endif
