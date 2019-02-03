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
//set中元素自动排序，重载<可以实现自定义序列！！
class solution1120 {
	int N;
	set<int> id;
public:
	int calID(int input) {
		int answer = 0;
		while (input != 0) {
			answer += input % 10;
			input /= 10;
		}
		return answer;
	}
	int main() {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			int temp;
			scanf("%d", &temp);
			id.insert(calID(temp));
		}

/*		vector<int> p;
		p.reserve(id.size());
		for (auto i = id.begin(); i != id.end(); ++i) {
			p.push_back(*i);
		}
		sort(p.begin(), p.end());*/
		printf("%d\n", id.size());
		for (auto i = id.begin(); i != id.end(); ++i) {
			if (i != id.begin())printf(" ");
			printf("%d", *i);
		}
		return 0;
	}

};

int main() {
	solution1120 p;
	p.main();

	system("pause");
	return 0;
}
