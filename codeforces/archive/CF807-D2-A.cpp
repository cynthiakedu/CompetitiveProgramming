#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    bool ok = false;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if (x != y) ok = true;
        v.push_back({x, y});
    }
    if (ok) {
        cout << "rated" << endl;
        return 0;
    }
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[i - 1]) {
            cout << "unrated" << endl;
            return 0;
        }
    }
    cout << "maybe" << endl;

    return 0;
}
