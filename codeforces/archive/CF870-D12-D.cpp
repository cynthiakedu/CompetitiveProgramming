#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int arr[20005];
map<int, int> inv;
int arr2[20005];
int N;
int ans2[20005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << "? " << i << " " << 0 << endl;
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        inv[arr[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        cout << "? 0 " << i << endl;
        cin >> arr2[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int temp[50005] = {}, ct[50005] = {};
        if (arr[i] != i) continue;
        for (int j = 0; j < N; j++) {
            temp[j] = arr[j] ^ i;
            ct[temp[j]]++;
        }
        bool ok = true;
        for (int j = 0; j < N; j++) {
            if (ct[j] != 1) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        for (int j = 0; j < N; j++) {
            if ((temp[0] ^ inv[j ^ i]) != arr2[j]) ok = false;
        }
        if (ok) {
            for (int j = 0; j < N; j++) {
                ans2[j] = temp[j];
            }
            ans++;
        }
    }
    cout << "!" << endl;
    cout << ans << endl;
    for (int i = 0; i < N; i++) cout << ans2[i] << (i == N - 1 ? "\n" : " ");

    return 0;
}
