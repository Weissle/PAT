#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;
//这题用cin输入流会导致超时，所以使用scanf
class solution1032 {
	map<int, int> link;
	set<int> worda;

public:
	int findNext(int input) {
		if (input == -1) return -1;
		else return link[input];
	}
	int main() {
		int n;
		int inita, initb;
		scanf("%d%d%d", &inita, &initb, &n);
		int answer = -1;
		//字符a没有用，忽略
		for (int i = 0; i < n; ++i) {
			char a;
			int tempa, tempb;
			scanf("%d %c %d", &tempa, &a, &tempb);
			link[tempa] = tempb;
		}
		int pointera = inita;
		//把单词a放入set中
		while (pointera != -1) {
			worda.insert(pointera);
			pointera = findNext(pointera);

		}
		int pointerb = initb;
		//找到第一个地址相同的节点
		while (pointerb != -1) {
			if (worda.find(pointerb) != worda.end()) {
				printf("%05d", pointerb);
				return 0;
			}
			else pointerb = findNext(pointerb);
		}
		cout << -1;
		return 0;
	
	}
};

int main() {
	solution1032 p;
	p.main();
	system("pause");
	return 0;
}