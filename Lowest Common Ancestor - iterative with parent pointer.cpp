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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*>stk;
        unordered_map<TreeNode*,TreeNode*>hash_map;
        
        hash_map[root] = NULL;
        stk.push(root);
        TreeNode* top;
        
        while(hash_map.find(p) == hash_map.end() || hash_map.find(q) == hash_map.end()){
            top = stk.top();
            stk.pop();
            if(top->right != NULL){
                hash_map[top->right] = top;
                stk.push(top->right);
            }
            if(top->left != NULL){
                hash_map[top->left] = top;
                stk.push(top->left);
            }
            
        }
        vector<TreeNode*>ancestors;
        TreeNode* cur = p;
        while(cur != NULL){
            ancestors.push_back(cur);
            cur = hash_map[cur];
            
        }
        
        cur = q;
        while(find(ancestors.begin(),ancestors.end(),cur) == ancestors.end()){
            cur = hash_map[cur];
        }
        return cur;
        
    }
};