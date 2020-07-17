#include <bits/stdc++.h>
using namespace std;
int N, arr[200005];
bool hasIn[200005];
bool vis[200005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    hasIn[arr[i]] = true;
  }

  vector<int> v1;
  for (int i = 1; i <= N; i++) {
    if (!hasIn[i] && !arr[i]) {
      v1.push_back(i);
    }
  }

  for (int i = 1; i <= N; i++) {
    if (!hasIn[i] && arr[i]) {
      int x = i;
      while (arr[x] != i && arr[x] != 0) {
        vis[x] = true;
        x = arr[x];
      }
      if (v1.size() == 0) {
        arr[x] = i;
      } else {
        arr[x] = v1[0];
        for (int j = 0; j < v1.size(); j++) {
          arr[v1[j]] = j == v1.size() - 1 ? i : v1[j + 1];
          hasIn[v1[j]] = true;
        }
        v1.clear();
      }
    }
  }

  vector<int> v2;
  for (int i = 1; i <= N; i++) {
    if (arr[i] == 0) {
      v2.push_back(i);
    }
  }
  for (int i = 0; i < v2.size(); i++) {
    arr[v2[i]] = v2[i == v2.size() - 1 ? 0 : i + 1];
  }

  for (int i = 1; i <= N; i++) cout << arr[i] << (i == N ? "\n" : " ");

  return 0;
}
