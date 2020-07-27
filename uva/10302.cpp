#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N) {
        cout << ((N * (N + 1) / 2) * (N * (N + 1) / 2)) << endl;
    }

    return 0;
}
