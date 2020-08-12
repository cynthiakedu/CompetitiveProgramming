#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e5;
int N, arr[mxN + 5], arr2[mxN + 5];
bool win[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr2[arr[i]] = i;
    }

    for (int i = N; i >= 1; i--) {
        int pos = arr2[i];
        vector<int> poss;
        for (int j = pos + i; j <= N; j += i) {
            if (arr[j] > i) poss.push_back(arr[j]);
        }
        for (int j = pos - i; j >= 1; j -= i) {
            if (arr[j] > i) poss.push_back(arr[j]);
        }

        int loseCt = 0;
        for (auto x : poss) {
            if (!win[x]) loseCt++;
        }
        win[i] = loseCt > 0;
    }

    for (int i = 1; i <= N; i++) {
        cout << (win[arr[i]] ? "A" : "B");
    }
    cout << endl;

    return 0;
}
