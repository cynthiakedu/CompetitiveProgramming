#include <bits/stdc++.h>
using namespace std;
int N;
map<string, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        m[s]++;
    }
    int mx = 0;
    string team;
    for (auto p : m) {
        if (p.second > mx) {
            mx = p.second;
            team = p.first;
        }
    }
    cout << team << endl;

    return 0;
}
