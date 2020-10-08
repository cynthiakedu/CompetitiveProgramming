#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N, arr[mxN + 5];
int L[mxN + 5], R[mxN + 5], cum[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    vector<int> v = {0};
    for (int i = 1; i <= N; i++) {
        int x = arr[i];
        while ((int)v.size() && arr[v.back()] >= x) {
            v.pop_back();
        }
        L[i] = v.back();
        v.push_back(i);
    }

    v = {N + 1};
    for (int i = N; i >= 1; i--) {
        int x = arr[i];
        while ((int)v.size() && arr[(v.back())] >= x) {
            v.pop_back();
        }
        R[i] = v.back();

        v.push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        int amt = (i - L[i] - 1) + (R[i] - i - 1) + 1;
        cum[amt] = max(cum[amt], arr[i]);
    }
    for (int i = N; i >= 1; i--) {
        cum[i] = max(cum[i], cum[i + 1]);
    }

    for (int i = 1; i <= N; i++) {
        cout << cum[i] << (i == N ? "\n" : " ");
    }

    return 0;
}
