// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// ll N, D;

// ll p(ll a, ll b) {
//     if (b == 0) return 1;
//     ll z = p(a, b / 2);
//     return z * z * (b % 2 == 1 ? a : 1);
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> N >> D;
//     ll ans;

//     ll dig = 0, N1 = N;
//     string ns = to_string(N);
//     while (N1 > 0) {
//         dig++;
//         N1 /= 10;
//     }
//     for (int i = dig - 1; i >= 0; i--) {
//         ll need = (N % p(10, i)) + 1;
//         cout << " need " << need << endl;
//         bool ok = true;
//         for (int j = )
//         if (need <= D) {
//             ans = N - need;
//             break;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }
