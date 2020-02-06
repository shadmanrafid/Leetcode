class Solution {
    vector<TreeNode*> Unique_Subtrees(int start,int end){
       vector<TreeNode*>result;
        if(start>end)
        {
            result.push_back(NULL);
            return result;
        }
        if(start == end)
        {
            TreeNode *Node = new TreeNode(start);
            result.push_back(Node);
            return result;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left_subtree = Unique_Subtrees(start,i-1);
            vector<TreeNode*>right_subtree = Unique_Subtrees(i+1,end);
            for(int j = 0; j<left_subtree.size();j++)
                for(int k = 0; k < right_subtree.size(); k++)
                {
                    TreeNode* Node = new TreeNode(i);
                    Node->left = left_subtree[j];
                    Node->right = right_subtree[k];
                    result.push_back(Node);
                }
        }
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return Unique_Subtrees(1,n);
    }
};