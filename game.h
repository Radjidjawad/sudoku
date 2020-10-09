#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <algorithm>
#include <string>
#include "grid.h"


using namespace std;

class Game {
private:
    int sudokuGrid[9][9];
    string sudokuGridHidden[9][9];
    bool hiddenGrid[81];
public:
    void generate_plateau();
    void hideElements(int nbreElementToHide);
    bool changeElementValue(int ligne, int colonne,int value);
    void afficherPlateau();
    bool joueurAGagner();
    void play(int nbreCacher);
};


#endif // GAME_H_INCLUDED
