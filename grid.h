#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED
#include <cstdlib>
#include <iostream>



#define NBLIGNE 9
#define NBCOLONNE 9

using namespace std;

class Grid {
public:
    int plateau[NBLIGNE][NBCOLONNE];
    Grid();
    void createGrid();
    void permuter_Ligne(int ligne1,int ligne2);
    void permuter_colonne(int colonne1,int colonne2);
    void Generer_Real_Grid(int argCheck);


};




#endif // GRID_H_INCLUDED
