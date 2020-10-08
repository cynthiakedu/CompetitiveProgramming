#include <bits/stdc++.h>
using namespace std;
int N;
string S;
int ct[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> S;
    for (auto c : S) {
        char c1 = tolower(c);
        ct[c1 - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (!ct[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
