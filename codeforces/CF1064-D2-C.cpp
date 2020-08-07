#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
int arr[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        arr[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << (char)('a' + i);
        }
    }
    cout << endl;

    return 0;
}
