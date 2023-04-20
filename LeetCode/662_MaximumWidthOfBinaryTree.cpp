/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int width=0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            int sz = q.size();
            int mn = q.front().second;
            int firstidx, lastidx;
            for(int i=0; i<sz; i++){
                int currIdx = q.front().second - mn;
                TreeNode *node = q.front().first;
                q.pop();
                
                if(i==0){
                    firstidx = currIdx;
                }
                if(i == sz-1){
                    lastidx = currIdx;
                }
                if(node->left){
                    q.push({node->left, (long long)currIdx*2+1});
                }
                if(node->right){
                    q.push({node->right, (long long)currIdx*2+2});
                }
            }
            width = max(width, lastidx-firstidx+1);
        }
        return width;
    }
};
