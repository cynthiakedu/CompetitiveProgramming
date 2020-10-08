#include <bits/stdc++.h>
using namespace std;
long long N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    if (N % 2 == 0) {
        cout << (N / 2) << endl;
    } else {
        cout << -((N + 1) / 2) << endl;
    }
    return 0;
}
