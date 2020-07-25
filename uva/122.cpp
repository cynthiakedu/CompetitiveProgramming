#include <bits/stdc++.h>
using namespace std;
string s;
map<string, int> m;
map<string, bool> vis;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> s) {
        m.clear();
        vis.clear();
        v.clear();
        bool ok = true;
        while (s != "()") {
            int pos = s.find(',');
            string a = s.substr(1, pos - 1);
            string b = s.substr(pos + 1, s.size() - 1 - pos - 1);
            int a1 = stoi(a);
            if (m.count(b) > 0) ok = false;
            m[b] = a1;
            vis[b] = false;
            cin >> s;
        }
        if (m.size() == 0) {
            return 0;
        }
        if (!ok) {
            cout << "not complete" << endl;
            continue;
        }
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            if (m.count(u) == 0) continue;
            v.push_back(m[u]);
            vis[u] = true;
            q.push(u + "L");
            q.push(u + "R");
        }
        for (auto p : vis) {
            if (!p.second) ok = false;
        }
        if (!ok) {
            cout << "not complete" << endl;
            continue;
        }
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << (i == (v.size() - 1) ? "\n" : " ");
        }
    }

    return 0;
}
