#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, a, b, c, fst;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        s1 += "0";
        s2 += (i == 0 ? "1" : "0");
    }
    cout << "? " << s1 << endl;
    cin >> a;
    cout << "? " << s2 << endl;
    cin >> b;
    fst = (b > a ? 0 : 1);

    string s = "";
    int l = 2, r = N;
    int temp;
    for (int i = 0; i < N; i++) {
        s += to_string(fst);
    }
    cout << "? " << s << endl;
    cin >> temp;

    while (l < r) {
        int m = (l + r) / 2;
        s = to_string(fst);
        int x;
        for (int i = 2; i <= N; i++) {
            if (l <= i && i <= m)
                s += to_string(1 - fst);
            else
                s += to_string(fst);
        }
        cout << "? " << s << endl;
        cin >> x;
        if (x == temp + (m - l + 1)) {
            l = m + 1;
        } else {
            r = m;
        }
        // temp = x;
    }
    cout << "! " << (fst == 0 ? 1 : l) << " " << (fst == 0 ? l : 1) << endl;
    return 0;
}
