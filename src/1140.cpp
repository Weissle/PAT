#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;

class solution1140 {
	int D, N;
	map<int, int> count;
public:
	void calNextSeq() {
		map<int, int> nextcount;
		for (int i = 0; i <= 9; ++i) {
			if (count[i] == 0)continue;
			else {
				int temp = count[i];
				nextcount[i]++;
				while (temp != 0) {
					nextcount[temp % 10]++;
					temp /= 10;
				}
			}
		}
		count = nextcount;
	}
	void prAns() {
		cout << D << count[D];
		for (int i = 0; i <= 9; ++i) {
			if (i == D)continue;
			else if (count[i] == 0)continue;
			else cout << i << count[i];
		}
		return;
	}
	int main() {
		scanf("%d%d", &D, &N);
		count[D] = 1;
		if (N == 1)cout << D;
		else if (N == 2)cout << D << 1;
		else {
			for (int i = 3; i < N; ++i) {
				calNextSeq();
				prAns();
	     		cout << endl;
			}
		}
		prAns();
		return 0;
	}

};

int main() {
	solution1140 p;
	p.main();

	system("pause");
	return 0;
}
