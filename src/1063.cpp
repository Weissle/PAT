#include<iostream>
#include<map>
#include<set>
using namespace std;
class solution1063 {
public:
	int main() {
		typedef set<unsigned int> mySet;
		int n;
		cin >> n;
		//set<unsigned int> *p = new set<unsigned int>[n];
		mySet *p = new mySet[n];
		for (int i = 0; i < n; ++i) {
			int tempn;
			cin >> tempn;
			for (int j = 0; j < tempn; ++j) {
				int temp;
				cin >> temp;
				p[i].insert(temp);
			}
		}
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			a--; b--;
			unsigned int down = p[a].size() + p[b].size();
			unsigned int up = 0;
			mySet *small, *big;
			//区分集合size，减少find的寻找次数
			if (p[a].size() > p[b].size()) {
				small = &p[b];
				big = &p[a];
			}
			else {
				big = &p[b];
				small = &p[a];
			}
			
			for (auto it = small->begin(); it != small->end(); ++it) {
				auto temp = *it;
				if (big->find(temp) != big->end()) ++up;
			}
			down -= up;
			printf("%.1f%%\n", (1.0*up / down) * 100);
		}
		return 0;
	}
};
int main() {
	solution1063 p;
	p.main();

	system("pause");
	return 0;
}