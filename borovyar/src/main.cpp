#include "game.hpp"
using namespace std;

///Main:
///In main I have main proccess of Game, so basically start&end of game, input recieving function;

///Input recieving function
char Input ( CGame* m_game = nullptr ){
    char tmp, check;

    if( !m_game ){
        cout << "Enter your choice: " << endl;
    }
    else if( !m_game->detected( check ) ){
        cout << "Enter your choice:  Q ( exit )/ R ( inventory )" << endl;
    }
    else if( check == 'N' || check == 'V'){
        cout << "Enter your choice: E ( travel )  " << endl;
    }
    else if( check != 'N' && check != 'V' && m_game->detected( check )){
        cout << "Enter your choice: E ( interaction )/ I ( print info )  " << endl;
    }

    cin >> tmp;
    return char(tolower(tmp));
}

int main(){
    vector< vector <char> > m_map;
    CGame m_game ( m_map );

    while( !m_game.getEnd() ){
        system("clear");

        m_game.printMenu( cout );
        m_game.specifyChoice( Input( nullptr ) );

        if( m_game.getGameOn() ){
            while( m_game.getGameOn() ){
                m_game.drawMap ( );
                m_game.Movement( Input( &m_game ));
            }
        }

    }

    return 0;
}