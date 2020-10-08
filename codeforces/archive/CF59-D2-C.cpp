#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int K;
string s;
bool ok = true;
int seen[30];
int n;
vector<int> v1, v2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> s;
    n = (int)s.size();
    for (int i = 0; i <= (n - 1) / 2; i++) {
        if (s[i] == '?' && s[n - 1 - i] == '?') {
            v2.push_back(i);
        } else if (s[i] == '?') {
            char c = s[n - 1 - i];
            s[i] = c;
            seen[c - 'a'] = 1;
        } else if (s[n - 1 - i] == '?') {
            seen[s[i] - 'a'] = 1;
            s[n - 1 - i] = s[i];
        } else if (s[i] != s[n - 1 - i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        } else {
            seen[s[i] - 'a'] = 1;
        }
    }
    for (int i = 0; i < K; i++) {
        if (!seen[i]) {
            v1.push_back(i);
        }
    }
    if (v1.size() > v2.size()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int s1 = v1.size(), s2 = v2.size();

    for (int i = 0; i < s2; i++) {
        int idx = v2[i], c = 0;
        if (i >= s2 - s1) {
            c = v1[i - (s2 - s1)];
        } else {
            c = 0;
        }
        s[idx] = s[n - 1 - idx] = (char)(c + 'a');
    }

    cout << s << endl;

    return 0;
}
