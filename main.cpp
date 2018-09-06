//Liudmila Zyrianova
//CSCI 235
//05/17/2018
//Programming Assignment 3
//Problem 4

#include <iostream>
#include <vector>

using namespace std;

const int infin = 100000;

int ExtractMin(int start , vector<int>& d, vector<int>& markers ){      //Returns unvisited vertex with the smallest weighted distances
    int minim = infin;      //Smallest weighted distance in d
    int minimV = start;     //Vertex, which has the smallest weighted distance in d.
    for (int i = 0; i< d.size(); i++){      //Go through each vertex in order to find the one with the smallest weighted distance.
        if ((d[i] < minim )&& (markers[i]==0)){     //If this vertex has distance d smaller than current minim, and it hasn’t been visited in Prims,
            minim = d[i];       //make minim equal to this distance,
            minimV = i;         //minimV equal to this vertex.
        }
    }
    return minimV;          //Return the unvisited vertex with the smallest weighted distance.
}

void Prims (int start, int n, vector<vector<int>>& v, vector<int>& parent){   // Find the minimum spanning tree
    vector<int> markers (n, 0);     //Shows, whether the certain vertex has been visited ( marker [i] = 1 if i has been visited. Otherwise, 0)
    vector<int> d (n, 0);           //Stores the minimal weighted distance from vertex start to the tree.

    //Make all distances d[i] equal to infinity (infin), besides distance to start, which is 0 (d[start] = 0).
    for (int i = 0; i< n; i++) {
        if (i != start) {
            d[i] = infin; //  instead infinity
        }
    }

    parent[start]= -1;    //parent [start] = -1

    //Find all minimal weighted distances from start to the tree.
    int restV = n;        //Shows, how many vertices left to examine.
    while (restV > 1){
        int minimV = ExtractMin(start, d, markers);     //Unvisited vertex with the smallest weighted distances
        markers [minimV] = 1;       //Mark minimV as visited
        restV = restV-1;            //Decrease the number of vertices left to examine by one
        for (int i = 0; i < n; i++) {   //Go through each vertex
            if ( (markers[i]==0)&& (v[minimV][i] != -1) && ( d[i] >  v[minimV][i] ) ){      //Found the unvisited neighbor of minimV, which currently has the distance d more than the weight of the edge between minimV and itself.
                d[i] =  v[minimV][i];   //Make its distance d equal to the weight of the edge between minimV and itself.
                parent[i] = minimV;     //Change parent [i] to the minimV (vertex, which leads to i)
            }
        }
    }
}

int main() {

    int n;      //Number of vertices in graph
    cin >> n;

    vector<vector<int>> v;      //Stores the input Adjacency Matrix
    vector<int> tr;             //Empty vector
    vector<int> parent (n, 0);  //Keeps track of the parents of vertices.

    //Fill out v and cyc by empty vectors
    for (int i = 0; i < n; i++) {
        v.push_back(tr);
    }

    //Read the input adjacency matrix to v
    int x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> x;
            v[i].push_back(x);
        }
    }


    Prims(0, n ,v, parent);     //Do Prim’s Algorithm in order to find the minimum spanning tree.

    int total = 0;  //Equal to the total weight of MST.


    for (int i=0; i<n; i++){    //Go through each vertex
        if (parent[i]!= -1){        //If this vertex has a parent,
            cout<< "( "<< parent[i]<< " , "<< i <<" )"<< endl;      //print this vertex with its parent. This will be the edge from MST between this vertex with its parent.
            total = total + v[i][parent[i]];    //Add the weight of printed edge to the total
        }
    }
    cout<< "Total weight of MSP is "<< total<< endl;        //Print out the total weight of MST.

    return 0;
}