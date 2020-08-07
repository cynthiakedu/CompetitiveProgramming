#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;

vector<int> v, h;
int ans = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            h.push_back(b);
        }
    }
    v.push_back(1000000000);
    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    ans = h.size();
    for (int i = 0; i < v.size(); i++) {
        int x = v[i];
        int pos = (int)(lower_bound(h.begin(), h.end(), x) - h.begin());
        ans = min(ans, i + (int)h.size() - pos);
    }
    cout << ans << endl;

    return 0;
}
