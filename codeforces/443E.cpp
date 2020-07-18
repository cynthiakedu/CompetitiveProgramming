#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
vector<int> arr;
ll score;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0, x; i < N; i++) {
    cin >> x;
    // cout << "arr " << endl;
    // for (auto x : arr) cout << x << " ";
    // cout << endl;
    if (arr.size() == 0 || arr.size() == 1) {
      arr.push_back(x);
    } else {
      if (x <= arr[arr.size() - 1]) {
        arr.push_back(x);
      } else if (arr[arr.size() - 2] <= arr[arr.size() - 1]) {
        arr.push_back(x);
      } else {
        while (arr.size() >= 2) {
          int a = arr[arr.size() - 2], b = arr[arr.size() - 1];
          if (x > b && a > b) {
            score += min(a, x);
            arr.pop_back();
          } else {
            break;
          }
        }
        arr.push_back(x);
      }
    }
  }
  //   cout << "arr " << endl;
  //   for (auto x : arr) cout << x << " ";
  //   cout << endl;

  vector<int> A = vector<int>{0}, B = vector<int>{0};
  A.push_back(arr[0]);
  B.push_back(arr[arr.size() - 1]);
  int idx = 1;
  for (; idx < arr.size() - 1; idx++) {
    if (arr[idx] <= A.back()) break;
    A.push_back(arr[idx]);
  }
  for (int i = arr.size() - 2; i >= idx; i--) {
    B.push_back(arr[i]);
  }

  //   cout << "A " << endl;
  //   for (auto a : A) cout << a << " ";
  //   cout << endl;
  //   cout << "B " << endl;
  //   for (auto b : B) cout << b << " ";
  //   cout << endl;

  while (A.size() > 2 && B.size() > 2) {
    int a1 = A[A.size() - 2], a2 = A[A.size() - 1];
    int b1 = B[B.size() - 2], b2 = B[B.size() - 1];
    if (a1 <= b1) {
      score += min(a2, b1);
      B.pop_back();
    } else {
      score += min(a1, b2);
      A.pop_back();
    }
  }
  if (B.size() > 2) {
    swap(A, B);
  }
  //   cout << "A " << endl;
  //   for (auto a : A) cout << a << " ";
  //   cout << endl;
  //   cout << "B " << endl;
  //   for (auto b : B) cout << b << " ";
  //   cout << endl;
  if (A.size() > 2) {
    for (int i = A.size() - 1; i >= 2; i--) {
      if (B.back() != 0) {
        score += min(B.back(), A[i - 1]);
      }
    }
  }
  cout << score << endl;
  return 0;
}

// 7
// 1 2 4 6 6 4 3