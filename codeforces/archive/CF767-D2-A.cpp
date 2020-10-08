#include <bits/stdc++.h>
using namespace std;
int N, arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int idx = N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        arr[x] = 1;
        vector<int> ans;
        while (idx > 0 && arr[idx]) {
            ans.push_back(idx);
            idx--;
        }
        for (int i = 0; i < ans.size(); i++) cout << (ans[i]) << (i < ans.size() - 1 ? " " : "");
        cout << endl;
    }

    return 0;
}
