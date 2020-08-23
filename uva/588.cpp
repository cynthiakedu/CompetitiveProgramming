#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
typedef complex<int> P;
#define X real()
#define Y imag()
vector<P> v;
vector<int> v1;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ct = 0;
    while (1) {
        ct++;
        v.clear();
        v1.clear();
        cin >> N;
        if (!N) return 0;
        if (ct != 1) cout << endl;
        for (int i = 1, a, b; i <= N; i++) {
            cin >> a >> b;
            v.push_back(P{a, b});
        }
        for (int i = 0; i < N; i++) {
            P a = v[i], b = v[(i + 1) % N], c = v[(i + 2) % N];
            P u = b - a, v = c - b;
            v1.push_back((conj(u) * v).Y);
        }
        bool ok = true;
        for (int i = 0; i < N; i++) {
            int a = v1[i], b = v1[(i + 1) % N];
            if (a > 0 && b > 0) ok = false;
            if (a < 0 && b < 0) ok = false;
        }
        cout << "Floor #" << ct << endl;
        cout << (ok ? "Surveillance is possible." : "Surveillance is impossible.") << endl;
    }

    return 0;
}
