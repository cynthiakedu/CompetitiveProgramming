#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
map<string, int> trie[40000];
int ct = 1;

void insertPath(vector<string> v) {
    int idx = 0;
    for (auto x : v) {
        if (trie[idx][x] == 0) {
            trie[idx][x] = ct++;
        }
        idx = trie[idx][x];
    }
}

void print(int idx, int depth = 0) {
    for (auto p : trie[idx]) {
        for (int i = 0; i < depth; i++) cout << " ";
        cout << p.first << endl;
        print(p.second, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N) {
        for (int i = 0; i < 40000; i++) {
            trie[i].clear();
        }
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            vector<string> v;
            string x;
            replace(s.begin(), s.end(), '\\', ' ');
            std::istringstream iss(s);
            while (iss >> x) {
                v.push_back(x);
            }
            insertPath(v);
        }
        print(0);
        cout << endl;
    }

    return 0;
}
