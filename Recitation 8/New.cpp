#include <iostream>
#include <stdlib.h>

#define ROW 3
#define COL 3

using namespace std;

//A
class board{
    private:
        char table[ROW][COL];
    public:
        board(char array[ROW][COL]);
        bool checkWin();
        bool checkTie();
        bool checkFutureTie(char);

};

board::board(char array[ROW][COL]){
    for(int i = 0;i<ROW;i++){
        for(int j = 0;j<COL;j++){
            table[i][j] = array[i][j];
        }
    }   
}

//B
bool board::checkWin(){
    bool flag = false;
    for(int i = 0;i<ROW;i++){
        if(table[i][0] == 'X' && table[i][1] == 'X' && table[i][2] == 'X')
            flag = true;
        if(table[i][0] == 'O' && table[i][1] == 'O' && table[i][2] == 'O')
            flag = true;
        if(table[0][i] == 'X' && table[1][i] == 'X' && table[2][i] == 'X')
            flag = true;
        if(table[0][i] == 'O' && table[1][i] == 'O' && table[2][i] == 'O')
            flag = true;
    }
    if(table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X')
            flag = true;
    if(table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O')
            flag = true;
    if(table[0][2] == 'X' && table[1][1] == 'X' && table[2][0] == 'X')
            flag = true;
    if(table[0][2] == 'O' && table[1][1] == 'O' && table[2][0] == 'O')
            flag = true;
    return flag;
} 

//C
bool board::checkTie(){
    for(int i = 0;i<ROW;i++){
        for(int j = 0;j<COL;j++){
            if(table[i][j] == 'B'){
                return false;
            }
        }
    }  
    return !checkWin();
}
//D
bool board::checkFutureTie(char turn){
    if(checkTie()){
        return true;
    }
    char nextTurn = turn == 'X' ? 'O':'X';
    for(int i = 0;i<ROW;i++){
        for(int j = 0;j<COL;j++){
            if(table[i][j] == 'B'){
                table[i][j] = turn;
                if(checkFutureTie(nextTurn)){
                    char symb = turn == 'X' ? 'X' : 'O';
                    cout << symb << ":[" << i << "," << j << "]" <<endl;
                    return true; 
                }
                table[i][j] = 'B';
            }
        }
    }
    return false;
}

int main(int argc,char *argv[]){
    char array[ROW][COL] = {{'X','O','X'}, {'X','O','O'}, {'B','B','X'}};
    board *gameBoard = new board(array);
    bool win_result = gameBoard->checkWin();
    bool tie_result = gameBoard->checkTie();
    bool ft_result = gameBoard->checkFutureTie('O');

    cout << win_result << endl;
    cout << tie_result << endl;
    cout << ft_result << endl;
    delete gameBoard;
    return EXIT_SUCCESS;
}