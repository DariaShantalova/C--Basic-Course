#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	set<string> list;

	for(int i = 0; i < n; i++) {
		cin >> s;
		list.insert(s);
	}
	cout << list.size() << endl;

	return 0;
}


