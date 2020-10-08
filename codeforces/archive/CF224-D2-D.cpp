#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 200005;
int N, M;
string s, t;

int occur[26][mxN];
int r[26][mxN], l[26][mxN];
int arr1[mxN], arr2[mxN];

vector<ii> v[26];

int ans[2][26][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 2; j++) {
            ans[j][i][0] = INT_MAX;
            ans[j][i][1] = INT_MIN;
        }
    }

    cin >> s >> t;
    N = s.size();
    M = t.size();
    s = "1" + s;
    t = "1" + t;
    for (int i = 1; i <= N; i++) {
        int c = s[i] - 'a';
        occur[c][i] = 1;
        ans[0][c][0] = min(ans[0][c][0], i);
        ans[0][c][1] = max(ans[0][c][1], i);
    }
    for (int i = 0; i < 26; i++) {
        r[i][N + 1] = N + 1;
        r[i][N] = N + 1;
        for (int j = N - 1; j >= 0; j--) {
            if (occur[i][j + 1])
                r[i][j] = j + 1;
            else
                r[i][j] = r[i][j + 1];
        }
        l[i][0] = 0;
        l[i][1] = 0;
        for (int j = 2; j <= N + 1; j++) {
            if (occur[i][j - 1])
                l[i][j] = j - 1;
            else
                l[i][j] = l[i][j - 1];
        }
    }

    for (int i = 1; i <= M; i++) {
        int c = t[i] - 'a';
        arr1[i] = r[c][arr1[i - 1]];
    }
    arr2[M + 1] = N + 1;
    for (int i = M; i >= 1; i--) {
        int c = t[i] - 'a';
        arr2[i] = l[c][arr2[i + 1]];
    }
    for (int i = 1; i <= M; i++) {
        if (arr1[i - 1] + 1 < arr2[i + 1]) {
            int c = t[i] - 'a';
            v[c].push_back({arr1[i - 1] + 1, arr2[i + 1] - 1});
            ans[1][c][0] = min(ans[1][c][0], arr1[i - 1]);
            ans[1][c][1] = max(ans[1][c][1], arr2[i + 1]);
        }
    }
    bool ok = true;
    for (int i = 1; i <= N; i++) {
        int c = s[i] - 'a';
        int pos = (int)(upper_bound(v[c].begin(), v[c].end(), ii{i, INT_MAX}) - v[c].begin());
        if (pos == 0 || v[c][pos - 1].second < i) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
