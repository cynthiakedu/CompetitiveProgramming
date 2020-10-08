#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int arr[105][2];
string s;
int a, b;

bool isMultiple(int a1, int b1, int a2, int b2) {
    if (!a1 && !b1) return true;
    if (!a2 && !b2) return false;
    if (!b2) {
        swap(a1, b1);
        swap(a2, b2);
    }
    int sa1 = a1 > 0 ? 1 : -1;
    int sa2 = a2 > 0 ? 1 : -1;
    int sb1 = b1 > 0 ? 1 : -1;
    int sb2 = b2 > 0 ? 1 : -1;
    if (!a2) {
        if (a1) return false;
        if (!b1) return true;
        if (sb1 * sb2 == -1) return false;
        return (abs(b1) % abs(b2) == 0);
    }
    if (sa1 * sa2 == -1 || sb1 * sb2 == -1) return false;
    if ((abs(a1) % abs(a2) != 0) || (abs(b1) % abs(b2) != 0)) return false;
    if (abs(a1) / abs(a2) != abs(b1) / abs(b2)) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        char c = s[i - 1];
        arr[i][0] = arr[i - 1][0];
        arr[i][1] = arr[i - 1][1];
        if (c == 'U') arr[i][1]++;
        if (c == 'D') arr[i][1]--;
        if (c == 'R') arr[i][0]++;
        if (c == 'L') arr[i][0]--;
    }
    int n = s.size();
    for (int i = 0; i < (int)s.size(); i++) {
        if (isMultiple(a - arr[i][0], b - arr[i][1], arr[n][0], arr[n][1])) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
