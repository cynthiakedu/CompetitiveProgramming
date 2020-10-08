#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

ll N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    ll ret = floor(log2(N - 1)) + 1;
    cout << ret << endl;

    return 0;
}
