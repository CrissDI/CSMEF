#include<stdio.h>
#include<stdlib.h>
#include "forfun.h"
#include "assmb.h"


void dSMDaSMO(float* secmbrO, int* AdPrCoefLiO, float* MatriceO, int* NumColO, char* nomfich, char* nomfic){


  /*** Lecture du fichier binaire SMD ***/

  int NbLign1;
  int* AdPrCoefLi1;
  float* secmbr1;
  int* nuddir1;
  float* valdir1;
  int NbCoef1;
  float *Matrice1;
  int* NumCol1;
  int* AdSuccLi1;


  LecSMD(&NbLign1, &NbCoef1, &secmbr1, &nuddir1, &valdir1,
	     &AdPrCoefLi1, &Matrice1, &NumCol1, &AdSuccLi1,"SMD_bin.txt");


  /*** Passage du stockage SMD a SMO ***/

  cdesse_(&NbLign1, AdPrCoefLi1, NumCol1, AdSuccLi1,
          Matrice1, secmbr1, nuddir1, valdir1,
          AdPrCoefLiO, NumColO, MatriceO, secmbrO);


  /*** Ecriture dans le fichier binaire SMO ***/

  FILE* smo = fopen(nomfic, "wb");        /* "SMO_bin.txt" */
  if (smo == NULL){
    printf("Ouverture du fichier impossible !\n");
    exit(1);
  }

  fwrite(&NbLign1, sizeof(int), 1, smo );
  fwrite( secmbrO, sizeof(float), NbLign1, smo );
  fwrite( AdPrCoefLiO, sizeof(int), NbLign1, smo );
  fwrite( MatriceO, sizeof(float), NbLign1+NbCoef1, smo );
  fwrite( NumColO, sizeof(int), NbCoef1, smo );

  fclose(smo);

  /* affsmo_(&NbLign1,AdPrCoefLiO,NumColO,MatriceO,secmbrO); */


  /* Liberation memoire */

  free(Matrice1);
  free(AdPrCoefLi1);
  free(AdSuccLi1);
  free(NumCol1);
  free(valdir1);
  free(nuddir1);
  free(secmbr1);

}
