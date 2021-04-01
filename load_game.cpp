//load_game.cpp

#include "load_game.h"

using namespace std;

void load_game(char **arr,int& nims, int **game_status, bool& player){
	ifstream status ("game_status.txt");
	status>>player>>nims;
	int line=0;
	game_status[0][0]=player;
	game_status[0][1]=nims;
	for (int i=1;i<nims+1;i++){
		for(int j=0;j<nims;j++){
			status>>game_status[i][j];
			if (game_status[i][j]==1){
				arr[line][j]='*';}
			else{
				arr[line][j]='x';}}
		line+=1;}}
	
