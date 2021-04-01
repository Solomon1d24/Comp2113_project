#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <fstream>
#include "save_game.h"
#include "load_game.h"

using namespace std;

const int rest = 2;
bool player=0;
int **game_status=NULL;

void delete_file();
bool check_winner(char **arr, int nims);
bool check_if_picked(char **arr, int rows, int columns)
{   
    if(arr[rows][columns] == 'x')
        {return true;}
    else
        {return false;}
    
}

void pick_nims (char **arr, int nims, int num_nims_pick, int **game_status)
{   int rows = 0, columns = 0;
    int picked = 0;
    while (picked < num_nims_pick and check_winner(arr,nims))
        {
            cout << "Which nim you want to pick? Please enter in the form of (rows,columns) " << "\n";
            cin >> rows >> columns;
            if(rows<=0||rows>nims)
                {
                    cout << "Invalid entry, please make sure that rows is less than or equal to " << nims << " and also greater than 0" << "\n";
                    continue;
                }
            if(columns<=0||columns>nims+1)
                {
                    cout << "Invalid entry, please make sure that columns is less than or equal to " << nims + 1 << " and also greater than 0" << "\n";
                    continue;
                }
            if(check_if_picked(arr,rows-1,columns-1) == true)
                {
                    cout << "This nim has been taken, try another one" << "\n";
                    continue;
                }
            arr[rows-1][columns-1] ='x';
	    game_status[rows][columns-1]=0;
            picked++;
        }
}

char** getarray(int nims)
{
    char** arr = new char *[nims];
    for(int i=0;i<nims;++i)
        {
            arr[i] = new char[nims+1];
            for(int j=0;j<nims+1;++j)
                {
                    arr[i][j] = '*';
                }
        }
    return arr;
}

void printarray(char** arr, int nims)
{
    for(int i=0;i<nims;i++)
        {
            for(int j=0;j<nims+1;j++)
            {
                cout << arr[i][j];
            }
        cout << endl;
        }
}

bool check_winner(char **arr, int nims){
	int count_x=0;
	for (int i=0;i<nims;i++){
		for (int j=0;j<nims;j++){
			if (arr[i][j]=='*') count_x+=1;}}
	if (count_x==1){
		delete_file();
		cout<<"Player "<<player<<" win!";
		return 0;}
	else{
		return 1;}}

int main()
{   srand(time(NULL)*time(NULL));
    int nims = rand()%6 + 5;
    string num_nims_pick; //To check if the iuput is Q or not
    int real_num_nims_pick=0;  //real num nims pick to calculate
    char **arr;
    game_status= new int*[nims+1];
    for (int i=0;i<nims+1;i++){  //intialize
	    game_status[i]=new int[nims];
	    for(int j=0;j<nims;j++){
		    game_status[i][j]=1;}}
    game_status[0][0]=player;
    game_status[0][1]=nims;
    arr = getarray(nims);
    ifstream check ("game_status.txt");  //check if there are any saving fie before this game
    if (check.good()){
	    cout<<"Do you want to resume your last progress? Type y for yes and n for no."<<endl;
	    string check_i;
	    cin>>check_i;
	    if (check_i=="y"){
		    load_game(arr,nims,game_status,player);
	    		cout<<"Welcome Back!"<<endl;}
	    else{
		    cout<<"Welcome"<<endl;}}
    else{
		    cout<<"Welcome!"<<endl;}
    check.close();

    while (check_winner(arr,nims)){
      cout << "Here is the new matrix!" << "\n";
      printarray(arr,nims);
      cout <<  "Number of rows: " << nims << '\n';
      cout <<  "Number of columns: " << nims  << '\n';
      cout << "This is the turn for Player " << player << "\n";

      cout << "Please decide number of nim（s） you want to pick （At most 2) or type q to exit and save the game." << '\n';
	    
      while(real_num_nims_pick <= 0 || real_num_nims_pick >rest )
    {
        cin >> num_nims_pick;
	if (num_nims_pick=="q"){      //if the player want to leave, game status will be saved and end the programe
		save_game(game_status,player,nims);
		return 0;} 
	real_num_nims_pick=stoi(num_nims_pick); //pass string as integer
        if(real_num_nims_pick <= 0 || real_num_nims_pick >rest)
            {
                cout << "Invalid number! Please type again! ";
            }
    }

      pick_nims (arr ,nims,real_num_nims_pick, game_status);
      player=!player;
      save_game(game_status,player,nims);
      real_num_nims_pick=0;}
    delete [] game_status;
    game_status=NULL;    
}
