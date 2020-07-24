#include <bits/stdc++.h>
using namespace std;
int N;
set<int> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        S.insert(x);
    }
    if (S.size() < 3) {
        cout << "YES" << endl;
    } else if (S.size() > 3) {
        cout << "NO" << endl;
    } else {
        vector<int> v;
        for (auto x : S) v.push_back(x);
        if (v[0] + v[2] == 2 * v[1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
