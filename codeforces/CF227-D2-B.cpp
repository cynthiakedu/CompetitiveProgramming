#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, arr[100005];
int rev[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        rev[x] = i;
    }
    cin >> M;
    ll a = 0, b = 0;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        a += rev[x];
        b += N - rev[x] + 1;
    }
    cout << a << " " << b << endl;
    return 0;
}
