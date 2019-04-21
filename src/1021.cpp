#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class solution1021 {
	class inf {
	public:
		int dis, father;
		inf() = default;
		inf(int _d,int _f):dis(_d),father(_f){}
	};
	inf *distance;
	map<int, set<int> > graph;
	bool *hadTra;
	
public:
	void DFS(int input) {
		const set<int> &edges = graph[input];
		for (auto i = edges.begin(); i != edges.end(); ++i) {
			if (hadTra[*i] == true)continue;
			else {
				distance[*i].dis = distance[input].dis + 1;
				distance[*i].father = input;
				hadTra[*i] = true;
				DFS(*i);
			}
		}
		return;
	}
	int main() {
		int n;
		cin >> n;
		distance = new inf[n + 1];
		hadTra = new bool[n + 1];
		for (int i = 0; i < n; ++i) {
			int tempa, tempb;
			cin >> tempa >> tempb;
			graph[tempa].insert(tempb);
			graph[tempb].insert(tempa);
		}
		int smallGraphNum = 0;
		for (auto i = graph.begin(); i != graph.end(); ++i) {
			if (hadTra[i->first] == false) {
				++smallGraphNum;
				DFS(i->first);
			}
			else continue;
		}



		return 0;
	}
};

int main() {
	solution1021 p;
	p.main();
	system("pause");
	return 0;
}