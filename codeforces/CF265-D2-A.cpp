#include <bits/stdc++.h>
using namespace std;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    int idx = 0;
    for (auto c : s2) {
        if (s1[idx] == c) idx++;
    }
    cout << idx + 1 << endl;

    return 0;
}
