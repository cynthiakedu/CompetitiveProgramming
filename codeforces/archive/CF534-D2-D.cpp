#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
multiset<int> arr[3];
int num[200005], idx[200005];
vector<int> ids[200005];
int plc[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        arr[x % 3].insert(x);
        ids[x].push_back(i);
    }
    num[0] = -1;
    for (int i = 1; i <= N; i++) {
        // cout << "start " << i << endl;
        int x = num[i - 1];
        int up = x + 1;
        multiset<int> s = arr[(i - 1) % 3];
        multiset<int>::iterator it = arr[(i - 1) % 3].upper_bound(up);
        if (it == arr[(i - 1) % 3].begin()) {
            cout << "Impossible" << endl;
            return 0;
        }
        it = prev(it);
        int p = *it;
        arr[(i - 1) % 3].erase(it);
        // cout << "PRINT " << endl;
        // for (auto x : arr[(i - 1) % 3]) {
        //     cout << x.first << " " << x.second << endl;
        // }
        num[i] = p;
        // cout << "choose " << i << " " << num[i] << " " << idx[i] << endl;
    }
    cout << "Possible" << endl;
    for (int i = 1; i <= N; i++) {
        int x = num[i];
        cout << ids[x][plc[x]] << (i == N ? "\n" : " ");
        plc[x]++;
    }
    return 0;
}
