#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll S = 0;
set<ll> seen;
ll cum = 0;
ll arr[100005];
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        S += arr[i];
    }

    if (S % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    seen.insert((ll)0);
    for (int i = 1; i <= N; i++) {
        ll other = S / 2 - arr[i];
        if (seen.count(other)) {
            cout << "YES" << endl;
            return 0;
        }
        cum += arr[i];
        seen.insert(cum);
    }

    cum = 0;
    seen.clear();
    seen.insert(0);
    for (int i = N; i >= 1; i--) {
        ll other = S / 2 - arr[i];
        if (seen.count(other)) {
            cout << "YES" << endl;
            return 0;
        }
        cum += arr[i];
        seen.insert(cum);
    }

    cout << "NO" << endl;

    return 0;
}
