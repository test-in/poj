/*
poj 1014: dividing
*/

#include <iostream>
#include <cstdio>
#define MAXN 100000
//using namespace std;

int zeroCount;
int m[6];
int memo[MAXN][MAXN];

void det() {

}

int main()
{
    int count = 1;
    while (scanf("%d %d %d %d %d %d", &m[0], &m[1], &m[2], &m[3], &m[4], &m[5])) {
        if (m[0]==0 && m[1]==0 && m[2]==0 && m[3]==0 && m[4]==0 && m[5]==0) {
            // printf("ends\n");
            break;
        }
        printf("Collection #%d:\n", count++);
        det();
    }

    return 0;
}
