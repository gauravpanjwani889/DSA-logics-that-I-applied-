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
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
       long long maxwidth=0;

        while(!q.empty()){
            long long start=q.front().second;
            long long end=q.back().second;

            maxwidth=max(maxwidth,end-start+1);

            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* currnode=q.front().first;
                long long idx=q.front().second;
                q.pop();
                
                if(currnode->left!=nullptr){
                    q.push({currnode->left,2*idx+1});

                }
                if(currnode->right!=nullptr){
                    q.push({currnode->right,2*idx+2});
                }

            }
        }
        return maxwidth;
        
    }
};