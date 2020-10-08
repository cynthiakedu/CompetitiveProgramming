#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, a1[200005], a2[200005];
int ct1 = 0, ct2 = 0;
ll s1 = 0, s2 = 0;
ll lst;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            ct1++;
            a1[ct1] = x;
            s1 += x;
        } else {
            ct2++;
            a2[ct2] = abs(x);
            s2 += abs(x);
        }
        if (i == N) lst = x;
    }
    if (s1 < s2) {
        cout << "second" << endl;
        return 0;
    }
    if (s1 > s2) {
        cout << "first" << endl;
        return 0;
    }
    for (int i = 1; i <= min(ct1, ct2); i++) {
        if (a1[i] < a2[i]) {
            cout << "second" << endl;
            return 0;
        } else if (a1[i] > a2[i]) {
            cout << "first" << endl;
            return 0;
        }
    }
    if (ct1 > ct2) {
        cout << "first" << endl;
        return 0;
    } else if (ct2 > ct1) {
        cout << "second" << endl;
        return 0;
    }
    if (lst > 0) {
        cout << "first" << endl;
        return 0;
    }
    cout << "second" << endl;

    return 0;
}
