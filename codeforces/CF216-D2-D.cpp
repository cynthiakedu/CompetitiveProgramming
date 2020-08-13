#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
vector<int> arr[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0, p; i < N; i++) {
        cin >> p;
        for (int j = 0, x; j < p; j++) {
            cin >> x;
            arr[i].push_back(x);
        }
        sort(arr[i].begin(), arr[i].end());
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a = (i - 1 + N) % N, b = (i + 1 + N) % N;
        for (int j = 0; j < arr[i].size() - 1; j++) {
            int amt = (int)(upper_bound(arr[a].begin(), arr[a].end(), arr[i][j + 1]) - upper_bound(arr[a].begin(), arr[a].end(), arr[i][j]));
            int amt2 = (int)(upper_bound(arr[b].begin(), arr[b].end(), arr[i][j + 1]) - upper_bound(arr[b].begin(), arr[b].end(), arr[i][j]));
            if (amt != amt2) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
