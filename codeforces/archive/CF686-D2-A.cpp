#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll X, d = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        char c;
        ll a;
        cin >> c >> a;
        if (c == '+') {
            X += a;
        } else {
            if (a <= X) {
                X -= a;
            } else {
                d++;
            }
        }
    }
    cout << X << " " << d << endl;

    return 0;
}
