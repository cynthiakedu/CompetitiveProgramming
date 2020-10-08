#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
ll sz[55];
ll arr[55][5005], arr2[250005];
ll preMax[55], posMax[55], allSum[55], partMax[55];
ll ans = LLONG_MIN;
ll bigTemp = LLONG_MIN;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 55; i++) {
        preMax[i] = LLONG_MIN;
        posMax[i] = LLONG_MIN;
        partMax[i] = LLONG_MIN;
    }
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> sz[i];
        ll temp = LLONG_MIN;
        ll s = 0;
        for (int j = 1; j <= sz[i]; j++) {
            cin >> arr[i][j];
            if (temp < 0) {
                temp = arr[i][j];
            } else {
                temp += arr[i][j];
            }
            partMax[i] = max(partMax[i], temp);
            s += arr[i][j];
            preMax[i] = max(preMax[i], s);
        }
        allSum[i] = s;
    }
    for (int i = 1; i <= N; i++) {
        ll s = 0;
        for (int j = sz[i]; j >= 1; j--) {
            s += arr[i][j];
            posMax[i] = max(posMax[i], s);
        }
    }

    for (int i = 1; i <= M; i++) {
        cin >> arr2[i];
    }

    for (int i = 1; i <= M; i++) {
        ll idx = arr2[i];
        if (bigTemp > 0) {
            ans = max(ans, preMax[idx] + bigTemp);
            bigTemp = max(bigTemp + allSum[idx], posMax[idx]);
        } else {
            bigTemp = posMax[idx];
        }
        ans = max(ans, partMax[idx]);
    }

    cout << ans << endl;
    return 0;
}
