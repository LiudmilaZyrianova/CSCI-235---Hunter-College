// Liudmila Zyrianova,CSCI 235, 02/27/2018, Programming Assignment 1, Problem 3:
#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int> v, int l, int h, int x)  //Binary search find the position of the largest number, which is smaller x
{
	if (h > l)      //If the length of the remaining vector >=1
	{
		int m = l + (h - l) / 2;  //Take the middle of array

		if (v[m] == x)	{ return m-1; }  // Found the element in the vector => returns the position of the largest number, which is smaller x.
                                            // This element is the previous one
		if (v[m] > x)	{ return binarySearch(v, l, m - 1, x);	}  // If x is less, ignore right part

		if (v[m] < x)	{ return binarySearch(v, m + 1, h, x);	}  // If x is greater, ignore left part

    }
	if (h == l)     //If the length of the remaining vector =1
	{
		if (v[l] == x) return l - 1;    // Found the element in the vector => return the position of the largest number, which is smaller x.
                                        // This element is the previous one
		if (v[l] > x) return l-1;   // If x is less, return the position of the largest number, which is smaller x. This element is the previous one
		if (v[l] < x) return l;     // If x is greater, return the position of the largest number, which is smaller x. This element is the current one
	}

	return -1;
}

int main()
{
    cout<< "Enter integer x, n, and numbers from array, separated by Space"<<endl;     //Request input
	int x, n;
	cin >> x >> n;                      // Reads x, n
	vector<int> v;

	int k;
	for (int i = 0; i < n; i++) {       // Reads array as vector
		cin >> k;
		v.push_back(k);
	}

	int res;
	res = binarySearch(v, 0, n-1, x);   // Does binary search in order to find the position of the largest number, which is smaller x

	if (res >= 4) {         // There is 5 biggest number, which are smaller x
        cout << v[res-4] << " " << v[res-3] << " " << v[res-2] << " " << v[res-1] << " " << v[res] << endl; //Print them
    }
	else if (res >= 0)      // There is less than 5 numbers, which are smaller x
	{
		int ii = 0;
		while (ii<=res) {       //Print them
			cout << v[ii] << " ";
			ii++;
		}
		cout << endl;
	}
	else {      // There is no numbers, which are smaller x. This situation occurs when x is equal or less the first number.
		cout << "x is smaller or equal to the smallest number from array" << endl;
	}
    return 0;
}


