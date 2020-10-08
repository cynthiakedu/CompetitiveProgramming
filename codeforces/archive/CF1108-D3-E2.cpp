#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define T (1 << 18)
const int mxN = 1e5;
ii tree[2 * T];
int N, arr[mxN + 5];

void update(int l, int r, int val, int id = 1, int low = 0, int high = T) {  //val always negative so min works
    tree[id].first += (high - low) * tree[id].second;
    if (id < T) {
        tree[id * 2].second += tree[id].second;
        tree[id * 2 + 1].second += tree[id].second;
    }
    tree[id].second = 0;

    if (l <= low && r >= high) {
        tree[id].second += val;
        return;
    }

    int mid = (low + high) / 2;
    if (r <= mid)
        update(l, r, val, id * 2, low, mid);
    else if (l > mid)
        update(l, r, val, id * 2 + 1, mid, high);
    else {
        update(l, r, val, id * 2, low, mid);
        update(l, r, val, id * 2 + 1, mid, high);
        tree[id].first = min(tree[2 * id].first, tree[2 * id + 1].first);
    }
    if (id < T)
}

int query(int l, int r, int id = 1, int low = 0, int high = T) {
    tree[id].first += (high - low) * tree[id].second;
    if (id < T) {
        tree[id * 2].second += tree[id].second;
        tree[id * 2 + 1].second += tree[id].second;
    }
    tree[id].second = 0;

    if (l <= low && r >= high) return tree[id].first;

    int mid = (low + high) / 2;
    if (r <= mid) return query(l, r, id * 2, low, mid);
    if (l > mid) return query(l, r, id * 2 + 1, mid, high);
    return min(query(l, r, id * 2, low, mid), query(l, r, id * 2 + 1, mid, high));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        tree[T + i].first = arr[i];
    }
    cout << "here " << endl;
    for (int t = T - 1; t >= 1; t--) tree[t].first = min(tree[2 * t].first, tree[2 * t + 1].first);
    cout << "here2 " << endl;
    update(1, 3, -1);
    cout << query(1, 3) << endl;

    return 0;
}

// 5
// 2 -2 3 1 2
