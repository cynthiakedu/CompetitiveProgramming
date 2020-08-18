#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>
int N;
vector<pair<pair<int, int>, int>> v;
vector<ll> ans1;
ll cum;

bool cmp(pair<ii, int> a, pair<ii, int> b) {
    ii a1 = a.first, b1 = b.first;
    // cout << "compare " << a1.first << " " << a1.second << " " << b1.first << " " << b1.second << endl;
    // cout << (a1.first * b1.second < b1.first * a1.second) << endl;
    return a1.first * b1.second < b1.first * a1.second;
}
ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        ll k, b;
        cin >> k >> b;
        if (k == 0) continue;
        b = -b;
        int x = k, y = 0;
        if (k > 0) swap(x, y);
        if (k < 0) {
            b = -b;
            k = -k;
        }
        ll g = gcd(abs(k), abs(b));
        v.push_back({{INT_MIN, 1}, x});
        v.push_back({{b / g, k / g}, y - x});
    }
    sort(v.begin(), v.end(), cmp);
    int idx = 0;
    while (idx < v.size()) {
        int j = idx;
        // cout << "START " << endl;
        while (j < v.size() && v[j].first == v[idx].first) {
            // cout << "process " << v[j].first.first << " " << v[j].first.second << " " << v[j].second << endl;
            cum += v[j].second;
            j++;
        }
        // cout << "cum " << cum << endl;
        ans1.push_back(cum);
        idx = j;
    }
    ll ans2 = 0;
    for (int i = 0; i < (int)ans1.size() - 1; i++) {
        if (ans1[i] != ans1[i + 1]) ans2++;
    }
    cout << ans2 << endl;

    return 0;
}
