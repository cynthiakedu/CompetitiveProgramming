#include <bits/stdc++.h>
using namespace std;
int N, arr[50005];
int Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        int pos1 = (int)(lower_bound(arr, arr + N, x) - arr);
        int pos2 = (int)(upper_bound(arr, arr + N, x) - arr);
        if (pos1 > 0) {
            cout << arr[pos1 - 1];
        } else {
            cout << "X";
        }
        cout << " ";
        if (pos2 < N) {
            cout << arr[pos2] << endl;
        } else {
            cout << "X" << endl;
        }
    }

    return 0;
}
