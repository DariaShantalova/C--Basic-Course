#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
	int n;
	string s;
	int number;
	vector<int> queu;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		if(s == "WORRY") {
			cin >> number;
			if(number < queu.size()) {
				queu[number] = 1;
			}
		}
		if(s == "QUIET") {
			cin >> number;
			if(number < queu.size()) {
				queu[number] = 0;
			}
		}
		if(s == "COME") {
			cin >> number;
			if(number >= 0) {
				for(int i = 0; i < number; ++i)
					queu.push_back(0);
			}else {
				if((-1) * number <= queu.size()) {
					for(int i = 0; i < (-1)*number; ++i)
						queu.pop_back();
				}
			}
		}
		if(s == "WORRY_COUNT") {
			int count = 0;
			for(auto c : queu){
				if(c != 0) {
					count++;
				}
			}
			cout << count << endl;
		}
	}

return 0;
}


