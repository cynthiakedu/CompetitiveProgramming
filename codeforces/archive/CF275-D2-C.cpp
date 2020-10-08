#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K;
set<int> S;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        if (!(x % K == 0 && S.count(x / K) > 0)) {
            S.insert(x);
        }
    }
    cout << S.size() << endl;

    return 0;
}
