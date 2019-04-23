#include<iostream>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int s[10000];
int top = 0;
int main() {
	int n;
	cin >> n;
	while (n) {
		n--;
		char op[20];
		scanf("%s", op);
		char ops[3] = { op[0],op[1] };
		if (strcmp(ops, "Po") == 0) {
			if (top == 0)cout << "Invalid";
			else cout << s[--top];
			if (n)cout << endl;
		}
		else if (strcmp(ops, "Pu") == 0) {
			int temp;
			scanf("%d", &temp);
			s[top++] = temp;
		}
		else if (strcmp(ops, "Pe") == 0) {
			if (top == 0)cout << "Invalid";
			else {
				const int temp = top + 1;
				cout << s[temp / 2 - 1];
			}
			if (n)cout << endl;
		}
		
	}
	return 0;
}