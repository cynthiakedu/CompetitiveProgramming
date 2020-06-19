#include <bits/stdc++.h>
using namespace std;
int N, K;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  if (N == 1) {
    if (K > 0) {
      cout << -1 << endl;
    } else {
      cout << 1 << endl;
    }
    return 0;
  }
  vector<int> ANS;
  int numPairs = N / 2;
  int avg = K / numPairs;
  int lastAdd = K - numPairs * avg;
  if (avg <= 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= 2 * (numPairs - lastAdd); i++) {
    ANS.push_back(i * (avg));
  }
  for (int i = 2 * (numPairs - lastAdd) + 1; i <= 2 * numPairs; i++) {
    ANS.push_back(i * (avg + 1));
  }

  if (N % 2 == 1) {
    ANS.push_back(ANS[ANS.size() - 1] + 1);
  }
  for (int i = 0; i < ANS.size(); i++)
    cout << ANS[i] << (i == ANS.size() - 1 ? "\n" : " ");

  return 0;
}
