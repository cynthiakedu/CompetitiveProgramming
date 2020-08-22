#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int b[100005];
string s;
int N;
map<int, int> m;

void preprocess() {
    int i = 0, j = -1;
    b[0] = -1;
    while (i < N) {
        while (j >= 0 && s[j] != s[i]) j = b[j];
        i++;
        j++;
        b[i] = j;
        m[j]++;
    }
}

void search() {
    int i = 0, j = 0;
    while (i < N) {
        cout << "i j " << i << " " << j << " " << s[j] << " " << s[i] << endl;
        while (j >= 0 && s[j] != s[i]) j = b[j];
        i++;
        j++;
        cout << "search " << i << " " << j << endl;
        if (j > 0) {
            m[j]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    N = s.size();
    preprocess();

    int j = s.size();
    vector<int> v;
    while (true) {
        v.push_back(j);
        j = b[j];
        if (j == 0) break;
    }
    map<int, int> m2;
    int cum = 0;
    for (auto x : v) {
        cum += m[x];
        m2[x] = cum;
    }

    cout << m2.size() << endl;
    for (auto x : m2) {
        if (x.first == 0) continue;
        cout << x.first << " " << x.second + 1 << endl;
    }

    return 0;
}
