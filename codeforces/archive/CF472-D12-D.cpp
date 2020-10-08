#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N, arr[2005][2005];

bool check(vector<int> v) {
    if (v.size() <= 2) return true;
    int x = v[0];
    // cout << "CHECKING " << x << endl;
    int mn = INT_MAX, y = -1;
    for (auto t : v) {
        if (t == x) continue;
        if (arr[x][t] < mn) {
            mn = arr[x][t];
            y = t;
        }
    }
    // cout << "second for it is " << y << endl;
    vector<int> v1 = {y}, v2 = {x};
    int d = arr[x][y];
    for (auto t : v) {
        if (t == x || t == y) continue;
        int a = arr[t][x], b = arr[t][y];
        if (b - a == d) {
            v2.push_back(t);
            // cout << t << " is with " << x << endl;
        } else if (a - b == d) {
            // cout << t << " is with " << y << endl;

            v1.push_back(t);
        } else {
            return false;
        }
    }
    for (auto a : v1) {
        for (auto b : v2) {
            if (!(arr[a][y] + arr[x][b] + d == arr[a][b])) {
                return false;
            }
        }
    }
    return check(v1) && check(v2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //check symmetry
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] != arr[j][i]) {
                cout << "NO" << endl;
                return 0;
            }
            if (i != j && arr[i][j] == 0) {
                cout << "NO" << endl;
                return 0;
            }
            if (i == j && arr[i][j] != 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    vector<int> v;
    for (int i = 1; i <= N; i++) v.push_back(i);
    if (check(v)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
