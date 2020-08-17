#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[200005];

int before[200005], after[200005];
int longest[200005];
priority_queue<ii, vector<ii>> pq;  // length, -id

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    memset(before, -1, sizeof before);
    memset(after, -1, sizeof after);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int idx = 1;
    vector<int> v;
    while (idx <= N) {
        int j = idx;
        while (j <= N && arr[j] == arr[idx]) j++;
        longest[idx] = j - idx;
        v.push_back(idx);
        // cout << "idx j " << idx << " " << j << endl;
        pq.push({j - idx, -idx});
        idx = j;
    }
    for (int i = 0; i < v.size() - 1; i++) {
        after[v[i]] = v[i + 1];
    }
    for (int i = 1; i < v.size(); i++) {
        before[v[i]] = v[i - 1];
    }
    int ans = 0;
    while (!pq.empty()) {
        ii p = pq.top();
        // cout << "pq " << p.first << " " << -p.second << endl;
        pq.pop();
        int u = -p.second;
        if (longest[u] > p.first || longest[u] == -1) continue;
        ans++;
        int a = before[-p.second], b = after[-p.second];
        if (a == -1 || b == -1) continue;
        if (arr[a] != arr[b]) continue;
        // cout << "process" << endl;
        after[a] = after[b];
        before[after[b]] = a;
        longest[a] += longest[b];
        longest[b] = -1;
        longest[u] = -1;
        pq.push({longest[a], -a});
    }
    cout << ans << endl;

    return 0;
}

// 5
// 4 3 3 4 4
