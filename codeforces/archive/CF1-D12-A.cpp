#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;

map<string, int> m = {{"Tetrahedron", 4}, {"Cube", 6}, {"Octahedron", 8}, {"Dodecahedron", 12}, {"Icosahedron", 20}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        ans += m[s];
    }
    cout << ans << endl;

    return 0;
}
