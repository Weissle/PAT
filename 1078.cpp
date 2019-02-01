#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;

class solution1078 {
	int *input,Tsize,n,*table;
	int *answer;
	vector<int> primeTable;
public:
	bool isPrime(int input) {
		for (auto i : primeTable) {
			if (i == input)return true;
			if (input%i == 0) return false;
		}
		return true;
	}
	int largerPrime(int input) {
		if (input == 1)return 2;
		bool tempT[105] = {true,true,false};

		for (int i = 2; i < 105; ++i) {
			if (tempT[i]==false) primeTable.push_back(i);
			else continue;
			int temp = i + i;
			while (temp < 105) {
				tempT[temp] = true;
				temp += i;
			}
		}

		if (input % 2 == 0 && input != 2) ++input;
		while (isPrime(input) == false) input += 2;
		return input;
	}
	int main() {
		cin >> Tsize >> n;
		Tsize = largerPrime(Tsize);
	//	cout << Tsize;
		table = new int[Tsize]();
		input = new int[n]();
		answer = new int[n]();
		
		for (int i = 0; i < n; ++i) scanf("%d", input + i);
		for (int i = 0; i < n; ++i) {
			int  key = input[i] % Tsize;
			int index;
			int count = 0;
			do {
				index = (key + count*count) % Tsize;
				if (table[index] != 0) ++count;
				else {
					table[index] = input[i];
					break;
				}
			} while (count < Tsize);
			if (count >= Tsize) answer[i] = -1;
			else answer[i] = index;
		}
		for (int i = 0; i < n; ++i) {
			if (i) printf(" ");
			if(answer[i] != -1) printf("%d", answer[i]);
			else printf("-");
		}
		return 0;
	}

};
/*
int main() {
	solution1078 p;
	p.main();
	system("pause");
	return 0;
}*/