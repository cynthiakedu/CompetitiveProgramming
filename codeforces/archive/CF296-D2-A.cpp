#include <bits/stdc++.h>
using namespace std;
int N;
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    for (auto p : m) {
        if (p.second > (N + 1) / 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
