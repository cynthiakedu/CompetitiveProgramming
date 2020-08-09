#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s;
int mn = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - 'a' > mn) {
            cout << "Ann" << endl;
        } else {
            cout << "Mike" << endl;
        }
        mn = min(mn, s[i] - 'a');
    }

    return 0;
}
