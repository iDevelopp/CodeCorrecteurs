#include "code_correcteur.h"

int pow2(uint n){
	return 1<<n;
}

VECTEUR vecteur_vide(uint n){
	VECTEUR vecteur = 0;
    return vecteur;
}

// big endian (MSB à gauche et LSB à droite)
/*void affiche_vecteur(VECTEUR v, uint n) {
    printf("(");
    for (uint i = n-1; i > 0; i--) {
        printf("%d", (v >> i) & 1);
        if (i > 1) printf(", ");
    }
    printf(", %d)", v & 1);
}*/

//little endian (LSB à gauche)
void affiche_vecteur(VECTEUR v, uint n) {
    printf("(");
    for (int i = 0; i < n; i++) {
        printf("%d", (v >> i) & 1);
        if (i < n - 1) printf(", ");
    }
    printf(")");
}


/*Ex1.5
On applique un masque de n=8 bits de poids faible à val pour ne pas avoir plus 
de n bits à 1 et dépasser un octet.
L'opérateur & force à conserver les bits du masque (poids faible)
Ex:
Si ça dépasse pas:
    00101101
   &01111111
   =00101101
Si ça dépasse: 
    11010101
   &01111111
   =01010101

Si on dépasse 255, il faut trouver un moyen plus intelligent pour conserver les bits
supérieur à un octet et l'indiquer.
*/
VECTEUR vecteur(uint n, uint val){
    if((val>255)||(n>8)) printf("Warning: Attention dépassement de capacité.");
	val &= (1 << n) - 1; //Toncage
	return (VECTEUR)val; //Casting
}

//Exo1.6 en appliquant un masque sur chaque bit de poids faible d'un variable type VECTEUR
int valeur(VECTEUR v, uint n){
	//donne la valeur décimale correspondant à la représentation binaire portée par v 
	int val=0;
	for(uint i=0; i<n; i++)
		val += ((v >> i) & 1) * pow2(i);
	return val;
}

