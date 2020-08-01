#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD 1000000007

ll powmod(ll a, ll b, ll m) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2, m);
    return (((z * z) % m) * (b % 2 == 1 ? a : 1)) % m;
}

// Complete the towerColoring function below.
int towerColoring(int n) {
    ll x = powmod(3, n, MOD - 1);
    ll ans = powmod(3, x, MOD);
    return (int)ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = towerColoring(n);

    fout << result << "\n";

    fout.close();

    return 0;
}