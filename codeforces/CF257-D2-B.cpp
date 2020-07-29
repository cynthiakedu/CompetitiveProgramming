#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int b = min(m, n);
    cout << n + m - 1 - b << " " << b << endl;

    return 0;
}
