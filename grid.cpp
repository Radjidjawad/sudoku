#include "grid.h"


 Grid::Grid() {

 }


 void Grid::createGrid() {

    int nombre = 1;
    int nombre2;

    for(int i = 0;i < NBLIGNE; i++){
        nombre2 = nombre;
        for(int j = 0; j < NBCOLONNE;j++){
            if(nombre2 <= 9){
                plateau[i][j] = nombre2;
                nombre2++;
            } else{
                nombre2 = 1;
                plateau[i][j] = nombre2;
                nombre2++;
            }
        }
        nombre = nombre2 + 3;
        if(nombre2 == 10){
            nombre = 4;
        }
        if(nombre > 9){
            nombre %= 9;
            nombre+= 1;
        }
    }


 }


void Grid::permuter_Ligne(int ligne1,int ligne2){
    int temporaire;
    for(int j=0;j<9;j++)
    {
       temporaire = plateau[ligne1][j];
       plateau[ligne1][j] = plateau[ligne2][j];
       plateau[ligne2][j] = temporaire;
    }
}

void Grid::permuter_colonne(int colonne1,int colonne2){
   int temporaire;
   for(int j=0;j<9;j++)
   {
      temporaire = plateau[j][colonne1];
      plateau[j][colonne1]= plateau[j][colonne2];
      plateau[j][colonne2]= temporaire;
    }
}


void Grid::Generer_Real_Grid(int argCheck) {
    int nbre1,nbre2,maximum = 2,minimum = 0;

    for(int i=0;i<3;i++)
    {
       nbre1 = rand() % (maximum - minimum + 1) + minimum;

       do{
          nbre2 = rand() % (maximum - minimum + 1) + minimum;
       }while(nbre1 == nbre2);

       maximum += 3; minimum += 3;

       if(argCheck == 1)
       {
            Grid().permuter_Ligne(nbre1,nbre2);
       }
       else if(argCheck == 0)
            Grid().permuter_colonne(nbre1,nbre2);
       }
}





