// https://www.topcoder.com/community/data-science/data-science-tutorials/dynamic-programming-from-novice-to-advanced/

#include <iostream>
#define Rep(i, a, b)\
	for (int i = (int)a; i < (int)b; i++)

using namespace std;

int row;
const int maxN = 101;
int tri[maxN][maxN];
int sum[maxN][maxN];

int dp() {
	Rep (p, 0, row) {
		Rep (q, 0, p+1) {
			if (p >= 1) {
				if (q>=1) {
					if (q <= p && sum[p-1][q-1] < sum[p-1][q]) {
						sum[p][q] += tri[p][q]+sum[p-1][q];
//						cout << sum[p][q] << " ";
					} else {
						sum[p][q] += tri[p][q]+sum[p-1][q-1];
//						cout << sum[p][q] << " ";
					}
				} else {
					sum[p][q] += tri[p][q]+sum[p-1][q];
//				cout << "along left" << sum[p][q] << endl;
//				cout << sum[p][q] << " ";
				}
			} else {
				sum[p][q] += tri[p][q]+0;
//				cout << "top sum\t" << sum[p][q] << endl;
//				cout << sum[p][q] << " ";
			}
		}
//		cout << endl;
	}
	
	int max = -1;
	Rep (r, 0, row) {
		if (sum[row-1][r] > max)
			max = sum[row-1][r];
	}
//	cout << "max is\t" << max << endl;
	return max;
}

int main() {
	cin >> row;
	Rep (i, 0, row) {
		Rep (j, 0, i+1) {
			cin >> tri[i][j];
//			cout << tri[i][j];
		}
//		cout << endl;
	}
	
	cout << dp() << endl;
	
	return 0;
}
