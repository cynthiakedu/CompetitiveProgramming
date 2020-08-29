#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N, M, Q;
vector<int> arr[mxN + 5];
bool row[mxN + 5];
int p[mxN + 5], r[mxN + 5];
int num, num2;

int findSet(int x) {
    return p[x] == x ? x : p[x] = findSet(p[x]);
}

void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x != y) {
        num--;
        if (r[x] < r[y]) {
            p[x] = y;
        } else {
            p[y] = x;
            if (r[x] == r[y]) {
                r[x]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> Q;
    for (int i = 1; i <= M; i++) p[i] = i;
    num = M;
    for (int i = 0, u, v; i < Q; i++) {
        cin >> u >> v;
        arr[u].push_back(v);
        row[u] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i].size() > 1) {
            for (int j = 1; j < (int)arr[i].size(); j++) {
                unionSet(arr[i][0], arr[i][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!row[i]) {
            num2++;
        }
    }
    cout << (num - 1) + num2 << endl;

    return 0;
}
