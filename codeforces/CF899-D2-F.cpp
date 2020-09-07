#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N, M;
string s;
map<char, set<int>> m;
bool used[mxN + 5];

vector<int> ft;

int rsq(int b) {
    int sum = 0;
    for (; b; b -= (b & (-b))) sum += ft[b];
    return sum;
}
int rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += (k & (-k))) {
        ft[k] += v;
    }
}

int findIndex(int num) {
    int l = 1, r = N;
    while (l < r) {
        int m = (l + r) / 2;
        int x = rsq(1, m);
        if (num > x) {
            l = m + 1;
        } else if (num < x) {
            r = m;
        } else {
            if (!used[m]) {
                return m;
            }
            r = m;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> s;
    ft.assign(N + 5, 0);
    for (int i = 1; i <= N; i++) adjust(i, 1);
    for (int i = 1; i <= N; i++) {
        char c = s[i - 1];
        m[c].insert(i);
    }

    for (int i = 0, l, r; i < M; i++) {
        char c;
        cin >> l >> r >> c;
        int l1 = findIndex(l), r1 = findIndex(r);
        set<int>::iterator pos1 = m[c].lower_bound(l1);
        set<int>::iterator pos2 = m[c].upper_bound(r1);
        while (pos1 != pos2) {
            int x = *pos1;
            set<int>::iterator temp = pos1;
            pos1++;
            m[c].erase(temp);
            used[x] = true;
            adjust(x, -1);
        }
    }

    string ans = "";
    for (int i = 1; i <= N; i++) {
        if (used[i]) continue;
        ans += s[i - 1];
    }
    cout << ans << endl;
    return 0;
}
