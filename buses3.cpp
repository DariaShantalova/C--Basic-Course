#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(){
	int n, count, count_bus = 0;
	map <set<string>, int> m;
	set<string> tmp;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> count;
		for(int j = 0; j < count; j++) {
			string t;
			cin >> t;
			tmp.insert(t);
		}
		if(m[tmp] > 0) {
			cout << "Already exists for " << m[tmp] << endl;
		}else {
			m[tmp] = ++count_bus;
			cout << "New bus " << m[tmp] << endl;
		}
		tmp.clear();
	}

	return 0;
}


