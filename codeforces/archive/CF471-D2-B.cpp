#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
map<int, vector<int>> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1, h; i <= N; i++) {
        cin >> h;
        m[h].push_back(i);
    }
    int ct2 = 0, ct3 = 0;
    vector<int> ans[3];
    vector<int> v1, v2, v3;
    for (auto p : m) {
        if (p.second.size() == 2) {
            int a = p.second[0], b = p.second[1];
            if (ct2 == 1) {
                ans[0].push_back(a);
                ans[0].push_back(b);
                ans[1].push_back(b);
                ans[1].push_back(a);
                ans[2].push_back(a);
                ans[2].push_back(b);
            } else {
                ans[0].push_back(a);
                ans[0].push_back(b);
                ans[1].push_back(a);
                ans[1].push_back(b);
                ans[2].push_back(b);
                ans[2].push_back(a);
            }
        } else {
            for (int j = 0; j < p.second.size(); j++) {
                for (int i = 0; i < 3; i++) {
                    ans[i].push_back(p.second[(j + i) % p.second.size()]);
                }
            }
        }

        if (p.second.size() >= 3) ct3++;
        if (p.second.size() == 2) ct2++;
    }
    if (ct3 == 0 && ct2 <= 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << (j == N - 1 ? "\n" : " ");
        }
    }

    return 0;
}
