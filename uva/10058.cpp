#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
set<string> verbs{"hate", "love", "know", "like"};
set<string> n{"tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse"};
set<string> a{"a", "the"};

bool isArticle(string x) {
    return a.count(x) > 0;
}

bool isNoun(string x) {
    return n.count(x) > 0;
}

bool isVerb(string x) {
    // cout << "isVerb" << endl;
    if (verbs.count(x) > 0) return true;
    if (x.size() == 0) return false;
    if (x[x.size() - 1] != 's') return false;
    return isVerb(x.substr(0, x.size() - 1));
}

bool isActor(vector<string> v) {
    // cout << "isActor" << endl;
    // for (auto x : v) {
    //     cout << "actor " << x << endl;
    // }
    int sz = (int)v.size();
    if (sz == 1) {
        return isNoun(v[0]);
    } else if (sz == 2) {
        return isArticle(v[0]) && isNoun(v[1]);
    }
    return false;
}

bool isActiveList(vector<string> v) {
    // cout << "isActiveList" << endl;
    // for (auto x : v) {
    //     cout << "check " << x << endl;
    // }
    if (isActor(v)) return true;
    for (int i = 1; i < (int)v.size() - 1; i++) {
        if (v[i] != "and") continue;
        vector<string> v1(v.begin(), v.begin() + i);
        vector<string> v2(v.begin() + i + 1, v.end());
        bool res = (isActiveList(v1)) && isActor(v2);
        if (res) return true;
    }
    return false;
}

bool isAction(vector<string> v) {
    // cout << "isAction" << endl;
    for (int i = 1; i < (int)v.size() - 1; i++) {
        if (!isVerb(v[i])) continue;
        vector<string> v1(v.begin(), v.begin() + i);
        vector<string> v2(v.begin() + i + 1, v.end());
        bool res = isActiveList(v1) && isActiveList(v2);
        if (res) return true;
    }
    return false;
}

bool isStatement(vector<string> v) {
    // cout << "isStatement " << endl;
    if (isAction(v)) return true;
    for (int i = 1; i < (int)v.size() - 1; i++) {
        if (v[i] != ",") continue;
        vector<string> v1(v.begin(), v.begin() + i);
        vector<string> v2(v.begin() + i + 1, v.end());
        bool res = isStatement(v1) && isAction(v2);
        if (res) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        vector<string> v;
        string x;
        while (iss >> x) {
            v.push_back(x);
        }
        cout << (isStatement(v) ? "YES I WILL" : "NO I WON'T") << endl;
    }

    return 0;
}
