#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MXN = 200005;
int N, M, arr[MXN][2], mx1[2][MXN], mx2[2][MXN];
int mnGood;
ll dp1[MXN], dp2[MXN], ans; //ct, sum
vector<int> v[2][2][MXN]; //(even, odd) * (add, sub) * (idx)
set<ii> S[2];

set<int> tolerate[3];
ll fw[2][2][3][MXN]; //(parity of index) * (ct, sum) * (even, odd, either) * (idx)
void update(int p, int i, int j, int k, int v) {
    for (; k < MXN; k += k & (-k)) {
        fw[p][i][j][k] += v;
    }
}
ll rsq(int p, int i, int j, int b) {
    ll ret = 0;
    for (; b; b -= b & (-b)) ret += fw[p][i][j][b];
    return ret;
}
ll rsq(int p, int i, int j, int a, int b) {
    if (a > b) return 0;
    return rsq(p, i, j, b) - (a == 1 ? 0 : rsq(p, i, j, a - 1));
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    // int s = clock();
    // freopen("output.txt", "r", stdin);
    // freopen("output2.txt", "w", stdout);

    cin >> N >> M;
    for (int i = 1, x, y; i <= N; ++i) {
        cin >> x >> y;
        arr[i][0] = x, arr[i][1] = y;
        mx1[y & 1][x] = max(mx1[y & 1][x], y);
        v[y & 1][0][y].push_back(i);
        v[y & 1][1][x].push_back(i);
    }
    mnGood = M;
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < 2; ++j) {
            mx2[j][i] = max(mx2[j][i - 1], mx1[j][i]);
        }
    }

    for (int i = M; i >= 1; --i) {
        // cout << "START " << i << "\n";
        int a = (i & 1), b = 1 - (i & 1);

        for (int x : v[a][0][i]) S[a].insert({ arr[x][1], x });
        update(a, 0, 2, i, 1), update(a, 1, 2, i, i);
        tolerate[2].insert(i);

        //Get answer
        if (max(mx2[0][i], mx2[1][i]) < i) {
            dp2[i] = dp1[i + 1] + dp2[i + 1];
            dp1[i] = dp1[i + 1];
        } else {
            int mnGoodTmp = mnGood;
            // int  fe =  mx2[a][i] >= i ? mx2[a][i] : M + 1;
            int  fe = max(mx2[0][i], mx2[1][i]);

            if (S[b].size()) mnGoodTmp = min(mnGoodTmp, S[b].begin()->first - 1);
            fe = min(fe, mnGoodTmp);
            // cout << "Ranges " << i << " " << fe << " " << mnGoodTmp << "\n";

            ll ct = rsq(a, 0, a, i, fe);
            dp1[i] += ct, dp2[i] += rsq(a, 1, a, i, fe) - (i - 1) * ct;
            ct = rsq(a, 0, 2, i, fe);
            dp1[i] += ct, dp2[i] += rsq(a, 1, 2, i, fe) - (i - 1) * ct;

            for (int j = 0; j < 2; ++j) {
                ct = rsq(j, 0, j, fe + 1, mnGoodTmp);
                dp1[i] += ct, dp2[i] += rsq(j, 1, j, fe + 1, mnGoodTmp) - (i - 1) * ct;
            }
            for (int k = 0; k < 2; ++k) {
                ct = rsq(k, 0, 2, fe + 1, mnGoodTmp);
                dp1[i] += ct, dp2[i] += rsq(k, 1, 2, fe + 1, mnGoodTmp) - (i - 1) * ct;
            }
        }
        ans += dp2[i];
        // cout << "dp " << i << " " << dp1[i] << " " << dp2[i] << "\n";

        //Process interval starts
        for (int j = 0; j < 2; ++j) {
            for (int x : v[j][1][i]) {
                if ((arr[x][1] - arr[x][0]) & 1) mnGood = min(mnGood, arr[x][1] - 1);
                S[j].erase({ arr[x][1], x });
                int s = arr[x][0] & 1;

                set<int> tmp, tmp2;
                set<int>::iterator it = tolerate[1 - s].lower_bound(arr[x][0]);
                for (; it != tolerate[1 - s].end() && *it <= arr[x][1]; ++it) {
                    tmp.insert(*it);
                }
                for (int t : tmp) {
                    tolerate[1 - s].erase(t);
                    update(t & 1, 0, 1 - s, t, -1), update(t & 1, 1, 1 - s, t, -t);
                }

                it = tolerate[2].lower_bound(arr[x][0]);
                for (; it != tolerate[2].end() && *it <= arr[x][1]; ++it) {
                    tmp2.insert(*it);
                }
                for (int t : tmp2) {
                    tolerate[2].erase(t);
                    update(t & 1, 0, 2, t, -1), update(t & 1, 1, 2, t, -t);
                    tolerate[s].insert(t);
                    update(t & 1, 0, s, t, +1), update(t & 1, 1, s, t, +t);
                }
            }
        }
    }
    cout << ans << "\n";
    // fprintf(stderr, "time: %.3lf s\n", (double)(clock() - s) / CLOCKS_PER_SEC);

    return 0;
}
