//Liudmila Zyrianova
//CSCI 235
//05/17/2018
//Programming Assignment 3
//Problem 1

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {

    int r, r1;
    cin >> r;
    r1 = r;        // Number of rows
    int c, c1;
    cin >> c;
    c1 = c;        //Number of columns

    vector<vector<int>> v;      //Stores the input matrix
    vector<vector<int>> f;      //Shows if it is possible to get to each cell from top left cell ( f[i][j] = 1 if it is possible to get to the cell (i,j); f[i][j] = 0 otherwise )
    stack <string> s;           //Stores (x; y) pairs (cell (x; y)) that represent the path
    vector<int> tr;             //Empty vector

    //Fill out v and f by empty vectors
    for (int i = 0; i < r; i++) {
        v.push_back(tr);
        f.push_back(tr);
    }

    //Read the input matrix to v and fill f by zeros
    int x;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> x;
            v[i].push_back(x);
            f[i].push_back(0);
        }
    }

    //Using dynamic programming, fill out f:
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if ( (i==0 )&&(j==0)) { f[i][j]=1; }    //The top left cell is 1, because we start from it
            else if ( (i==0) && (v[i][j]==1) && ( f[i][j-1]== 1 ) )  { f[i][j]=1; }   //If the cell in the top row, it is not “off limits”, and we can get to its left neighbor, then we can get to the cell itself.
            else if ( (j==0) && (v[i][j]==1) && ( f[i-1][j]== 1 ) )  { f[i][j]=1; }   //If the cell in the left column, it is not “off limits”, and we can get to its upper neighbor, then we can get to the cell itself.
            else if ( (v[i][j]==1) && ( ((j-1>=0) && (f[i][j-1]== 1)) || ((i-1>=0) &&(f[i-1][j]== 1)))) { f[i][j] = 1;}     //If the cell in the rest of the field, it is not “off limits”, and we can get to its upper neighbor or to its left neighbor, then we can get to the cell itself.
            else { f[i][j] = 0;}    //In all other situations we cannot get to the cell.
        }
    }

    //Go through f  from bottom right cell to upper left cell in order to reconstruct the solution: the possible path for robot
    c = c-1;
    r = r-1;
    while ( (r > 0) || (c > 0) ){
        if (f[r][c] == 1){  //If we can get to the cell
            if ( (r-1 >= 0) &&  (f[r-1][c] == 1 ) ){    //If we can get to the cell and to its upper neighbor
                s.push("( " + to_string(r+1)+ " , "+ to_string(c+1)+ " )" );    //Store the coordinates of the cell in s (increased by one in order to make all coordinates from 1 to r and from 1 to c)
                r = r-1;    //Go the upper cell.
            } else if ((c-1 >= 0) && (f[r][c-1] == 1) ) {   //If we can get to the cell and to its left neighbor
                s.push("( " + to_string(r+1)+ " , "+ to_string(c+1)+ " )" );    //Store the coordinates of the cell in s (increased by one in order to make all coordinates from 1 to r and from 1 to c)
                c = c-1;    //Go the left cell
            } else {        //In all other cases we cannot get to the cell. Thus, there is no path from top left cell to the certain cell.
                cout << "No path"<< endl;       //Show in the output, that there is no path,
                break;      //and break the cycle.
            }
        } else {            //In all other cases we cannot get to the cell. Thus, there is no path from top left cell to the certain cell.
            cout << "No path"<< endl;       //Show in the output, that there is no path,
            break;      //and break the cycle.
        }

    }

    //Need to check, whether the path exist. It exist, if we could go through f from bottom right cell to upper left cell. Only in this case we found r+c-2 coordinates, which is the path we need (excluding coordinates of the upper left cell, because our previous cycle went only to the one cell before the upper left cell).
    if (s.size() == r1+c1-2){   //In case of total r+c-2 coordinates,
        s.push("( " + to_string(1)+ " , "+ to_string(1)+ " )" );    //just add coordinates of the upper left cell in order to get the whole path.
    } else{     //Otherwise,
        stack<string> emp;
        s = emp;        //the path doesn’t exist. Thus, make s empty.
    }

    //Output:
    if (!s.empty()){    //If s is not empty, it stores coordinates of the path.
        //In this case we just peek() and pop() coordinates from stack s and show them in the output.
        cout << "The path is (the upper left corner has coordinates (1, 1)):"<< endl;
        cout << "( row, column )"<< endl;
        while (!s.empty()){
            cout << s.top()<< endl;
            s.pop();
        }
    }
    return 0;
}