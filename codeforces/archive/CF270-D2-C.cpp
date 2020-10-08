#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, k;
double a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mx = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> k >> a;
        ll add = ceil(0.5 * log2(a));
        mx = max(mx, k + add);
    }
    cout << mx << endl;

    return 0;
}
