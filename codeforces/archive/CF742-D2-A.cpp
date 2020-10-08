#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> v = {8, 4, 2, 6};
    if (N == 0) {
        cout << 1 << endl;
    } else {
        cout << v[(N - 1) % 4] << endl;
    }

    return 0;
}
