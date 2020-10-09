
#include "game.h"
#include <sstream>


template <typename T>
string ToString(T val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}

bool Game::changeElementValue(int ligne, int colonne,int value) {

    int modifiable = hiddenGrid[9 * (ligne -1) + (colonne - 1)];

    if(modifiable == 1) {
        sudokuGridHidden[ligne - 1][colonne - 1] = ToString(value); //to_string(value);
        return 1;
    } else {
        return 0;
    }


}


void Game::hideElements(int nbreElementToHide) {

    for(int i = 0; i < 81; i++) {
        if( i < nbreElementToHide -1) {
            hiddenGrid[i] = 1;
        } else {
            hiddenGrid[i] = 0;
        }
    }

    std::random_shuffle(&hiddenGrid[0],&hiddenGrid[80]);

    int cpt = 0;
    for(int l = 0; l < 9; l++) {
        for(int c = 0; c < 9; c++) {
            if(hiddenGrid[cpt] == 1) {
                sudokuGridHidden[l][c] = '.';
            } else {
              sudokuGridHidden[l][c] = ToString(sudokuGrid[l][c]); //to_string(sudokuGrid[l][c]);
            }
            cpt++;
        }
    }

}


void Game::generate_plateau() {
    Grid grid = Grid();
    grid.createGrid();

    int x;

    for(int k = 0; k < 10; k++){
        x = rand() % 2;
        grid.Generer_Real_Grid(x);
    }

    for(int index = 0; index < 9; index++) {
        for(int loop = 0; loop < 9; loop++) {
            sudokuGrid[index][loop] = grid.plateau[index][loop];
        }
    }

}


void Game::afficherPlateau(){

    for(int i = 0;i < 9; i++){
      cout << "--------------------------------------------" << endl;
      for(int j =0;j < 9; j++){
          cout << " " << sudokuGridHidden[i][j] << " | ";
      }
      cout << "" << endl;
    }
    cout << "--------------------------------------------" << endl;
}



bool Game::joueurAGagner() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(sudokuGridHidden[i][j] != ToString(sudokuGrid[i][j])) { //to_string(sudokuGrid[i][j])) {
                return 0;
            }
        }
    }

    return 1;
}


void Game::play(int nbreCacher) {
    Game game = Game();

    game.generate_plateau();
    game.hideElements(nbreCacher);


    do {
        int line = -1;
        int colomumn = -1;
        int nbChange = -1;

        game.afficherPlateau();

        do {
            cout << "choose the line of the box : (between 1 - 9) : ";
            cin >> line;
        } while(line < 1 || line > 9);

        do {
            cout << "choose the colomumn of the box : (between 1 - 9) : ";
            cin >> colomumn;
        } while(colomumn < 1 || colomumn > 9);

        do {
            cout << "choose a number to write : (between 1 - 9) : ";
            cin >> nbChange;
        } while(nbChange < 1 || nbChange > 9);

        if(game.changeElementValue(line,colomumn,nbChange) == 1) {
            cout << "value changed with success" << endl;
        } else {
            cout << "you cannot change this value" << endl;
        }

    } while(game.joueurAGagner() == 0);


    cout << endl << "You win !!!!!!!!!" << endl;

}
