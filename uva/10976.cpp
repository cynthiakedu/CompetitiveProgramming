#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> K) {
        vector<ii> ans;
        int s = K * K;
        for (int i = 1; i <= K; i++) {
            if ((K * K) % i == 0) {
                ans.push_back({K * K / i + K, i + K});
            }
        }
        cout << ans.size() << endl;
        for (auto p : ans) {
            cout << "1/" << K << " = "
                 << "1/" << p.first << " + 1/" << p.second << endl;
        }
    }

    return 0;
}
