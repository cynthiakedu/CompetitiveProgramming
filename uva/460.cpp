#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int l1, r1, d1, u1;
        int l2, r2, d2, u2;
        cin >> l1 >> d1 >> r1 >> u1;
        cin >> l2 >> d2 >> r2 >> u2;
        int l = max(l1, l2), r = min(r1, r2);
        int d = max(d1, d2), u = min(u1, u2);
        if (l >= r || d >= u) {
            cout << "No Overlap" << endl;
        } else {
            cout << l << " " << d << " " << r << " " << u << endl;
        }
        if (i != N - 1) {
            cout << endl;
        }
    }

    return 0;
}