#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
ll arr[2000005];
ll s = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr + 1, arr + N + 1);
    reverse(arr + 1, arr + N + 1);

    for (int i = 2; i <= N; i++) arr[i] += arr[i - 1];
    while (N >= 1) {
        s += arr[N];
        N /= 4;
    }
    cout << s << endl;

    return 0;
}
