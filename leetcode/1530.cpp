#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//From tmwilliamlin168
class Solution {
public:
    int d;
    int ans = 0;

    vector<int> dfs(TreeNode* u) {
        if (!u) return {};
        if (!(u->left) && !(u->right)) return {0};
        vector<int> l = dfs(u->left), r = dfs(u->right);
        for (int& a : l) a++;
        for (int& a : r) a++;
        for (int a : l) {
            for (int b : r) {
                if (a + b <= d) ans++;
            }
        }
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }

    int countPairs(TreeNode* root, int distance) {
        d = distance;
        dfs(root);
        return ans;
    }
};