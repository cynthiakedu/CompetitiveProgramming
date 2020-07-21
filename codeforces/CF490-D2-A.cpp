#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> arr[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr[x].push_back(i + 1);
    }
    int amt = min({arr[1].size(), arr[2].size(), arr[3].size()});
    cout << amt << endl;
    for (int i = 0; i < amt; i++) {
        cout << arr[1][i] << " " << arr[2][i] << " " << arr[3][i] << endl;
    }

    return 0;
}
