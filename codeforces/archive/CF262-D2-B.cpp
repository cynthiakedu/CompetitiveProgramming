#include <bits/stdc++.h>
using namespace std;
int N, K, arr[100005], cum[100005] = {}, ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int negNum = 0;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] < 0) negNum = i;
        cum[i] = cum[i - 1] + arr[i];
    }

    if (negNum >= K || (negNum % 2 == K % 2)) {
        cout << (cum[N] - 2 * cum[min(negNum, K)]) << endl;
    } else {
        int a = negNum >= 1 ? arr[negNum] : INT_MAX;
        int b = negNum < N ? arr[negNum + 1] : INT_MAX;
        cout << (cum[N] - 2 * cum[negNum]) - 2 * min(abs(a), abs(b)) << endl;
    }

    return 0;
}
