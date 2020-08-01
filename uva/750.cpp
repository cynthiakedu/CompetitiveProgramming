#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

vector<vector<int>> ans;
int sol[9];
bool col[20], diag1[20], diag2[20];
int a, b, T;

void search(int y) {
    if (y == 8) {
        vector<int> v(8);
        for (int i = 0; i < 8; i++) v[i] = sol[i];
        ans.push_back(v);
        return;
    }
    for (int x = 0; x < 8; x++) {
        if (col[x] || diag1[x + y] || diag2[x - y + 8 - 1]) continue;
        if (y == b && x != a) continue;
        col[x] = diag1[x + y] = diag2[x - y + 8 - 1] = true;
        sol[y] = x;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + 8 - 1] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    cout << endl;
    for (int t = 0; t < T; t++) {
        ans.clear();
        memset(sol, 0, sizeof sol);

        cin >> a >> b;
        a--, b--;
        search(0);
        if (t == 0)
            puts("");
        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8\n");
        cout << endl;
        for (int i = 0; i < ans.size(); i++) {
            vector<int> v = ans[i];
            printf("%2d     ", i + 1);
            for (int j = 0; j < v.size(); j++) {
                printf(" %d", v[j] + 1);
            }
            puts("");
        }
        cout << endl;
    }

    return 0;
}

// 2
// 1 1
// 1 3