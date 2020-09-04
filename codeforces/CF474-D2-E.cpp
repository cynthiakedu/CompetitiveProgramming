#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e5;
int N;
ll arr[mxN + 5], D;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> D;
    ans.push_back(1);
    for (int i = 1; i <= N; i++) cin >> arr[i];

    int idx = 1;
    while (idx < N) {
        ans.pop_back();
        int j = idx;
        bool pos = false, neg = false;
        vector<ll> temp;
        while (j <= N) {
            temp.push_back(arr[j]);
            if (j == N) break;
            if (arr[j + 1] == arr[j]) {
                j++;
            } else if (arr[j + 1] > arr[j]) {
                if (neg) {
                    break;
                }
                pos = true;
                j++;
            } else {
                if (pos) {
                    break;
                }
                neg = true;
                j++;
            }
        }
        if (neg) {
            for (int i = 0; i < temp.size(); i++) temp[i] = -temp[i];
        }
        int idx2 = 0;
        vector<ll> chosen = {0};
        while (true) {
            int pos = (int)(lower_bound(temp.begin() + idx2 + 1, temp.end(), temp[idx2] + D) - temp.begin());
            if (pos >= temp.size()) {
                break;
            }
            chosen.push_back(pos);
            idx2 = pos;
        }
        chosen[chosen.size() - 1] = temp.size() - 1;
        for (auto x : chosen) {
            ans.push_back(x + idx);
        }
        idx = j;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");

    return 0;
}
