#include <bits/stdc++.h>
using namespace std;
int N;

set<char> d, nd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (i == j || (i + j == N - 1)) {
                d.insert(c);
            } else {
                nd.insert(c);
            }
        }
    }
    if (d.size() > 1 || nd.size() > 1) {
        cout << "NO" << endl;
    } else {
        char a = *d.begin();
        char b = *nd.begin();
        if (a == b) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
