#include <bits/stdc++.h>
using namespace std;

int ct = 0, X;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X;
    for (int i = 0; i < 32; i++) {
        if (X & (1 << i)) {
            ct++;
        }
    }
    cout << ct << endl;

    return 0;
}
