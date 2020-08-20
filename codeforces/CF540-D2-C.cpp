#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int r1, c1, r2, c2;
int N, M;
char arr[505][505];

bool isValid(int x, int y) {
    if (x <= 0 || x > N) return false;
    if (y <= 0 || y > M) return false;
    return true;
}

bool dfs(int x, int y) {
    // cout << "x y " << x << " " << y << endl;
    arr[x][y] = 'X';
    if (x == r2 && y == c2) return true;
    bool ans = false;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
        int x0 = x + dx[i], y0 = y + dy[i];
        // cout << "potential " << x0 << " " << y0 << endl;
        if (isValid(x0, y0)) {
            if (arr[x0][y0] == 'X') {
                if (x0 == r2 && y0 == c2)
                    return true;
                else
                    continue;
            }

            ans |= dfs(x0, y0);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;
    cout << (dfs(r1, c1) ? "YES" : "NO") << endl;
    return 0;
}
