#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define MOD 1000000007
int N, M;
set<char> arr[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[j].insert(s[j]);
        }
    }
    ll ans = 1;
    for (int i = 0; i < M; i++) {
        ans = (ans * (ll)arr[i].size()) % MOD;
    }
    cout << ans << endl;

    return 0;
}
