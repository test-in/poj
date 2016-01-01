/*
poj 1014: dividing
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#define Rep(i, a, b)    for (int i = (int)a; i < (int)b; i++)

// using namespace std;

int arr[6];     // value of i-th pos == i+1
string line;
int count = 1;
int total;

#define maxN 20000
int memo[maxN][maxN];		// [sum][ball types]

bool dp() {
    Rep (i, 0, 6) {
        total += (i+1)*arr[i];
    }
    cout << "sum is\t" << total << endl;

    if (total %2 != 0)		// cant divide odd sum
        return false;

    cal(total, 0);
}

int cal(int value, int type) {		// calculate by subtracting total by ball{type}
	if (value < 0) 
		memo[value][type] = -1000000000;    // fail, return a large -ve number

/*
	if (value == total/2)
        // mem[value][type] = value-(1+type);
        return value-arr[type];
*/
    
    if (memo[value][type] != -1)
        return memo[value-arr[type]][type]+arr[type];

    int curr = -1;
    m
    
    Rep (i, 0, 
}

int main() {
    stringstream is;

	memset(memo, -1, sizeof memo);		// for dp
	
    while (true) {
        getline(cin, line);
        if (line == "0 0 0 0 0 0")
            break;
            
        is << line;
        memset (arr, -1, 6);

        Rep(i, 0, 6) {
            is >> arr[i];
            cout << arr[i] << "\t";
        }

        printf("Collection #%d:\n", count++);
        if (dp()) {
            cout << "Can't be divided.\n";
        } else {
            cout << "Can be divided.\n";
        }
    }

    return 0;

}
