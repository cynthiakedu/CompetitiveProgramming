#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
int N, M;
vector<ii> v[1030];
int arr[mxN + 5], costs[mxN + 5];
vector<pair<ii, int>> v2;
int poss[1030];
ii choice[1030];
int ans1 = 0, ans2 = INT_MAX;
ii ans3 = {1, 2};

int getNum(bool ok) {
    int x;
    cin >> x;
    int temp[10] = {}, num = 0;
    for (int j = 1, y; j <= x; j++) {
        cin >> y;
        temp[y - 1] = 1;
    }
    for (int j = 0; j < 9; j++) {
        if (!ok && !temp[j]) num += (1 << j);
        if (ok && temp[j]) num += (1 << j);
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < (1 << 9); i++) poss[i] = INT_MAX;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        arr[i] = getNum(true);
    }
    for (int i = 1, x; i <= M; i++) {
        cin >> costs[i];
        int num = getNum(false);
        v[num].push_back({costs[i], i});
    }
    ans2 = costs[1] + costs[2];
    for (int i = 0; i < (1 << 9); i++) {
        sort(v[i].begin(), v[i].end());
        if (v[i].size() > 0) v2.push_back({v[i][0], i});
        if (v[i].size() > 1) v2.push_back({v[i][1], i});
    }
    for (int i = 0; i < v2.size(); i++) {
        for (int j = i + 1; j < v2.size(); j++) {
            int a = v2[i].first.first, b = v2[j].first.first;
            int id1 = v2[i].first.second, id2 = v2[j].first.second;
            int x = v2[i].second, y = v2[j].second;
            if (a + b < poss[x & y]) {
                poss[x & y] = min(poss[x & y], a + b);
                choice[x & y] = {id1, id2};
            }
        }
    }
    for (int i = 0; i < (1 << 9); i++) {
        if (poss[i] == INT_MAX) continue;
        int tmp = 0;
        int newCost = costs[choice[i].first] + costs[choice[i].second];

        for (int j = 1; j <= N; j++) {
            if (!(i & (arr[j]))) {
                tmp++;
            }
        }
        if (tmp > ans1) {
            ans1 = tmp;
            ans2 = newCost;
            ans3 = choice[i];
        } else if (tmp == ans1) {
            if (newCost < ans2) {
                ans2 = newCost;
                ans3 = choice[i];
            }
        }
    }
    cout << ans3.first << " " << ans3.second << endl;

    return 0;
}
