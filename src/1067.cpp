#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//本题一开始没有注意只能和0 swap，以为能任意swap
//所以加入了fix变量进行答案修正
class solution1067 {
	int *p;
	bool *isRank;
public:
	int main() {
		int n;

		cin >> n;
		//记录输入
		p = new int[n];
		//某个位置是否已经排好序；由于不需要输出排序后的数组，所以只需要记录是否被（虚拟）swap，而不需要真正的swap
		isRank = new bool[n]();
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			isRank[i] = false;
		}
		//由于只能和p[0]swap，所以如果需要swap且p[0]是0，则需要两次swap，先把p[0]打乱，再复原p[0]
		//如果一开始p[0]不是0，则两次swap可以少一次
		int fix = (p[0] == 0) ? 0 : -1;
		int answer = 0;
		
		for (int i = 0; i < n; ++i) {
			//原本就是正确位置或者被swap过
			if (p[i] == i || isRank[i] ) isRank[i]=true;
			else {
				int temp;
				temp = p[i];
				//循环swap直到回到起点
				++fix;
				do {
					++answer;
					isRank[temp] = true;
					temp = p[temp];
				} while (temp != i);
			}
		}
		cout << answer + 2 * fix;

		return 0;
	}
};

int main() {
	solution1067 p;
	p.main();
	system("pause");
	return 0;
}