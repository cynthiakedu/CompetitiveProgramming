#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int arr[5];
vector<int> perm(5);
int ans = 0;
bool ok;
void solve(int idx) {
    if (idx == 5) {
        if (ans == 23) {
            ok = true;
        }
        return;
    }
    int num = arr[perm[idx]];
    ans += num;
    solve(idx + 1);
    ans -= num;

    ans -= num;
    solve(idx + 1);
    ans += num;

    ans *= num;
    solve(idx + 1);
    ans /= num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ((cin >> arr[0]) && (cin >> arr[1]) && (cin >> arr[2]) && (cin >> arr[3]) && (cin >> arr[4])) {
        bool lst = true;
        for (int i = 0; i < 5; i++) {
            if (arr[i] != 0) lst = false;
        }
        if (lst) return 0;
        for (int i = 0; i < 5; i++) perm[i] = i;
        ok = false;

        do {
            ans = arr[perm[0]];
            solve(1);
        } while (next_permutation(perm.begin(), perm.end()));
        cout << (ok ? "Possible" : "Impossible") << endl;
    }

    return 0;
}
