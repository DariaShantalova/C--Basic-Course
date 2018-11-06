#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
void IsAnagramm(const string& str1, const string& str2) {
	map <char, int> m1, m2;
	for(auto s : str1) {
		++m1[s];
	}
	for(auto s : str2) {
		++m2[s];
	}
	if(m1 == m2) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}

}
int main(){
	int n;
	string str1, str2;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> str1 >> str2;
        IsAnagramm(str1, str2);
	}
	return 0;
}


