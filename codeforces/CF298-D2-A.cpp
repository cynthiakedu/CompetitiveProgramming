#include <bits/stdc++.h>
using namespace std;

int N;
string S;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> S;
    int l = 0, r = 0;
    int s = 0, e = 0;
    for (int i = 0; i < N; i++) {
        if (s == 0 && S[i] != '.') s = i;
        if (s != 0 && S[i] == '.' && e == 0) e = i;
        if (S[i] == 'R') r++;
    }
    if (r == e - s) {
        cout << s + 1 << " " << e + 1 << endl;
    } else if (r == 0) {
        cout << e << " " << s << endl;
    } else {
        cout << s + 1 << " " << s + r << endl;
    }

    return 0;
}
