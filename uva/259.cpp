#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
map<int, int> adj[50];

int mf, f, src = 26 + 10, sink = 26 + 10 + 1;
int totalTasks = 0;
vector<int> p;

void process(string s) {
    char a;
    int b;
    string s2;
    istringstream iss(s);
    iss >> a >> b >> s2;
    adj[src][a - 'A'] += b;
    totalTasks += b;
    for (int i = 0; i < s2.size() - 1; i++) {
        int dig = s2[i] - '0';
        adj[a - 'A'][26 + dig] = INT_MAX;
    }
}

void augment(int v, int minEdge) {
    if (v == src) {
        f = minEdge;
        return;
    }
    if (p[v] != -1) {
        augment(p[v], min(minEdge, adj[p[v]][v]));
        adj[p[v]][v] -= f;
        adj[v][p[v]] += f;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (getline(cin, s)) {
        mf = 0;
        totalTasks = 0;
        for (int i = 0; i < 50; i++) adj[i].clear();

        process(s);
        while (getline(cin, s)) {
            if (s.empty()) {
                break;
            }
            process(s);
        }

        for (int i = 0; i < 10; i++) adj[i + 26][sink] = 1;

        while (1) {
            vector<int> dist(50, -1);
            p.assign(50, -1);
            queue<int> q;
            f = 0;

            q.push(src);
            dist[src] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (u == sink) break;
                for (auto v : adj[u]) {
                    if (v.second > 0 && dist[v.first] == -1) {
                        q.push(v.first);
                        dist[v.first] = dist[u] + 1;
                        p[v.first] = u;
                    }
                }
            }
            augment(sink, INT_MAX);
            if (f == 0) break;
            mf += f;
        }
        if (mf != totalTasks) {
            cout << "!" << endl;
        } else {
            for (int i = 0; i < 10; i++) {
                char c = '_';
                for (int j = 0; j < 26; j++) {
                    if (adj[i + 26][j]) {
                        c = (char)(j + 'A');
                        break;
                    }
                }
                cout << c;
            }
            cout << endl;
        }
    }

    return 0;
}