#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<math.h>
using namespace std;
//sort function
bool cmp(const int a, const int  b) {
	return a > b;
}
class solution1105 {
	int N, n, m;
	int *p;
	int **answer;
	//x,y coordination direction ,answer[x][y]
	int Dx[4] = { 0,1,0,-1 };
	int Dy[4] = { 1,0,-1,0 };
public:
	//get n,m from N
	void adjustNM() {
		int temp = sqrt(N);
		for (int i = 1; i < temp + 1; ++i) {
			if (N%i == 0 && (N / i) >= i) {
				n = i;
				m = N / i;
			}
		}
	}
	
	int main() {
		scanf("%d", &N);
		p = new int[N]();
		for (int i = 0; i < N; ++i) scanf("%d", p + i);

		adjustNM();
		sort(p, p + N, cmp);

		answer = new int*[m];
		for (int i = 0; i < m; ++i) answer[i] = new int[n]();
		int ordX = 0, ordY = 0, Dir = 0;
		for (int i = 0; i < N; ++i) {
			answer[ordX][ordY] = p[i];
			if (i == N - 1)break;
			//get new x,y
			do {
				int tempx = ordX + Dx[Dir], tempy = ordY + Dy[Dir];
				//change direction
				if (tempx >= m || tempy >= n  || tempx < 0 || tempy < 0 || answer[tempx][tempy] != 0) Dir = (Dir + 1) % 4;
				else  break;
			} while (true);
			ordX = ordX + Dx[Dir], ordY = ordY + Dy[Dir];

		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j)printf(" ");
				printf("%d", answer[i][j]);
			}
			printf("\n");
		}
		return 0;
	}

};

int main() {
	solution1105 p;
	p.main();
	system("pause");
	return 0;
}