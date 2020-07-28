#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
char arr[1005][1005];
int T, N, M;

vector<ii> fd(int x, int y) {
    vector<ii> v;
    vector<int> dir{-1, 0, 1};
    for (auto dx : dir) {
        for (auto dy : dir) {
            if (!dx && !dy) continue;
            for (int i = 1; i <= max(N, M); i++) {
                int x1 = dx * i + x, y1 = dy * i + y;
                if (x1 < 0 || x1 >= 8) break;
                if (y1 < 0 || y1 >= 8) break;
                if (arr[x1][y1] == 'X') break;
                v.push_back(ii(x1, y1));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
