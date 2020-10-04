#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MXN = 100005;
ll MOD = 1e9 + 7;
bool debug = false;

ll d, p, bn[15][15], mat[15][15], coeff[15][15];

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    ll z = powmod(a, b / 2);
    return z * z % p * (b % 2 ? a : 1) % p;
}

ll inv(ll a, ll b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

void prt1(int e1, int e2, int to) {
    cout << "+ " << e1 << " " << e2 << " " << to << "\n";
}
void prt2(int e, int to) {
    cout << "^ " << e << " " << to << "\n";
}

int ct = 5;

int mult(int init, int m) {
    if (!m) m = p;
    int beg = -1;
    for (int i = 0; i < 32; ++i) {
        int plc = i ? ct + i - 1 : init;
        if (i) {
            int prevPlc = (i == 1 ? init : ct + (i - 2));
            prt1(prevPlc, prevPlc, plc);
        }
        if (m & (1 << i)) {
            if (beg == -1) { beg = plc; }
            else { prt1(beg, plc, beg); }
        }
    }
    ct += 31;
    return beg;
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("codeforces/out.txt", "w", stdout);
    cin >> d >> p;
    for (int n = 1; n < 15; ++n) {
        for (int k = 0; k <= n; ++k) {
            if (k == 0 || k == n) { bn[n][k] = 1; }
            else { bn[n][k] = (bn[n - 1][k - 1] + bn[n - 1][k]) % p; }
        }
    }

    // Solve system of equations
    for (int i = 1; i <= d; i++) {
        for (int j = d; j >= 1; j--) {
            mat[i][d + 1 - j] = bn[d][j] * powmod(i, d - j) % p;
        }
    }
    for (int i = 1; i <= d; i++) coeff[i][i] = 1LL;
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= d; j++) {
            if (i == j) continue;
            ll m = mat[j][i] * inv(mat[i][i], p) % p;
            for (int k = 1; k <= d; k++) {
                coeff[j][k] = (coeff[j][k] - m * coeff[i][k] % p + p) % p;
                mat[j][k] = (mat[j][k] - m * mat[i][k] % p + p) % p;
            }
        }
    }
    int iv = inv(mat[d - 1][d - 1], p);
    for (int i = 1; i <= d; i++) {
        coeff[d - 1][i] = (coeff[d - 1][i] * iv) % p;
        if (debug) cout << "COEFF " << i << " " << coeff[d - 1][i] << "\n";
    }

    //Perform operations
    prt1(1, 2, 3);
    int beg[3] = {};
    for (int a = 1; a <= 3; ++a) {
        for (int i = 1; i <= d; ++i) {
            prt1(a, 4, ct);
            for (int j = 0; j < i - 1; ++j)
                prt1(4, ct, ct);
            prt2(ct, ct);
            int posPow = ct;
            ct += 2;
            int posCst = mult(ct - 1, p - powmod(i, d));
            prt1(posPow, posCst, posCst);

            int posRes = mult(posCst, coeff[d - 1][i]);
            if (!beg[a - 1]) { beg[a - 1] = posRes; }
            else { prt1(beg[a - 1], posRes, beg[a - 1]); }
        }
    }

    int p0 = ct++;
    prt1(beg[0], beg[1], p0); //x^2 + y^2
    int p1 = mult(p0, p - 1); //(p-1)(X^2+y^2)
    prt1(p1, beg[2], p1); //2xy
    int ans = mult(p1, inv(2, p));
    cout << "f " << ans << "\n";


    return 0;
}
