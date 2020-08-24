#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int K;
int ct = 0;

vector<int> v1, v2;
vector<ii> ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    if (K % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    int t = 0;
    while (1) {
        t++;
        cout << "try t " << t << endl;
        if ((1 + (K - 2) * t) % K == 0) {
            break;
        }
    }
    cout << "t " << t << endl;
    for (int i = 1; i <= t; i++) {
        ans.push_back({ct + 1, ct + K});
        for (int j = 1; j <= K - 2; j++) {
            ans.push_back({ct + 1, ct + 1 + j});
            v1.push_back(ct + 1 + j);
        }
        ct += K - 1;
    }
    v1.push_back(ct);
    cout << "ans1 " << ans.size() << endl;
    // cout << "ct " << ct << endl;
    int x = (1 + (K - 2) * t) / K;
    for (int i = 1; i <= x * (K - 1); i++) {
        for (int j = 1; j <= K; j++) {
            v2.push_back(ct + j);
            for (int k = j + 1; k <= K; k++) {
                ans.push_back({ct + j, ct + k});
            }
        }
        ct += K;
    }
    cout << "ans2 " << ans.size() << endl;
    // cout << "ct " << ct << endl;
    int sec = ct + 1;
    int cum = 0;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < K - 1; j++) {
            ans.push_back({v1[i], v2[cum + j]});
        }
        cum += K - 1;
    }
    cout << "ans3 " << ans.size() << endl;
    cout << "ANS" << endl;
    cout << 2 * ct << " " << 2 * (int)ans.size() + 1 << endl;
    // for (auto p : ans) {
    //     cout << p.first << " " << p.second << endl;
    //     cout << ct + p.first << " " << p.second << endl;
    // }
    // cout << 1 << " " << ct + 1 << endl;

    return 0;
}
