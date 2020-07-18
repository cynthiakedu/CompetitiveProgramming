#include <bits/stdc++.h>
using namespace std;
int N, M, arr[100005], l[100005], t[100005];
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    arr[N + 1] = M;
    for (int i = 1; i <= N + 1; i++) {
        l[i] = l[i - 1] + (i % 2 == 1 ? arr[i] - arr[i - 1] : 0);
    }
    ans = l[N + 1];
    for (int i = 0; i <= N; i++) {
        if (arr[i + 1] - arr[i] >= 2) {
            int amt = l[i] + (arr[N + 1] - arr[i + 1]) - (l[N + 1] - l[i + 1]) + (arr[i + 1] - arr[i] - 1);
            if (amt > ans)
                ans = amt;
        }
    }
    cout << ans << endl;

    return 0;
}
