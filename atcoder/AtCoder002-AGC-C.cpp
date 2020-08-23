#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, L, arr[100005];
int mx = 0, idx = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < N; i++) {
        int amt = arr[i] + arr[i + 1];
        if (amt > mx) {
            mx = amt;
            idx = i;
        }
    }
    if (mx < L) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> v = {idx};
    for (int i = idx + 1; i < N; i++) v.push_back(i);
    for (int i = idx - 1; i >= 1; i--) v.push_back(i);
    reverse(v.begin(), v.end());
    cout << "Possible" << endl;
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}
