#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person {

	public:
	  void ChangeFirstName(int year, const string& first_name) {
		  names[year] = first_name;
	  }
	  void ChangeLastName(int year, const string& last_name) {
		  surnames[year] = last_name;
	  }
	  string GetFullName(int year) {
		if(names.count(year) != 0 && surnames.count(year) != 0) {
	    	return names[year] + ' ' + surnames[year];
	    }
	    if(names.count(year) != 0 && surnames.count(year) == 0) {
	    	if(year < surnames.begin()->first) {
	    		return names[year] + " with unknown last name";
	    	}else{
	    		return names[year] + " " + (--surnames.lower_bound(year))->second;
	    	}
	    }
	    if(names.count(year) == 0 && surnames.count(year) != 0) {
	    	if(names.size() == 0) {
	    		return surnames[year] + " with unknown first name";
	    	}else{
	    		return (--names.lower_bound(year))->second +  " " + surnames[year];
	    	}
	    }
	    if(names.count(year) == 0 && surnames.count(year) == 0) {
	    	if(names.begin()->first < year && surnames.begin()->first < year )
	    		return (--names.lower_bound(year))->second + " " + (--surnames.lower_bound(year))->second;
	    	if(names.begin()->first > year && surnames.begin()->first > year )
	    		return "Incognito";
	    	if(names.begin()->first < year && surnames.begin()->first > year )
	    		return (--names.lower_bound(year))->second + " with unknown last name";
	    	if(names.begin()->first > year && surnames.begin()->first < year )
	    		return (--surnames.lower_bound(year))->second + " with unknown first name";
	    }
	    return names[year] + ' ' + surnames[year];
	}
	private:
	  map <int, string> names;
	  map <int, string> surnames;
};
int main() {
	  Person person;

	  person.ChangeFirstName(1965, "Polina");
	  person.ChangeLastName(1967, "Sergeeva");
	  for (int year : {1900, 1965, 1990}) {
	    cout << person.GetFullName(year) << endl;
	  }

	  person.ChangeFirstName(1970, "Appolinaria");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullName(year) << endl;
	  }

	  person.ChangeLastName(1968, "Volkova");
	  for (int year : {1969, 1970}) {
	    cout << person.GetFullName(year) << endl;
	  }

	  person.ChangeLastName(1960, "Pupsikova");
	  for (int year : {1900, 1965, 1990}) {
	    cout << person.GetFullName(year) << endl;
	  }

	  return 0;
}



