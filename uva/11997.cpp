#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int K, arr[800][800];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> K) {
        int s = 0;
        for (int i = 1; i <= K; i++) {
            for (int j = 1; j <= K; j++) {
                cin >> arr[i][j];
            }
            sort(arr[i] + 1, arr[i] + K + 1);
            s += arr[i][1];
        }
        vector<int> v;
        v.push_back(s);
        for (int i = 1; i <= K; i++) {
            for (int j = 2; j <= K; j++) {
                int s1 = s + arr[i][j] - arr[i][1];
                v.push_back(s1);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 1; i <= K; i++) cout << v[i - 1] << (i == K ? "\n" : " ");
    }

    return 0;
}
