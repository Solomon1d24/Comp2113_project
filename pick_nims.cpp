#include <iostream>
#include <string>

using namespace std;
const int  N = 3;

void pick_nims (char **arr, int nims, int num_nims_pick);
bool check_if_picked(char array[][11], int rows, int columns);
char** getarray(int nims);
void printarray(char** arr, int nims);

int main()
{
  int nims = 10;
  int num_nims_pick = 2; 
  int player = 0;
  char** arr;
 arr = getarray(nims);
 printarray(arr,nims);
 cout << "Number of rows is " << nims << "\n";
 cout << "Number of columns is " << nims + 1 << "\n";

pick_nims (arr ,nims,num_nims_pick);
printarray(arr,nims);


}


bool check_if_picked(char **array, int rows, int columns)
{   
    if(array[rows][columns] == 'x')
        {return true;}
    else
        {return false;}
    
}


void pick_nims (char **array, int nims, int num_nims_pick)
{   int rows = 0, columns = 0;
    int picked = 0;
    while (picked < num_nims_pick)
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
            if(check_if_picked(array,rows-1,columns-1) == true)
                {
                    cout << "This nim has been taken, try another one" << "\n";
                    continue;
                }
            array[rows-1][columns-1] ='x';
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