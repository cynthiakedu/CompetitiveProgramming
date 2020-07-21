#include <bits/stdc++.h>
using namespace std;
int N, arr[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        arr[x] = i;
    }
    for (int i = 1; i <= N; i++) cout << arr[i] << (i == N ? "\n" : " ");
    return 0;
}
