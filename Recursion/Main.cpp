#include <iostream>
#include <stdlib.h>
#include <stack>

#define RIGHT   1
#define LEFT    2
#define UP      3
#define DOWN    4

#define MAZE_HOR_SIZE    8
#define MAZE_VER_SIZE    8
#define WALL   '#'
#define PATH   ' '
#define GONE   'o'

using namespace std;

void recursion_examples();
int factorial(int);
int power(int,int);
int fibonacci(int);
int iter_sum(int*,int);
void recursive_hanoi(int);
void hanoi_move(stack<char> pegs[3],int,int,int,int);
void recursive_maze();
void print_maze(char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE]);
bool find_path_recursive(char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE],int,int,int,int,int);

int main(int argc,char *argv[]){
    recursion_examples();
    return EXIT_SUCCESS;
}

int factorial(int val){
    if(val == 1){
        return 1;
    }
    return val*factorial(val-1);
}

int power(int a,int b){
    if(b==0){
        return 1;
    }
    return a*power(a,b-1);
}

int fibonacci(int a){
    if(a == 1 || a == 2){
        return 1;
    }
    return fibonacci(a-1)+fibonacci(a-2);
}

int recur_sum(int* arr,int size){
    if(size == 0){
        return 0;
    }
    return *(arr+(size-1)) + recur_sum(arr,size-1);
}

void recursive_hanoi(int disks){
    int source = 0;
    int dest = 2;
    int temp = 1;
    stack<char> pegs[3];
    for(int i = 0;i<disks;i++){
        pegs[0].push(64+disks-i);
    }
    hanoi_move(pegs,disks,source,dest,temp);
}

void hanoi_move(stack<char> pegs[3],int disks,int source,int dest,int temp){
    if(disks >= 1){
        hanoi_move(pegs,disks-1,source,temp,dest);
            cout << "Disk "<< pegs[source].top() << " moved from disk "<< source << " to disk "<<dest <<endl;
        pegs[dest].push(pegs[source].top());
        pegs[source].pop();
        hanoi_move(pegs,disks-1,temp,dest,source);
    }
}

void recursive_maze(){
    char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE] = {{'#','#',' ','#'},
				      						   {' ',' ',' ',' '},
										       {'#',' ','#','#'},
				    						   {'#','#','#','#'},
	};
    int enter_y = 1;
    int enter_x = 0;
    int exit_y = 1;
    int exit_x = 3;
    print_maze(maze);
    if(find_path_recursive(maze,enter_y,enter_x,exit_y,exit_x,LEFT)){
        cout << "!!!! PATH found !!!!" << endl << endl;
    }
    print_maze(maze);
}

void print_maze(char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE]){
    for (int i = 0; i < MAZE_VER_SIZE; i++) {
        for (int j = 0; j < MAZE_HOR_SIZE; j++)
            cout << maze[i][j];
        cout << endl;
    }
    cout << endl << endl;
}

bool find_path_recursive(char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE],int cur_y,int cur_x,int exit_y,int exit_x,int camefrom){
    maze[cur_y][cur_x] = GONE;
    if(cur_x == exit_x && cur_y == exit_y){
        return true;
    }
    print_maze(maze);
    
    if(cur_x > 0 && maze[cur_y][cur_x-1] != WALL && camefrom != LEFT)
        if(find_path_recursive(maze,cur_y,cur_x-1,exit_y,exit_x,RIGHT))
            return true;
    if(cur_y < MAZE_VER_SIZE-1 && maze[cur_y + 1][cur_x] != WALL && camefrom != DOWN)
        if(find_path_recursive(maze,cur_y+1,cur_x,exit_y,exit_x,UP))
            return true;
    if(cur_y > 0 && maze[cur_y-1][cur_x] != WALL && camefrom != UP)
        if(find_path_recursive(maze,cur_y-1,cur_x,exit_y,exit_x,DOWN))
            return true;
    if(cur_x < MAZE_HOR_SIZE-1 && maze[cur_y][cur_x+1] != WALL && camefrom != RIGHT)
        if(find_path_recursive(maze,cur_y,cur_x+1,exit_y,exit_x,LEFT))
            return true;
    maze[cur_y][cur_x] = PATH;
    return false;
}

void recursion_examples(){
    //int arr[10]={1,2,3,4,5,6,7,8,9,10};
    //cout<<factorial(5)<<endl;
    //cout<<power(3,5)<<endl;
    //cout<<fibonacci(6)<<endl;
    //cout<<recur_sum(arr,10)<<endl;
    //cout<<"************"<<endl;
    //recursive_hanoi(10);
    recursive_maze();
}