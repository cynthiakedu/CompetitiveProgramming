#include <bits/stdc++.h>
using namespace std;
string s;
int M;
int arr[200005], cum[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    cin >> M;
    for (int i = 0, x; i < M; i++) {
        cin >> x;
        arr[x - 1]++;
    }
    cum[0] = arr[0];
    for (int i = 1; i < s.size(); i++) {
        cum[i] = cum[i - 1] + arr[i];
    }
    for (int i = 0; i < s.size() / 2; i++) {
        if (cum[i] % 2 == 1) {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }
    cout << s << endl;

    return 0;
}
