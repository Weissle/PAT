#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
long long primeContain[100000] = { 0 };
bool isPrime(const long long input) {
	for (auto &temp : primeContain) {
		if (temp == 0) {
			temp = input;
			return true;
		}
		else {
			if (input%temp == 0)return false;
			else continue;
		}
	}
}


int main() {
	long long n;
	cin >> n;
	const long long nn = n;
	bool isFirst = true;
	long long thisNum = 2;
	if (n == 1) {
		cout << "1=1";
		return 0;
	}
	while (n != 1) {
		if (isPrime(thisNum) == true) {
			int count = 0;
			while (n%thisNum == 0) {
				n = n / thisNum;
				++count;
			}
			if (count) {
				if (isFirst == false)cout << "*";
				else {
					cout << nn << "=";
					isFirst = false;
				}
				cout << thisNum;
				if (count > 1)cout << "^" << count;
			}
		}
		++thisNum;
	}


	return 0;
}