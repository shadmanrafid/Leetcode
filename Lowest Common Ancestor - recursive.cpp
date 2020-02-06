/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *result;
    bool backtrack(TreeNode* current, TreeNode* p,TreeNode* q){
        if(current == NULL) return false;
        
        int left = backtrack(current->left,p,q)? 1:0;
        int right = backtrack(current->right,p,q)?1:0;
        int mid = 0;
        if(current == p || current == q){
            mid = 1;
        }
        if(mid + left + right >1){
            this->result = current;
        }
        if(mid+left+right > 0)return true;
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->result = NULL;
        
        backtrack(root,p,q);
        
        return this->result;
        
    }
};