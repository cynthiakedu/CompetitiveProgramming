#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
vector<int> y[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1, a, b; i <= M; i++) {
        cin >> a >> b;
        y[a].push_back(i);
        y[b].push_back(i);
    }
    int c = M;
    for (int i = 1; i <= N; i++) {
        if (y[i].size() == 0) {
            c++;
            y[i].push_back(c);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << y[i].size() << endl;
        for (int c : y[i]) {
            cout << c << " " << i << endl;
        }
    }
    return 0;
}
