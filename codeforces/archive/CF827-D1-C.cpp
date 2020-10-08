#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
int ft[15][15][5][mxN + 5];
int Q;
string S;
map<char, int> m = {{'A', 0}, {'T', 1}, {'G', 2}, {'C', 3}};

int rsq(int mod, int l, int t, int b) {
    int sum = 0;
    for (; b; b -= (b & (-b))) sum += ft[mod][l][t][b];
    return sum;
}
int rsq(int mod, int l, int t, int a, int b) {
    return rsq(mod, l, t, b) - (a == 1 ? 0 : rsq(mod, l, t, a - 1));
}

void adjust(int mod, int l, int t, int k, int v) {
    for (; k < mxN + 5; k += (k & (-k))) {
        ft[mod][l][t][k] += v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    for (int i = 1; i <= (int)S.size(); i++) {
        char c = S[i - 1];
        for (int j = 1; j < 11; j++) {
            int i1 = i % j;
            adjust(j, i1, m[c], i, 1);
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type, x, l, r;
        cin >> type;
        if (type == 1) {
            char c;
            cin >> x >> c;
            char c1 = S[x - 1];
            for (int j = 1; j <= 10; j++) {
                adjust(j, x % j, m[c], x, 1);
                adjust(j, x % j, m[c1], x, -1);
            }
            S[x - 1] = c;
        } else {
            cin >> l >> r;
            string tmp;
            cin >> tmp;
            int n = tmp.size();
            int ans = 0;
            for (int j = 1; j <= n; j++) {
                char c = tmp[j - 1];
                int y = (l + j - 1) % n;
                ans += rsq(n, y, m[c], l, r);
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
