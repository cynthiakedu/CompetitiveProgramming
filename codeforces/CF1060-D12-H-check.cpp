#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MXN = 100005;
ll MOD = 1e9 + 7;
bool debug = false;

ll d = 4, p = 7, arr[5005];

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return z * z % p * (b % 2 ? a : 1) % p;
}
void chkBd(int x) {
    if (x > 5000) {
        cout << "Out of bound \n";
        exit(0);
    }
}

void prtArr(int idx) {
    cout << "arr[" << idx << "] = " << arr[idx] << "\n";
}

vector<string> v;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("codeforces/out.txt", "r", stdin);

    int a, b, c;
    int ct = 0;
    string s;
    while (getline(cin, s)) { v.push_back(s); }
    if (ct > 5000) { cout << "TOO MANY OPERATIONS!\n"; return 0; }

    char type;
    int ans[2] = {};
    for (ll x = 0; x < p; x++) {
        for (ll y = 0; y < p; y++) {
            arr[1] = x, arr[2] = y;
            for (int i = 3; i <= 5000; i++) arr[i] = 1;

            for (string s : v) {
                istringstream iss(s);
                iss >> type;
                if (type == '+') {
                    iss >> a >> b >> c;
                    chkBd(a), chkBd(b), chkBd(c);
                    arr[c] = (arr[a] + arr[b]) % p;
                }
                else if (type == '^') {
                    iss >> a >> b;
                    chkBd(a), chkBd(b);
                    arr[b] = powmod(arr[a], d);
                }
                else {
                    iss >> a;
                    chkBd(a);
                    ans[(int)(arr[a] == (x * y) % p)]++;
                    // cout << "x y " << x << " " << y << "\n";
                    // cout << "Result is " << arr[a] << "\n";
                    // cout << "x * y = " << x * y % p << "\n";
                }
            }

        }
    }
    cout << "CORRECT/INCORRECT " << ans[1] << " " << ans[0] << "\n";


    return 0;
}
