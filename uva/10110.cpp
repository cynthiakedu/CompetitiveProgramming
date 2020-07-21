#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N;
        if (N == 0) return 0;
        ll i = sqrt(N);
        if (i * i == N) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
