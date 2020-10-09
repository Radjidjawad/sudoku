#include <iostream>
#include <cstdlib>

#include "game.h";

using namespace std;

int main()
{

    int choice = -1;
    cout << "Welcome To SUPSUDUKU" << endl;
    cout << "Level Easy -> 1 " << endl;
    cout << "Level Meduim -> 2" << endl;
    cout << "Level Hard -> 3" << endl;

    do {
        cout << "Choose a level (1 - 2 - 3) : ";
        cin >> choice;
    } while(choice < 1 || choice >= 4);

    Game game = Game();

    game.play(choice * 15);



    return 0;
}
