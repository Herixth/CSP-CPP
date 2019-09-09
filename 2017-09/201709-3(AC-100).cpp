#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N, M;

string pub_str;
bool flg_empty = false;
set<string> tar_set;
set<string> empty_object;

void read_inf() {
	string line = "";
	bool phase = false; // 0-> no key and value, 1-> key and no value;
	string key = "";
	for (int inc = 0; inc < N; inc ++) {
		getline(cin, line);
		int len = line.length();
		// for every index in line(string)
		for (int idx = 0; idx < len; idx ++) {
			if (line[idx] == '}' && !pub_str.length())
				continue;
			if (line[idx] == '{' && !phase) 
				continue;
			if (line[idx] == '{') {
				pub_str += key + string(".");
				phase = false;
				flg_empty = true;
			}
			if (line[idx] == '}') {
				if (flg_empty) {
					tar_set.insert(pub_str);
					empty_object.insert(pub_str);
				}
				int pub_len = pub_str.length();
				int dot_idx = pub_str.find_last_of('.', pub_len - 2) + 1;
				pub_str.erase(dot_idx);
			}
			if (line[idx] == '"') {
				flg_empty = false;
				string mid = "";
				for (++idx; idx < len; idx ++) {
					if (line[idx] == '\\')
						mid += line[++idx];
					else if (line[idx] == '"')
					 	break;
					else
						mid += line[idx];
				}
				if (phase) {
					tar_set.insert(pub_str + key + string(".") + mid);
				}
				else {
					key = mid;
				}
				phase = !phase;
			}
		}
	}
}

void query() {
	string line;
	for (int idx = 0; idx < M; idx ++) {
		getline(cin, line);
		line += ".";
		string fetch = "";
		int counter = 0;
		set<string>::iterator iter;
    	for (iter = tar_set.begin(); iter != tar_set.end(); iter++) {
    		if (!(*iter).find(line.c_str(), 0)) {
    			if (!counter) {
    				fetch = *iter;
				}
				counter++;
			}
		}
		if (counter == 0) {
			printf("NOTEXIST\n");
		}
		else if (counter > 1) {
			printf("OBJECT\n");
		}
		else {
			counter = 0;
			set<string>::iterator itera;
	    	for (itera = empty_object.begin(); itera != empty_object.end(); itera++) {
	    		if (!(*itera).find(line.c_str(), 0)) {
					counter++;
					break;
				}
			}
			if (counter) {
				printf("OBJECT\n");
			}
			else {
				counter = 0;
				int lens = line.length();
				string vals = fetch.substr(lens);
				if (vals.find('.') == string::npos) {
					printf("STRING %s\n", vals.c_str());
				}
				else {
					printf("OBJECT\n");
				}
			}
		}
	}
}

int main() {
	freopen("./JOSN.txt", "r", stdin);
	scanf("%d %d\n", &N, &M);
	
	read_inf();
	
	query();
	return 0;
}
