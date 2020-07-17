#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> adjList[100005];
bool vis[100005];
int ans = 0;

int visit(int x)
{
    vis[x] = true;
    int ct = 0;
    for (auto y : adjList[x]) {
        if (!vis[y]) {
            int c = visit(y);
            if (c % 2 == 0)
                ans++;
            ct += c;
        }
    }
    return ct + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0, x, y; i < N - 1; i++) {
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    int ct = visit(1);
    if (ct % 2 == 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
