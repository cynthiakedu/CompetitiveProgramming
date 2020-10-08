#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
ll arr[100005][2];

vector<ll> getLine(int i, int j) {
    ll x1 = arr[i][0], y1 = arr[i][1];
    ll x2 = arr[j][0], y2 = arr[j][1];
    ll a, b, c;
    a = y2 - y1;
    b = x1 - x2;
    c = a * x1 + b * y1;
    return {a, b, c};
}

bool isSameLine(vector<int> v) {
    if (v.size() <= 2) return true;
    vector<ll> l = getLine(v[0], v[1]);
    for (auto x : v) {
        if (l[0] * arr[x][0] + l[1] * arr[x][1] != l[2]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1];

    if (N <= 2) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            vector<ll> line1 = getLine(i, j);

            vector<int> v;
            for (int k = 0; k < N; k++) {
                if (line1[0] * arr[k][0] + line1[1] * arr[k][1] != line1[2]) {
                    v.push_back(k);
                }
            }

            if (isSameLine(v)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
