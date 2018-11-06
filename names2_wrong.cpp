#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // изначально имя неизвестно

  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }

  return name;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;

  }
  string GetFullName(int year) {
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);

    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";

    // если неизвестно только имя
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";

    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";

    // если известны и имя, и фамилия
    } else {
      return first_name + " " + last_name;
    }
  }

  string VectorToString(vector<string>& vector, const int& year) {
	  string str;

	  for(int i = vector.size() - 1; i >= 0; --i){
		  	if(vector[i] == FindNameByYear(first_names, year) || vector[i] == FindNameByYear(last_names, year)){
		  		vector.resize(vector.size() - 1);
		  	}else{
		  		break;
		  	}
	  }
	  if(vector.size() != 0) {
		  str += " (";
		  for(int i = vector.size() - 1; i >= 0; --i){
			  str += vector[i];
			  if(i != 0){
				  str += ", ";
			  }

		  }
		  str += ")";
	  }
	  return str;
  }
  string GetFullNameWithHistory(int year) {
	  vector<string> history_first_names;
	  vector<string> history_last_names;
	  if(GetFullName(year) == "Incognito"){
		  return "Incognito";
	  }
      for(auto t : first_names) {
    	  if(t.first <= year) {
    		  history_first_names.push_back(t.second);
    	  }else{
    		  break;
    	  }
      }
      for(auto t : last_names) {
    	  if(t.first <= year) {
        	  history_last_names.push_back(t.second);
          }else{
        	  break;
          }
      }

      int x = GetFullName(year).find(" ");

      return GetFullName(year).substr(0, x) + VectorToString(history_first_names, year) +
    		  GetFullName(year).substr(x, GetFullName(year).size()) + VectorToString(history_last_names, year) ;


    }

private:
  map<int, string> first_names;
  map<int, string> last_names;
};

