#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;

class solution1068 {
	int n, m;
	int *coins;
	int **bag;
	vector<int> answer;
public:

	bool cmpAns(const vector<int> &a, const vector<int> &b) {

		const int as = a.size(), bs = b.size();
		for (int i = 0; i < min(as, bs); ++i) {
			if (a[i] > b[i]) return false;
			else if (b[i] > a[i]) return true;
		}
		return false;
	}
	void prAnswer(int i, int j) {
		vector<int> tempAns;
		int last = m;
		do {
			tempAns.push_back(coins[i - 1]);
			last -= coins[i - 1];
			j -= coins[i - 1];
			--i;
			while (i && bag[i][j] == bag[i - 1][j] ) i--;
			while (j && bag[i][j] == bag[i][j - 1]) --j;
		} while (last != 0 && i);//不加 && i 条件出现段错误
		
		reverse(tempAns.begin(), tempAns.end());

		if (answer.empty())answer = tempAns;
		else if (cmpAns(answer, tempAns)==false) {
			answer = tempAns;
		}

	}
	int main() {
		scanf("%d%d", &n, &m);
		coins = new int[n];
		bag = new int*[n + 1];
		for (int i = 0; i < n; ++i) {
			scanf("%d", coins + i);
		}
		sort(coins, coins + n);

		for (int i = 0; i <= n; ++i) {
			bag[i] = new int[m + 1];
		}
		for (int i = 0; i <= n; ++i) bag[i][0] = 0;
		for (int i = 0; i <= m; ++i) bag[0][i] = 0;

		for (int i = 1; i <= n; ++i) {
			int value = coins[i - 1];

			for (int j = 1; j <= m; ++j) {
				bag[i][j] = max(bag[i - 1][j], bag[i][j - 1]);
				
				if (j < value) continue;
				else bag[i][j] = max(bag[i][j], bag[i - 1][j - value] + value);
				if (bag[i][j] == m)	prAnswer(i, j);
				
			}
		}
		if (answer.empty())cout << "No Solution";
		else {
			for (auto i = 0; i < answer.size(); ++i) {
				if (i)printf(" ");
				printf("%d", answer[i]);
			}
		}
		return 0;

	}

};

int main() {
	solution1068 p;
	p.main();
	system("pause");
	return 0;
}