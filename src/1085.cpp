#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>

long long seq[100000 + 5];

using namespace std;
int main() {
	long long n;
	long long p;
	scanf("%lld %lld", &n, &p);
	
	for (long long i = 0; i < n; ++i) {
		scanf("%lld", seq + i);
	}
	if (n < 2) {
		cout << n;
		return 0;
	}
	sort(seq, seq + n);
	long long head = 0, tail = n - 1;
	while (head <= tail) {
		long long mp = seq[head] * p;
		if (seq[tail] < mp) {
			cout << tail - head + 1;
			break;
		}
		else {
			long long disHead = seq[head + 1] - seq[head];
			long long disTail = seq[tail] - seq[tail - 1];
			long long disHeadP = disHead*p;
			if (disHeadP > disTail) ++head;
			else --tail;
		}
	}
	return 0;
}