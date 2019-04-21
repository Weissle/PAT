#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class solution1121 {
public:
    int main() {
		map<string, string> s1;
		int n, m;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			string a, b;
			cin >> a >> b;
			s1[a] = b;
			s1[b] = a;
		}
		cin >> m;
		set<string> guest;
		vector<string> answer;
		for (int i = 0; i < m; ++i) {
			string temp;
			cin >> temp;
			string p1 = s1[temp];
			//no CP exist
			if (p1 == "") {
				answer.push_back(temp);
			}
			else {
				string &per = p1;
				
				auto findCP = guest.find(per);
				//CP not in guest list (yet)
				if (findCP == guest.end()) guest.insert(temp);
				//find CP in guest list
				else guest.erase(*findCP);
			}
		}
		for (auto i = guest.begin(); i != guest.end(); ++i) answer.push_back(*i);
		sort(answer.begin(), answer.end());
		cout << answer.size() << endl;
		for (int i = 0; i < answer.size(); ++i) {
			if (i != 0) cout << " ";
			cout << answer[i] ;
		}
		return 0;
	}
};

int main() {
	solution1121 p;
	p.main();
	system("pause");
	return 0;
}