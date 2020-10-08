#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M, X, N1;
char arr[35][35];
map<char, vector<ii>> m;
string q;
map<char, int> ct;

int dist(ii p, ii q) {
    return (q.first - p.first) * (q.first - p.first) + (q.second - p.second) * (q.second - p.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> X;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            m[arr[i][j]].push_back(ii(i, j));
        }
    }
    cin >> N1;

    for (int i = 0; i < 26; i++) {
        ct[(char)(i + 'a')] = 1;
        for (auto p1 : m[(char)(i + 'a')]) {
            for (auto p2 : m['S']) {
                if (dist(p1, p2) <= X * X) {
                    ct[(char)(i + 'a')] = 0;
                }
            }
        }
    }

    cin >> q;
    bool ok = true;
    int ans = 0;
    for (auto c : q) {
        if (m[tolower(c)].size() == 0) ok = false;
        if (isupper(c)) {
            if (m['S'].size() == 0) ok = false;
            ans += ct[tolower(c)];
        }
    }
    if (!ok) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
