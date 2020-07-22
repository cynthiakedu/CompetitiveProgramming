#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
#define MOD 1000000007
int N, M, K, len;
int L[205], R[205];

int numbersSizes[205];
vector<int> numbers[205];
int numbersVals[205];

vector<ii> segsWithStart[25];
int digitVals[25];

ll dp[20][205][505];
int maxDigits = 200;

bool isPrefix(vector<int> a, vector<int> b, bool isStrict) {
  if (a.size() > b.size()) return false;
  if (isStrict && a.size() == b.size()) return false;
  //   cout << "small " << endl;
  //   for (auto x : a) cout << x << endl;
  //   cout << "big " << endl;
  //   for (auto x : b) cout << x << endl;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

int getValue(vector<int> x) {
  int ret = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= (int)x.size() - numbers[i][0]; j++) {
      bool isNumber = true;
      for (int k = 0; k < numbers[i][0]; k++) {
        if (x[j + k] != numbers[i][1 + k]) {
          isNumber = false;
        }
      }
      if (isNumber) {
        ret += numbersVals[i];
      }
    }
  }
  return ret;
}

vector<ii> getSegs(vector<int> x) {
  vector<ii> ret, temp;
  if (x.size() == 0) return ret;
  for (int j = 0; j < N; j++) {
    if (isPrefix(x, numbers[j], true)) {
      temp.push_back(ii(numbers[j][0], j));
    }
  }
  sort(temp.begin(), temp.end());
  ret.resize(temp.size());

  for (int j = 0; j < temp.size(); j++) {
    ret[j] = ii(0, temp[j].second);
    for (int k = 0; k < j; k++) {
      vector<int> kNum = numbers[temp[k].second];
      vector<int> jNum = numbers[temp[j].second];
      if (isPrefix(kNum, jNum, false)) {
        ret[j].first += numbersVals[temp[k].second];
      }
    }
  }
  return ret;
}

ll run(vector<int> pref, int start, int upperForStart, int KLeft) {
  int prefVal = pref.size() == 1 ? digitVals[pref[0]] : getValue(pref);
  if (prefVal > KLeft) return 0;
  if (start == maxDigits + 1) return 1;

  vector<ii> segs = pref.size() == 1 ? segsWithStart[pref[0]] : getSegs(pref);

  ll ret = 0;

  //   cout << "START " << endl;
  for (int i = 0; i < upperForStart; i++) {
    // cout << "calculating " << i << " " << start << " " << KLeft - prefVal
    //      << endl;
    ret = (ret + dp[i][start][KLeft - prefVal]) % MOD;
  }
  //   cout << "start " << start << " " << ret << endl;
  for (auto p : segs) {
    vector<int> number = numbers[p.second];
    int nextStart = numbersSizes[p.second] - pref.size() + start - 1;
    if (nextStart <= maxDigits) {
      ret -=
          dp[number[numbersSizes[p.second] - 1]][nextStart][KLeft - p.second];
      ret = (ret + MOD) % MOD;
      if (p.second + numbersVals[p.second] <= KLeft) {
        ret = (ret + dp[number[numbersSizes[p.second] - 1]][nextStart]
                       [KLeft - p.second - numbersVals[p.second]]) %
              MOD;
      }
    }
  }
  return ret;
}

int countBelow(int x[205]) {
  vector<int> pref;
  int ans = 0;
  pref.push_back(x[x[0]]);
  for (int i = x[0] + 1; i <= maxDigits; i++) {
    for (int j = 0; j < x[i]; j++) {
      pref.push_back(j);
      //   cout << "run " << i + 1 << " " << endl;
      int res = run(pref, i + 1, M, K);
      //   cout << "res " << res << endl;
      ans += res;
      pref.pop_back();
    }
    pref.push_back(x[i]);
  }
  for (int i = x[0] + 1; i <= maxDigits; i++) {
    // cout << "i " << i << " " << K << endl;
    for (int j = 1; j < M; j++) {
      //   cout << "run " << i + 1 << " " << endl;
      int res = dp[j][i][K];
      //   cout << "res " << res << endl;
      ans += res;
    }
  }
  //   cout << ans << endl;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //   N = 5;
  //   K = 10;
  //   numbersSizes[0] = 1;
  //   numbersSizes[1] = 2;
  //   numbersSizes[2] = 3;
  //   numbersSizes[3] = 3;
  //   numbersSizes[4] = 2;
  //   numbers[0] = vector<int>{3};
  //   numbers[1] = vector<int>{3, 7};
  //   numbers[2] = vector<int>{3, 7, 5};
  //   numbers[3] = vector<int>{3, 6, 5};
  //   numbers[4] = vector<int>{7, 3};
  //   numbersVals[0] = 1;
  //   numbersVals[1] = 2;
  //   numbersVals[2] = 3;
  //   numbersVals[3] = 4;
  //   numbersVals[4] = 5;
  //   vector<ii> v = getSegs(vector<int>{});
  //   cout << "getSegs " << endl;
  //   for (auto x : v) cout << x.first << " " << x.second << endl;
  //   cout << "getValue " << getValue({3}) << endl;
  //   cout << "getValue " << getValue({3, 3}) << endl;
  //   cout << "getValue " << getValue({3, 7, 3}) << endl;
  //   cout << "getValue " << getValue({4}) << endl;
  //   cout << isPrefix(vector<int>{1, 3}, vector<int>{1, 3, 4}, true) << endl;
  //   cout << isPrefix(vector<int>{1, 3}, vector<int>{1, 3, 4}, false) << endl;
  //   cout << isPrefix(vector<int>{1, 3, 4}, vector<int>{1, 3, 4}, true) <<
  //   endl; cout << isPrefix(vector<int>{1, 3}, vector<int>{1, 5, 4}, false) <<
  //   endl;

  cin >> N >> M >> K;
  cin >> len;
  L[0] = maxDigits - len + 1;
  for (int i = L[0]; i <= maxDigits; i++) cin >> L[i];
  cin >> len;
  R[0] = maxDigits - len + 1;
  for (int i = R[0]; i <= maxDigits; i++) cin >> R[i];
  for (int i = 0; i < N; i++) {
    cin >> len;
    numbersSizes[i] = len;
    for (int j = 1, x; j <= len; j++) {
      cin >> x;
      numbers[i].push_back(x);
    }
    cin >> numbersVals[i];
    if (len == 1) {
      digitVals[numbers[i][0]] += numbersVals[i];
    }
  }
  // getSegs for all digits
  for (int i = 0; i < M; i++) {
    segsWithStart[i] = getSegs(vector<int>{i});
  }
  // Fill memo
  for (int j = maxDigits + 1; j >= 1; j--) {
    for (int i = 0; i < M; i++) {
      for (int k = K; k >= 0; k--) {
        if (j == maxDigits + 1) {
          dp[i][j][k] = 1;
          continue;
        }
        dp[i][j][k] = run(vector<int>{i}, j + 1, M, k);
        cout << "dp " << i << " " << j << " " << k << " " << dp[i][j][k]
             << endl;
      }
    }
  }

  // get L, R
  cout << countBelow(L) << endl;
  cout << countBelow(R) << endl;

  return 0;
}
// 5 10 10
// 0
// 3 1 0 0
// 1 3 1
// 2 3 7 2
// 3 3 7 5 3
// 3 3 6 5 4
// 2 7 3 5

// 5 10 10
// 0
// 2 1 0
// 1 3 1
// 2 3 7 2
// 3 3 7 5 3
// 3 3 6 5 4
// 2 7 3 5

// 5 10 1
// 0
// 2 1 1
// 1 3 1
// 2 3 7 2
// 3 3 7 5 3
// 3 3 6 5 4
// 2 7 3 5