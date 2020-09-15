#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
bool debug = false;
const int mxN = 1e5;
int N, a[mxN + 5][2], b[mxN + 5][2];
vector<ii> v;
set<ii> s, e;

void bad() {
    cout << "NO" << endl;
    exit(0);
}

void check(int arr1[mxN + 5][2], int arr2[mxN + 5][2]) {
    vector<ii> v;
    for (int i = 1; i <= N; i++) {
        v.push_back({arr1[i][0], -i});
        v.push_back({arr1[i][1], i});
    }
    sort(v.begin(), v.end());

    for (auto p : v) {
        int id = abs(p.second);
        int l = arr2[id][0], r = arr2[id][1];
        if (debug) cout << "process " << p.second << " " << l << " " << r << endl;

        if (p.second < 0) {
            if (s.size() && r < (*prev(s.end())).first) bad();
            if (e.size() && l > (*(e.begin())).first) bad();
            s.insert({l, id});
            e.insert({r, id});
        } else {
            s.erase({l, id});
            e.erase({r, id});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i][0] >> a[i][1] >> b[i][0] >> b[i][1];
    }

    check(a, b);
    check(b, a);

    cout << "YES" << endl;

    return 0;
}
