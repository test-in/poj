#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#define Rep(i, b, e)\
    for (int i = (int)b; i < (int)e; i++)

using namespace std;

int TC;
int N;
int MAX_N = 13;
int perm[13];

void doTrick() {
    int idx = 0;
    Rep (i, 0, N) {
        idx = (idx += i+1)%N;
        perm[idx] = i+1;
    }

    Rep (i, 0, N)
        printf("%d ", perm[i]);
}

void shuffle() {
    queue<int> res;
    Rep (i, 0, N) {
        res.push(N-i);
        Rep (j, 0, N-i) {
            res.push(res.front());
            res.pop();
        }
    }

    stack<int> fin;
    while (!res.empty()) {
        fin.push(res.front());
        res.pop();
    }
    while (!fin.empty()) {
        printf("%d ", fin.top());
        fin.pop();
    }
}

int main()
{
    //cout << "Hello world!" << endl;
    scanf("%d", &TC);

    Rep (i, 0, TC) {
        scanf("%d", &N);

        //doTrick();        // fails
        shuffle();
        printf("\n");
    }

    return 0;
}
