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

 class bstiterator{
    stack<TreeNode*> st;
    bool reverse=true;
    public:
    bstiterator(TreeNode* node, bool isreverse){
        reverse=isreverse;
        pushall(node);
    }
    bool hasnext(){
        return !st.empty();
    }

    int next(){
        TreeNode* temp=st.top();
        st.pop();
        if(!reverse){
            pushall(temp->right);
        }
        else{
            pushall(temp->left);
        }
        return temp->val;
    }

    private:
    void pushall(TreeNode* node){
        for(;node!=NULL; ){
            st.push(node);
            if(reverse==true){
                node=node->right;
            }
            else{
                node=node->left;
            }
        }
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        bstiterator l(root,false);
        bstiterator r(root,true);

        int i=l.next();
        int j=r.next();

        while(i<j){
            if(i+j==k) return true;
            else if(i+j <k){
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
        return false;
        
    }
};