#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, M;
map<string, string> dict;

string head;

void split(string &str) {
	for (string::iterator it = str.begin(); it != str.end(); it ++) {
		if (*it == '\\') {
			str.erase(it);
			it ++;
			if (it == str.end()) break;
		}
	}
}

void read_data() {
	int state = 0;
	string first, second;
	string line;
	for (int lines = 0; lines < N; lines ++) {
		string text;
		getline(cin, text);
		line += text;
	}
	
	int loc_f = 0, loc_s = 0;
	int length = line.length();
	while (loc_f > length || (loc_f = line.find('"', loc_f)) != string::npos) {
		while (loc_f > 0 && line[loc_f - 1] == '\\') loc_f = line.find('"', loc_f + 1);
		loc_s = line.find('"', loc_f + 1);
		while (loc_s > 0 && line[loc_s - 1] == '\\') loc_s = line.find('"', loc_s + 1);
		string sub_str = line.substr(loc_f + 1, loc_s - loc_f - 1);
		
		if (state == 0) {
			first = head.empty() ? sub_str : head + "." + sub_str;
			int flg = 0;
			for (int locs = loc_s + 1; locs < length; locs ++) {
				if (line[locs] == '"') break;
				if (line[locs] == '{') {
					flg = 1;
				}
				if (line[locs] == '}' && flg >= 1) {
					flg ++;
				}
			}
			
			if (flg) {
				dict[head + (head.empty() ? sub_str : "." + sub_str)] = string("OBJECT");
				if (flg == 1)
					head += head.empty() ? sub_str : "." + sub_str;
				if (flg > 2) {
					int sub = flg - 2;
					for (int cnt = 0; cnt < sub; cnt ++) {
						if (head.find_last_of('.') == string::npos) {
							head.clear();
						}
						else {
							head.erase(head.find_last_of('.'));
						}
					}
				}
			}
			else {
				state ++;
			}
		}
		else if (state == 1) {
			second = sub_str;
			int flg = 0;
			for (int locs = loc_s + 1; locs < length; locs ++) {
				if (line[locs] == '"') break;
				if (line[locs] == '}') {
					flg ++;
				}
			}
			for (int cnt = 0; cnt < flg; cnt ++) {
				if (head.find_last_of('.') == string::npos) {
					head.clear();
				}
				else {
					head.erase(head.find_last_of('.'));
				}
			}
			
			split(first);
			split(second);
			dict[first] = "STRING " + second;
			state = 0;
			first.clear();
			second.clear();
		}
		else {
			state = 0;
		}
		loc_f = loc_s + 1;
	} 
}

void query() {
	string text;
	for (int lines = 0; lines < M; lines ++) {
		getline(cin, text);
		if (dict.find(text) == dict.end()) {
			printf("NOTEXIST\n");
		}
		else {
			printf("%s\n", dict[text].c_str());
		}
	}
}

int main() {
// #ifdef DEBUG
	freopen("JOSN.txt", "r", stdin);
// #endif
	scanf("%d%d\n", &N, &M);
	
	read_data();
	
	query();
	
	// for (map<string, string>::iterator it = dict.begin(); it != dict.end(); it ++) {
	// 	cout << it -> first << " -> " << it -> second << endl;
	// }
	

	return 0;
}
