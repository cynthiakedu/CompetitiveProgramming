#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
ll a[mxN + 5], b[mxN + 5];
int N, M, Q;
ll aSum = 0, bInit;
vector<ll> bSum;

void findMin() {
    ll ret = LLONG_MAX;
    int pos = (int)(lower_bound(bSum.begin(), bSum.end(), aSum) - bSum.begin());
    if (pos < bSum.size()) {
        ret = min(ret, abs(aSum - bSum[pos]));
    }
    if (pos > 0) {
        ret = min(ret, abs(aSum - bSum[pos - 1]));
    }
    cout << ret << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        aSum += (i % 2 ? 1 : -1) * a[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> b[i];
        if (i <= N) {
            bInit += (i % 2 ? 1 : -1) * b[i];
        }
    }
    bSum.push_back(bInit);
    for (int i = N + 1; i <= M; i++) {
        bInit = -bInit + ((N % 2 == 1 ? 1 : -1) * b[i] + b[i - N]);
        bSum.push_back(bInit);
    }
    sort(bSum.begin(), bSum.end());
    findMin();

    for (int i = 0, l, r, x; i < Q; i++) {
        cin >> l >> r >> x;
        if (l % 2 == r % 2) {
            aSum += (l % 2 == 1 ? 1 : -1) * x;
        }
        findMin();
    }
    return 0;
}
