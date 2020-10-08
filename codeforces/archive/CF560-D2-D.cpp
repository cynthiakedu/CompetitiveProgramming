#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s1 >> s2;
    if (s1.size() != s2.size()) {
        cout << "NO" << endl;
        return 0;
    }
    int N = s1.size();
    int a = 0, b = s1.size() - 1;
    int c = 0, d = s2.size() - 1;
    while (a < b) {
        if (s1[a] == s2[c]) {
            a++;
            c++;
        } else if (s1[b] == s2[d]) {
            b--;
            d--;
        } else if (s1[a] == s2[d]) {
            a++;
            d--;
        } else if (s1[b] == s2[c]) {
            b--;
            c++;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
