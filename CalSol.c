#include<stdio.h>
#include "sol.h"


void CalSol(int NbLign, float** coord, float* UEX){

  int nucas = 1;
  float coor[2] = {0};

  for (int i=0; i<NbLign; i++){
    coor[0] = coord[i][0];
    coor[1] = coord[i][1];

    UEX[i]  = solex(coor);
  }

}
