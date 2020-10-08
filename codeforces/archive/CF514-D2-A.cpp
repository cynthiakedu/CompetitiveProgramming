#include <bits/stdc++.h>
using namespace std;
string x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x;
    string t = "";
    for (int i = 0; i < x.size(); i++) {
        int y = x[i] - '0';
        if (y >= 5) {
            if (y == 9 && i == 0) {
                t += x[i];
            } else {
                t += (char)(9 - y + '0');
            }
        } else {
            t += x[i];
        }
    }
    cout << t << endl;

    return 0;
}
