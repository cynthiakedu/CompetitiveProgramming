#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        cin >> N;
        if (N == 0) return 0;

        cout << N - 1 << "/" << N << endl;
    }

    return 0;
}
