#include <bits/stdc++.h>
using namespace std;
string s;
set<char> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, s);
    for (auto c : s) {
        if (c != ' ' && c != '{' && c != '}' && c != ',') {
            S.insert(c);
        }
    }
    cout << S.size() << endl;
    return 0;
}
