#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, Q;
string arr[100005];
set<string> S[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < M; i++) {
        int type;
        string x, y;
        cin >> type >> x >> y;
        int sx = S[0].count(x) > 0 ? 0 : S[1].count(x) > 0 ? 1 : 2;
        int sy = S[1].count(y) > 0 ? 0 : S[1].count(y) > 0 ? 1 : 2;
        // if (type == 0 && sx)
    }

    return 0;
}
