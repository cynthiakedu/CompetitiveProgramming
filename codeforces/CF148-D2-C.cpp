#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, A, B;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> A >> B;
    if (N == A + 1 && A != 0) {
        cout << -1 << endl;
        return 0;
    }
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    ans.push_back(1);
    if (B == 0) ans.push_back(1);
    int s = 1;
    for (int i = 0; i < B; i++) {
        ans.push_back(s + 1);
        s = 2 * s + 1;
    }
    int lst = ans[ans.size() - 1];
    for (int i = 0; i < A; i++) {
        ans.push_back(lst + 1);
        lst++;
    }
    int x = N - ans.size();
    for (int i = 0; i < x; i++) {
        ans.push_back(1);
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    return 0;
}
