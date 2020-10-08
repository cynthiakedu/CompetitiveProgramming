#include <bits/stdc++.h>
using namespace std;
int N, M;
set<int> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ok = true;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a, b;
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == 'G') a = j;
            if (c == 'S') b = j;
        }
        if (a > b) ok = false;
        S.insert(b - a);
    }
    if (!ok) {
        cout << -1 << endl;
    } else {
        cout << (S.size()) << endl;
    }

    return 0;
}
