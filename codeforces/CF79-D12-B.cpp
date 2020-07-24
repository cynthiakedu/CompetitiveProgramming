#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M, K, T;
vector<ii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K >> T;
    for (int i = 0, x, y; i < K; i++) {
        cin >> x >> y;
        v.push_back(ii(x, y));
    }
    sort(v.begin(), v.end());
    for (int t = 0, x, y; t < T; t++) {
        cin >> x >> y;
        int pos = (int)(lower_bound(v.begin(), v.end(), ii(x, y)) - v.begin());
        if (v[pos].first == x && v[pos].second == y) {
            cout << "Waste" << endl;
        } else {
            int num = M * (x - 1) + y - pos;
            vector<string> v1 = {"Carrots", "Kiwis", "Grapes"};
            cout << v1[(num - 1) % 3] << endl;
        }
    }

    return 0;
}
