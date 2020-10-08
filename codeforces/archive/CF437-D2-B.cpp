#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int S, L;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S >> L;
    vector<int> ans;

    for (int i = 16; i >= 0; i--) {
        int num = 1 << i;
        for (int j = 1; j * num <= L; j += 2) {
            if (S >= num) {
                S -= num;
                ans.push_back(num * j);
            }
        }
    }
    if (S > 0) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }

    return 0;
}
