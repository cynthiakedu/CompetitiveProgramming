#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K, arr[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= K; i++) cin >> arr[i];

    int ele = 1;
    stack<int> s;

    for (int i = 1; i <= K; i++) {
        if (s.size() && s.top() < arr[i]) {
            cout << -1 << endl;
            return 0;
        }
        s.push(arr[i]);
        while (s.size() && s.top() == ele) {
            s.pop();
            ele++;
        }
    }

    int idx = K + 1;
    while (s.size()) {
        for (int i = s.top() - 1; i >= ele; i--) {
            arr[idx++] = i;
        }
        ele = s.top() + 1;
        s.pop();
    }
    for (int i = N; i >= ele; i--) {
        arr[idx++] = i;
    }

    for (int i = 1; i <= N; i++) cout << arr[i] << (i == N ? "\n" : " ");

    return 0;
}
