// Liudmila Zyrianova,CSCI 235, 02/27/2018, Programming Assignment 1, Problem 2 b):

#include <iostream>
#include <vector>

using namespace std;
int n;
int param =0;
vector<int> v;   // Vector stores in the v[i] value of the column j, where i-th queen, located in the i-th row, is placed.

void print_board() {            //Prints the chess board, where “1” – queens, “0” – empty squares.
    for (int i=0; i<v.size(); i++){     //Goes through each row i,
        for (int j=0; j<n; j++){        // and if there is v[i] between 0 and n in this row,
            if (j==v[i]){cout<<"1";}    // on the place v[i] it prints “1”, otherwise – “0”.
            else {cout<<"0";}
        }
        cout<<endl;
    }
    cout<<endl;
}

int notShare (int i, int j){  // Checks whether the queen with coordinates (i,j) will not share row, column, or diagonal  with already plugged queens
    for (int k=0; k<i; k++) {
        if (i==k){ return 0; }
        if (j==v[k]) { return 0;}
        if (i+j==k+v[k]) { return 0;}
        if (i-j== k-v[k]) { return 0;}

        // If queen with coordinates (i,j) shares row, or column, or diagonal from bottom-left to top-right, or diagonal from top-left to down-right
        // with any ot the i-1 previous queens. Thus, return 0.
    }
    return 1; //Else return 1. Means, that queen does not share any row, or column, or diagonal with ither queens
}

int putQueen (int i, int j){ //Tries to put i-th queen somewhere in the i-th row
    if (param == 0) {        //Checks, whether it is needed to continue the recursion.
        if (i < n) {            //If we still need to put at least one more i-th queen
            for (int l = 0; l+j < n; l++) {     //Check all the possible position in the row: (i , j+0), (i , j+1), … .
                if (notShare(i, j+l) == 1) {    //If this position is suitable,
                    v[i] = j+l;                 //v[i] becomes equal to this position
                    putQueen(i + 1, 0);         //Recursively starts to count the suitable position of i+1 – th queen from the 0-th position in the row
                }
            }
            //In case if there is no suitable place for i-th queen, the recursion on i-th breaks down and comes back to the i-1 – th queen’s recurtion,
            //and its cycle for (int l = 0; l +j < n; l++) {} continues to change the position of i-1 – th queen.
        } else{                                 //If the function has putted all n queen
            print_board();                      //Prints the board
            param = param+1;                    //Changes the param  by one, which prevent any further manipulations with the positions of the queens
        }
    }
}


int main() {
    cout << "Enter a number n - the width of the chess board" << endl;  //Requests the input
    cin >> n;               //Reads the user's input - width of the chess board
    for (int i = 0; i < n; i++) { v.push_back(0); }         //Fill vector with zeroes
    putQueen(0, 0);              //Prints one board
    return 0;
}

