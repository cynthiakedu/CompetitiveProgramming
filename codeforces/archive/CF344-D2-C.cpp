#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll A, B;

ll ct(ll a, ll b) {
    if (b > a) swap(a, b);
    if (b == 1) return a;
    ll s = a / b;
    return s + ct(a % b, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B;
    cout << ct(A, B) << endl;
    return 0;
}
