#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
string s[15];
int c[15];
ll ct = 0;
int arr[40];

bool check(string x, int idx) {
    int num = 0;
    for (int i = 0; i < N; i++) {
        if (x[i] == s[idx][i]) {
            num++;
        }
    }
    return num == c[idx];
}

void solve(int idx, int num) {
    if (idx == N) {
        if (num == 0) {
            string x = "";
            for (int i = 0; i < N; i++) {
                int y = s[1][i] - '0';
                int newy = arr[i] == 1 ? y : 1 - y;
                x += (char)('0' + newy);
            }
            bool ok = true;

            for (int i = 2; i <= M; i++) {
                if (!check(x, i)) {
                    ok = false;
                }
            }
            if (ok) ct++;
        }
        return;
    }
    if (num >= 1) {
        arr[idx] = 1;
        solve(idx + 1, num - 1);
        arr[idx] = 0;
    }
    solve(idx + 1, num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> s[i] >> c[i];
    }
    solve(0, c[1]);
    cout << ct << endl;
    return 0;
}
