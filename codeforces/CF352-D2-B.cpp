#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N;
map<int, vector<int>> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        m[x].push_back(i);
    }
    vector<ii> ans;
    for (auto p : m) {
        vector<int> v = p.second;
        if (v.size() == 1) {
            ans.push_back(ii(p.first, 0));
        } else {
            int diff = v[1] - v[0];
            bool ok = true;
            for (int i = 1; i < v.size(); i++) {
                int s = v[0] + i * diff;
                if (s != v[i]) ok = false;
            }
            if (ok) ans.push_back(ii(p.first, diff));
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
