#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e5;
int N, arr[mxN + 5];
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    vector<int> v;
    for (int i = 1; i <= N; i++) {
        while (v.size() && v.back() < arr[i]) {
            v.pop_back();
        }
        if (v.size()) {
            ans = max(ans, (v.back() ^ arr[i]));
        }
        v.push_back(arr[i]);
    }
    v.clear();
    for (int i = N; i >= 1; i--) {
        while (v.size() && v.back() < arr[i]) {
            v.pop_back();
        }
        if (v.size()) {
            ans = max(ans, (v.back() ^ arr[i]));
        }
        v.push_back(arr[i]);
    }
    cout << ans << endl;

    return 0;
}
