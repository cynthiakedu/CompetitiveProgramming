#include <bits/stdc++.h>
using namespace std;
int N, mx = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
    }
    cout << mx << endl;

    return 0;
}
