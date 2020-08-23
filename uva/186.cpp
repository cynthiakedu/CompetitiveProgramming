#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
string s;
int ct = 0;

map<string, int> m;
map<int, string> m2;
int adj[105][105];
pair<string, int> p[105][105];
int p2[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            adj[i][j] = INT_MAX;
        }
    }
    while (getline(cin, s)) {
        if (s.empty()) break;
        int x1 = s.find(',');
        int x2 = s.find(',', x1 + 1);
        int x3 = s.find(',', x2 + 1);
        string start = s.substr(0, x1), dest = s.substr(x1 + 1, x2 - x1 - 1), route = s.substr(x2 + 1, x3 - x2 - 1);
        int dist = stoi(s.substr(x3 + 1));
        if (m.count(start) == 0) {
            m[start] = ++ct;
            m2[ct] = start;
        }
        if (m.count(dest) == 0) {
            m[dest] = ++ct;
            m2[ct] = dest;
        }
        int a = m[start], b = m[dest];
        if (adj[a][b] > dist) {
            adj[a][b] = adj[b][a] = dist;
            p[a][b] = {route, dist};
            p[b][a] = {route, dist};
            p2[a][b] = a;
            p2[b][a] = b;
        }
    }
    for (int k = 1; k <= ct; k++) {
        for (int i = 1; i <= ct; i++) {
            for (int j = 1; j <= ct; j++) {
                if (adj[i][k] != INT_MAX && adj[j][k] != INT_MAX) {
                    int newd = adj[i][k] + adj[j][k];
                    if (newd < adj[i][j]) {
                        adj[i][j] = newd;
                        p[i][j] = p[k][j];
                        p2[i][j] = p2[k][j];
                    }
                }
            }
        }
    }

    while (getline(cin, s)) {
        cout << endl;
        cout << endl;
        int x1 = s.find(',');
        string a1 = s.substr(0, x1), b1 = s.substr(x1 + 1);
        int a = m[a1], b = m[b1];
        int dist = adj[a][b];
        vector<pair<string, string>> v;
        vector<pair<string, int>> r;
        while (b != a) {
            v.push_back({m2[p2[a][b]], m2[b]});
            r.push_back(p[a][b]);
            b = p2[a][b];
        }
        cout << setw(21) << left << "From ";
        cout << setw(21) << left << "To ";
        cout << setw(11) << left << "Route ";
        cout << setw(5) << left << "Miles" << endl;
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < 20; i++) {
                cout << "-";
            }
            cout << " ";
        }
        for (int i = 0; i < 10; i++) {
            cout << "-";
        }
        cout << " ";
        for (int i = 0; i < 5; i++) {
            cout << "-";
        }
        cout << "\n";

        reverse(v.begin(), v.end());
        reverse(r.begin(), r.end());

        for (int i = 0; i < v.size(); i++) {
            cout << setw(21) << left << v[i].first;
            cout << setw(21) << left << v[i].second;
            cout << setw(11) << left << r[i].first;
            cout << setw(5) << right << r[i].second;
            cout << endl;
        }
        cout << setw(58) << right << "-----" << endl;
        for (int i = 0; i < 42; i++) cout << " ";
        cout << "Total";
        cout << setw(11) << right << dist << "\n";
    }

    return 0;
}
