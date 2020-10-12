#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MXN = 200005;
int N, M, L[MXN], R[MXN], mx[MXN], mn;
ll dp1[MXN], dp2[MXN], ans; //ct, sum
vector<int> v_l[MXN], v_r[MXN];
multiset<int> S[2];

set<int> all[2];
ll fw[2][2][MXN]; //(even, odd) * (ct, sum) * (idx)
void upd(int par, int tp, int k, int v) {
    for (; k < MXN; k += k & (-k)) fw[par][tp][k] += v;
}
ll rsq(int par, int tp, int b) {
    ll ret = 0;
    for (; b; b -= b & (-b)) ret += fw[par][tp][b];
    return ret;
}
ll rsq(int par, int tp, int a, int b) {
    if (a > b) return 0;
    return rsq(par, tp, b) - (a == 1 ? 0 : rsq(par, tp, a - 1));
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    // freopen("output.txt", "r", stdin);
    // freopen("output2.txt", "w", stdout);

    cin >> N >> M;
    for (int i = 1, x, y; i <= N; ++i) {
        cin >> x >> y;
        L[i] = x, R[i] = y;
        mx[x] = max(mx[x], y);
        v_l[x].push_back(i), v_r[y].push_back(i);
    }
    mn = M;
    for (int i = 1; i <= M; ++i) mx[i] = max(mx[i], mx[i - 1]);

    for (int i = M; i >= 1; --i) {
        int a = (i & 1), b = 1 - (i & 1);

        for (int id : v_r[i]) S[R[id] & 1].insert(R[id]);
        all[a].insert(i), upd(a, 0, i, 1), upd(a, 1, i, i);

        //Get answer
        if (!(S[a].size() || S[b].size())) {
            dp1[i] = dp1[i + 1], dp2[i] = dp1[i + 1] + dp2[i + 1];
        } else {
            int re = min(mn, S[b].size() ? (*S[b].begin()) - 1 : INT_MAX);
            int le = min(re, mx[i]);

            ll ct = rsq(a, 0, i, le);
            dp1[i] += ct;
            dp2[i] += rsq(a, 1, i, le) - (i - 1) * ct;

            ct = rsq(0, 0, le + 1, re) + rsq(1, 0, le + 1, re);
            dp1[i] += ct;
            dp2[i] += rsq(0, 1, le + 1, re) + rsq(1, 1, le + 1, re) - (i - 1) * ct;
        }
        ans += dp2[i];
        // cout << "dp " << i << " " << dp1[i] << " " << dp2[i] << "\n";

        //Process interval starts
        for (int id : v_l[i]) {
            if ((R[id] - i) & 1) mn = min(mn, R[id] - 1);
            S[R[id] & 1].erase(S[R[id] & 1].find(R[id]));

            while (true) {
                set<int>::iterator it = all[b].lower_bound(i);
                if (it == all[b].end() || *it > R[id]) break;
                int t = *it;
                upd(b, 0, t, -1), upd(b, 1, t, -t);
                all[b].erase(it);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}