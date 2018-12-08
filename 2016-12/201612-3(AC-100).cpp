#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int maxn  = 1e4 + 10;
const int noPri = -1;

map<string, int> category;
map<string, map<string, int> > rules;
map<string, map<string, int> > users;

int P, R, U, Q;  // priority, rule, user, query

void readPriority() {
    scanf("%d\n", &P);
    string priLine;
    for (int inc = 0; inc < P; inc ++) {
        getline(cin, priLine);
        int pivot = priLine.find(':');
        if (pivot != string::npos) { // pri
            category[priLine.substr(0, pivot)] = priLine[pivot + 1] - '0';
        }
        else {   // no pri
            category[priLine] = noPri;
        }
    }
}

void readRule() {
    scanf("%d\n", &R);
    for (int inc = 0; inc < R; inc ++) {
        int num = 0;
        string srule, spri;
        cin >> srule >> num;
        for (int idx = 0; idx < num; idx ++) {
            cin >> spri;
            int pivot = spri.find(':');
            if (pivot != string::npos) { // pri
                string priName = spri.substr(0, pivot);
                int level = spri[pivot + 1] - '0';
                if (rules[srule].find(priName) == rules[srule].end() ||
                    rules[srule][priName] < level)
                    rules[srule][priName] = level;
            }
            else {
                rules[srule][spri] = noPri;
            }
        }
    }
}

void readUser() {
    scanf("%d\n", &U);
    for (int inc = 0; inc < U; inc ++) {
        int num = 0;
        string suser, srule;
        cin >> suser >> num;
        for (int idx = 0; idx < num; idx ++) {
            cin >> srule;
            for (map<string, int>::iterator iter = rules[srule].begin();
                iter != rules[srule].end(); iter ++) {
                if (users[suser].find(iter->first) == users[suser].end() ||
                    users[suser][iter->first] < iter->second) {
                    users[suser][iter->first] = iter->second;
                }
            }
        }
    }
}

void query() {
    scanf("%d\n", &Q);
    for (int inc = 0; inc < Q; inc ++) {
        string suser, spri;
        cin >> suser >> spri;
        if (users.find(suser) == users.end()) {
            printf("false\n");
            continue;
        }
        int pivot = spri.find(':');
        if (pivot != string::npos) {
            string pri = spri.substr(0, pivot);
            int level = spri[pivot + 1] - '0';
            if (users[suser].find(pri) == users[suser].end()) {
                printf("false\n");
                continue;
            }
            if (users[suser][pri] != noPri && users[suser][pri] >= level) {
                printf("true\n");
            }
            else {
                printf("false\n");
            }
        }
        else {
            if (users[suser].find(spri) == users[suser].end()) {
                printf("false\n");
                continue;
            }
            if (users[suser][spri] == noPri)
                printf("true\n");
            else
                printf("%d\n", users[suser][spri]);
        }
    }
}

int main() {

    readPriority();

    readRule();

    readUser();

    query();

    return 0;
}