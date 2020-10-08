#include <bits/stdc++.h>
using namespace std;
int N, A, B;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> A >> B;
    vector<int> ans;
    int g = gcd(A, B);
    A /= g;
    B /= g;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        if (A >= B)
            ans.push_back(0);
        else {
            cout << x % B << " " << (B + A - 1) / A << endl;
            ans.push_back((x % B) % ((B + A - 1) / A));
        }
    }
    for (int i = 0; i < N; i++) cout << ans[i] << (i == (N - 1) ? "\n" : " ");

    return 0;
}
