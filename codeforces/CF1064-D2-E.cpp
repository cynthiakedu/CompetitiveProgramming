#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
vector<int> sz;
vector<int> l = {0, 0};
vector<int> r = {1000000000, 1000000000};

string first, s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cout << 0 << " " << 0 << endl;
    cin >> first;
    sz = {(N - 1) / 2, N - 1 - (N - 1) / 2};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < sz[i]; j++) {
            int m = (l[i] + r[i]) / 2;
            int x = 0, y = m;
            if (i == 1) swap(x, y);
            cout << x << " " << y << endl;
            cin >> s;
            if (s == first) {
                l[i] = m;
            } else {
                r[i] = m;
            }
        }
    }
    cout << 0 << " " << l[0] + 1 << " " << l[1] + 1 << " " << 0 << endl;

    return 0;
}
