#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
bool debug = false;
const int mxN = 5e5;
int arr[mxN + 5][2];
int N, ct[mxN + 5], num[mxN + 5], counter = 1, numComp;
vector<ii> v;
set<int> S;
ll ans, numEdge;

int p[mxN + 5], r[mxN + 5];
int findSet(int x) {
    return p[x] == x ? x : p[x] = findSet(p[x]);
}

void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x != y) {
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
    cin >> N;
    numComp = N;
    for (int i = 1; i <= N; i++) p[i] = i;
    for (int i = 1, l, r; i <= N; i++) {
        cin >> l >> r;
        arr[i][0] = l;
        arr[i][1] = r;
        v.push_back({l, -i});
        v.push_back({r, i});
    }
    sort(v.begin(), v.end());

    for (ii p : v) {
        int id = p.second, x = p.first;
        if (debug) cout << "go " << id << " " << x << endl;
        if (id < 0) {
            S.insert(-id);
            for (int id2 : S) {
                if (debug) cout << "before intersect " << id2 << " " << -id << " " << arr[id2][1] << " " << arr[-id][1] << endl;

                if (arr[id2][1] < arr[-id][1]) {
                    if (debug) cout << "intersect " << id2 << " " << -id << endl;
                    numEdge++;
                    if (numEdge > N - 1) {
                        cout << "NO" << endl;
                        return 0;
                    }
                    int s1 = findSet(id2), s2 = findSet(id);
                    if (s1 != s2) {
                        numComp--;
                        unionSet(s1, s2);
                    }
                }
            }
        } else {
            S.erase(id);
        }
    }
    if (debug) cout << "ans " << ans << " " << numComp << endl;
    if (numComp == 1 && numEdge == N - 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
