#include <bits/stdc++.h>
using namespace std;
int N;
int ct = 0;
string arr[100005];
string spec = "1";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    bool isZero = false;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] == "0") isZero = true;
    }
    if (isZero) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        bool ok = true;
        string s = arr[i];
        if (s[0] != '1') ok = false;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != '0') ok = false;
        }
        if (ok) {
            ct += s.size() - 1;
        } else {
            spec = s;
        }
    }
    cout << spec;
    for (int i = 0; i < ct; i++) cout << 0;
    cout << endl;

    return 0;
}
