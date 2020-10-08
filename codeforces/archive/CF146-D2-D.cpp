#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int a1, a2, a3, a4;  // 4, 7, 47, 74

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a1 >> a2 >> a3 >> a4;
    if (abs(a3 - a4) > 1 || min(a1, a2) < max(a3, a4)) {
        cout << -1 << endl;
        return 0;
    }
    string s = "";
    if (a3 == a4) {
        int x = a3;
        if (a1 >= a4 + 1) {
            for (int i = 0; i < a1 - (x + 1); i++) {
                s += "4";
            }
            for (int i = 1; i <= x; i++) {
                s += "47";
            }
            for (int i = 0; i < a2 - x; i++) {
                s += "7";
            }
            s += "4";

        } else if (a2 >= a4 + 1) {
            s += "74";
            for (int i = 0; i < a1 - x; i++) {
                s += "4";
            }
            for (int i = 1; i < x; i++) {
                s += "74";
            }
            for (int i = 0; i < a2 - x; i++) {
                s += "7";
            }
        } else {
            cout << -1 << endl;
            return 0;
        }
        cout << s << endl;
        return 0;
    }
    if (a3 == a4 + 1) {
        int x = a4;
        for (int i = 0; i < a1 - (x + 1); i++) {
            s += "4";
        }
        for (int i = 1; i <= x + 1; i++) {
            s += "47";
        }

        for (int i = 0; i < a2 - (x + 1); i++) {
            s += "7";
        }
        cout << s << endl;
        return 0;
    }
    if (a4 == a3 + 1) {
        int x = a3;
        s += "7";
        for (int i = 0; i < a1 - (x + 1); i++) {
            s += "4";
        }
        for (int i = 1; i <= x; i++) {
            s += "47";
        }
        for (int i = 0; i < a2 - (x + 1); i++) {
            s += "7";
        }
        s += "4";

        cout << s << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
