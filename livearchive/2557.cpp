#include <bits/stdc++.h>
using namespace std;
int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        cout << floor(sqrt(N)) << endl;
    }
    return 0;
}
