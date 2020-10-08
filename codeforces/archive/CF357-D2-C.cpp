#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N;
vector<int> divs;
int arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 3; i <= N; i++) {
        if (N % i == 0) {
            vector<int> v(N / i, 0);
            for (int j = 0; j < N; j++) {
                v[j % (N / i)] += arr[j];
            }
            for (int j = 0; j < N / i; j++) {
                if (v[j] == i) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
