#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
pair<int, string> arr[3005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        string s;
        cin >> s >> x;
        arr[i] = {x, s};
    }
    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        if (arr[i].first > i) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<string> heightDec;
    map<string, int> m;

    for (int i = 0; i < N; i++) {
        vector<string> v;
        int x = arr[i].first;
        string s = arr[i].second;
        for (int j = 0; j < x; j++) {
            v.push_back(heightDec[j]);
        }
        v.push_back(s);
        for (int j = x; j < heightDec.size(); j++) {
            v.push_back(heightDec[j]);
        }
        heightDec = v;
    }
    for (int i = 0; i < heightDec.size(); i++) {
        m[heightDec[i]] = heightDec.size() + 1 - i;
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i].second << " " << m[arr[i].second] << endl;
    }

    return 0;
}
