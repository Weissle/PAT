#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//����һ��ʼû��ע��ֻ�ܺ�0 swap����Ϊ������swap
//���Լ�����fix�������д�����
class solution1067 {
	int *p;
	bool *isRank;
public:
	int main() {
		int n;

		cin >> n;
		//��¼����
		p = new int[n];
		//ĳ��λ���Ƿ��Ѿ��ź������ڲ���Ҫ������������飬����ֻ��Ҫ��¼�Ƿ񱻣����⣩swap��������Ҫ������swap
		isRank = new bool[n]();
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			isRank[i] = false;
		}
		//����ֻ�ܺ�p[0]swap�����������Ҫswap��p[0]��0������Ҫ����swap���Ȱ�p[0]���ң��ٸ�ԭp[0]
		//���һ��ʼp[0]����0��������swap������һ��
		int fix = (p[0] == 0) ? 0 : -1;
		int answer = 0;
		
		for (int i = 0; i < n; ++i) {
			//ԭ��������ȷλ�û��߱�swap��
			if (p[i] == i || isRank[i] ) isRank[i]=true;
			else {
				int temp;
				temp = p[i];
				//ѭ��swapֱ���ص����
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