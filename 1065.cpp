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

class solution1065 {
	int T;
public:
	typedef long long int lli;
	bool cmp2(lli a, lli b) {
		if (b <= 0 && a <= 0)return false;
		else if (a >= 0 && b >= 0) return true;
		else {
			if (a + b > 0)return true;
			else return false;
		}
	}
	bool cmp3(lli a, lli b, lli c) {
		c *= -1;
		lli p[3] = { a,b,c };
		sort(p, p + 3);
		if (p[0] >= 0 && p[2] > 0)return true;
		else if (p[2] <= 0)return false;
		else {
			lli temp = p[0] + p[2];
			return cmp2(temp, p[1]);
		}

	}
	int main() {
		scanf("%d", &T);
		for (int i = 0; i < T; ++i) {
			lli tempa, tempb, tempc;
			scanf("%lld%lld%lld", &tempa, &tempb, &tempc);
			bool answer = cmp3(tempa, tempb, tempc);
			printf("Case #%d: ", i + 1);
			if (answer) printf("true\n");
			else printf("false\n");
		}
		return 0;
	}

};
/*
int main() {
	solution1065 p;
	p.main();
//	cout << (unsigned long long int)(-1) / 2 << endl;
	system("pause");
	return 0;
}
*/
/*
int main() {
	int T, tcase = 1;
	scanf("%d", &T);
	while (T--) {
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		long long res = a + b;
		bool flag;
		if (a>0 && b>0 && res<0) flag = true;
		else if (a<0 && b<0 && res >= 0) flag = false;
		else if (res>c) flag = true;
		else flag = false;
		if (flag) printf("Case #%d: true\n", tcase++);
		else printf("Case #%d: false\n", tcase++);
	}
	return 0;
}*/