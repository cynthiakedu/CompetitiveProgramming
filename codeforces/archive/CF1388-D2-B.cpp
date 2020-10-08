#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        int amt = (N + 3) / 4;
        int rest = N - amt;
        for (int i = 0; i < rest; i++) cout << 9;
        for (int i = 0; i < amt; i++) cout << 8;
        cout << endl;
    }
    return 0;
}
