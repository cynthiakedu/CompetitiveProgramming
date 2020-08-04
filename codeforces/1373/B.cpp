#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> s;
        int a = 0, b = 0;
        for (auto c : s) {
            if (c == '0')
                a++;
            else
                b++;
        }
        cout << ((min(a, b) % 2 == 1) ? "DA" : "NET") << endl;
    }

    return 0;
}
