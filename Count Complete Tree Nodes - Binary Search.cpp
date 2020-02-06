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
    bool exists(int idx,int depth, TreeNode* node)
    {
        int left = 0,right = pow(2,depth) -1,pivot;
        for(int i = 0; i<depth;i++){
            pivot = left + (right- left)/2;
            if(idx <= pivot){
                node = node->left;
                right = pivot;
            }
            else{
                node = node->right;
                left = pivot+1;
            }
        }
        return (node !=NULL)? true:false;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        else if(root->left == NULL) return 1;
        int depth = 0;
        TreeNode* cur = root;
        while(cur->left != NULL){
            depth++;
            cur=cur->left;
        }
        int full_nodes = pow(2,depth) - 1;
        
        int left = 0, right = pow(2,depth) -1;
        int pivot;
        while(left<=right){
            pivot = left + (right-left)/2;
            if(exists(pivot,depth,root)){
                left = pivot + 1;
            }
            else right = pivot -1;
        }
        return full_nodes + left;;
    }
};