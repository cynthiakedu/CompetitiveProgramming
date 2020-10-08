#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    if (N <= 5) {
        cout << -1 << endl;
    } else {
        cout << 1 << " " << 2 << endl;
        for (int i = 3; i <= (N + 3) / 2; i++) cout << "1 " << i << "\n";
        for (int i = (N + 5) / 2; i <= N; i++) cout << "2 " << i << "\n";
    }

    for (int i = 2; i <= N; i++) cout << 1 << " " << i << "\n";

    return 0;
}
