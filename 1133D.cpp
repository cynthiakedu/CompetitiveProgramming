#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii; 
int N, a[200005], b[200005]; 
int freeCt = 0; 
int mx = 0; 
map<ii, int> m; 

int gcd(int x, int y){
    if (x == 0) return y; 
    return gcd(y%x, x); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N; 
    for (int i = 1; i <= N; i++){
        cin >> a[i]; 
    }
    for (int i = 1; i <= N; i++){
        cin >> b[i]; 
    }

    for (int i = 1; i <= N; i++){
        if (a[i] == 0 && b[i] == 0) {freeCt++; continue;}
        if (a[i] == 0 && b[i] != 0) continue; 
        int A = abs(a[i]), B = abs(b[i]);
        int g = gcd(A, B); 
        int sgn = -1; 
        if (a[i] < 0) sgn *= -1; 
        if (b[i] < 0) sgn *= -1;  
        m[ii(sgn*(B/g), A/g)] += 1; 
    }

    for (auto p : m){
        if (p.second > mx){
            mx = p.second; 
        }
    }

    cout<<mx+freeCt<<endl;
    return 0;
}
