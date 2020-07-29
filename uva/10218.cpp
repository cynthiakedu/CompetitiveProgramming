#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
long double M, W, C;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        cin >> M >> W >> C;
        if (M == 0 && W == 0) return 0;
        long double num = 0;
        for (ll i = 0; i <= C; i += 2) num += pow(M, i) * pow(W, C - i);
        long double denom = pow(M + W, C);
        cout << num / denom << endl;
    }
    return 0;
}
