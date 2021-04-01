#include <iostream>
#include <fstream>
#include "save_game.h"	

using namespace std;

void save_game(int **stat, bool a, int nims){
	ofstream status;
	stat[0][0]=a;
	status.open("game_status.txt",ios::out|ios::trunc);
	status<<stat[0][0]<<" "<<stat[0][1]<<" ";
	for (int i=1;i<nims+1;i++){
		for (int j=0;j<nims;j++){
			status<<stat[i][j]<<" ";}}
	status.close();}
