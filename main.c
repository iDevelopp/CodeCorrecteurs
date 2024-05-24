#include "code_correcteur.h"

int main(void){
	printf("ATTENTION, affiche par défaut Little endian\n");
	uint k = 4;
	uint n = 7;

	MATRICE G = (MATRICE)calloc(k,sizeof(VECTEUR));
	/*
	  Pour recopier la matrice, soit je mets leurs représentation
	  en utilisant la fonction valeur et en passant le vecteur de bits en paramètre
	  soit en les passant en binaire ou pour G[0] 67 directement. 
	
	Erreur que j'ai comise : mélange en little endian et big endian ! 
	G[0] = 0b1000101;
	G[1] = 0b1000111;
	G[2] = 0b1001100;
	G[3] = 0b1001011;

	H[0] = 0b1110100;
	H[1] = 0b0111010;
	H[2] = 0b1101001;
	Bon, les syndromes avaient des bits à 1, donc beaucoups d'erreurs sans bruitage ce 
	qui m'a indiqué m'être trompé à ce niveau là.
	*/
	G[0] = 0b1010001;
	G[1] = 0b1110010;
	G[2] = 0b0110100;
	G[3] = 0b1101000;
    //printf("Mat g:\n");
    //affiche_matrice(G, k, n, 0);

	uint puis = pow2(k);
	VECTEUR* mots_k = mots(k);
	VECTEUR* mots_code = (VECTEUR*)calloc(puis, sizeof(VECTEUR));

	printf("Mots du code généré par la matrice G :\n");
	for (unsigned int i = 0; i < puis; i++) {
        mots_code[i] = encode(G, mots_k[i], k, n);
        affiche_vecteur(mots_code[i], n);
        printf("\n");
    }

    uint distance_min = dist_min(mots_code, n, puis);
    uint e = capacite_decodage(distance_min);
    printf("distance minimum : %u, et capacité de décodage: %u\n", distance_min, e);

    //VECTEUR v = 0b110011;
    //uint n2 = 6;
    //printf("%u", v);
    //affiche_vecteur(v, n2);

    uint tmat = n-k;
    MATRICE H = (MATRICE)calloc(tmat,sizeof(VECTEUR));
    H[0] = 0b0010111;
	H[1] = 0b0101110;
	H[2] = 0b1001011;
    //printf("Mat H:\n");
    //affiche_matrice(H, tmat, n, 0);

	printf("L'ensemble des syndromes pr les vecteurs de dimensions 7:\n");
    for(uint i=0; i<puis;i++){
        SYNDROME s = syndrome(H, mots_code[i], k,n);
        printf("<Mots code> ");
        affiche_vecteur(mots_code[i], n);
        printf("<syndrome original> -> ");
        affiche_vecteur(s, tmat);
        printf("\n");
    }

    /*

	Exercice 4.3
	
	Tout les syndromes sont à 0 donc il n'y a pas de problème dans l'encodage !
	d'ailleurs c'est pour ça que e vaut 1.
    */
    printf("Si tout les syndromes sont à 0 => pas de problème dans l'encodage.");

    //TEST BRuITAGE
    VECTEUR* vtest_b = (VECTEUR*)calloc(n, sizeof(VECTEUR));
    vtest_b[0]=0;
    vtest_b[1]=0b1110010;
    vtest_b[2]=0b0110100;
    vtest_b[3]=0b1000110;
    vtest_b[4]=0b0010111;
    vtest_b[5]=0b0111001;
    vtest_b[6]=0b0001101;

    //TEST BRUITAGE
    /*for(uint i=0; i<7; i++){
    	printf("vecteur original: ");
    	affiche_vecteur(vtest_b[i], 7);
    	printf(", indice à modifier : %d, ",i);
    	bruite(&vtest_b[i],7,i);
    	printf(" resultat : ");
    	affiche_vecteur(vtest_b[i], 7);
    	printf("\n");
    }
    free(vtest_b);*/

    for(uint i=0; i<n; i++){
    	printf("vecteur original: ");
    	affiche_vecteur(vtest_b[i], n);

    	printf("- syndrome original: ");
		SYNDROME s = syndrome(H, vtest_b[i], k,n);
		affiche_vecteur(s, tmat);

		printf("- vecteur bruité: ");
    	bruite(&vtest_b[i],n,i);
    	affiche_vecteur(vtest_b[i], n);

    	printf(" syndrome : ");
    	s = syndrome(H, vtest_b[i], k,n);
		affiche_vecteur(s, tmat);
    	
        printf("Après correction: ");
        affiche_vecteur(corrige(vtest_b[i],H,k,n), n);
        printf("décodé : ");
        affiche_vecteur(decode(corrige(vtest_b[i],H,k,n),k,n), n);
        printf("\n");

    }
    //On remarque que les syndromes indiques des erreurs après bruitage
    printf("Bits allumés : les syndromes indiquent des erreurs après le bruitage!!");


    free(vtest_b);
    free(G);
    free(mots_k);
    free(mots_code);
    return 0;
}
