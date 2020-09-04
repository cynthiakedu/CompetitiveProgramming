#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int tree[1000005];
int n = 4e5;

int mn(int a, int b) {
    b += 200005;
    a += n, b += n;
    int ret = INT_MAX;
    while (a <= b) {
        if (a % 2 == 1) ret = min(ret, tree[a++]);
        if (b % 2 == 0) ret = min(ret, tree[b--]);
        a /= 2;
        b /= 2;
    }
    return ret;
}

void change(int k, int x) {
    k += 200005;
    k += n;
    tree[k] = min(tree[k], x);
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = min(tree[2 * k], tree[2 * k + 1]);
    }
}

string s;
int arr[200005], N;
vector<char> v{'a', 'e', 'i', 'o', 'u'};
int ans1 = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 2 * (4e5); i++) tree[i] = INT_MAX;

    cin >> s;
    N = s.size();
    change(0, 0);
    for (int i = 1; i <= N; i++) {
        char c = tolower(s[i - 1]);
        if (find(v.begin(), v.end(), c) != v.end()) {
            arr[i] = -1;
        } else {
            arr[i] = 2;
        }
        arr[i] += arr[i - 1];
        int m = mn(0, arr[i]);
        if (m < INT_MAX) {
            ans1 = max(ans1, i - m);
        }
        change(arr[i], i);
    }
    if (ans1 == 0) {
        cout << "No solution" << endl;
        return 0;
    }
    int ans2 = 0;
    for (int i = ans1; i <= N; i++) {
        if (arr[i] >= arr[i - ans1]) {
            ans2++;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
