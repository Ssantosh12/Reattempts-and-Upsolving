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
    // subproblem/state defintion: number of good nodes in a subtree with 'root' as root node
    // and 'maxNodeRootToCurr' as the max node value from root to current node
    int goodNodesUptoSubtree(TreeNode* root, int maxNodeRootToCurr) {
        // base case:
        if(root==NULL)
            return 0;

        // transition:
        if(root->val>=maxNodeRootToCurr)
            return 1+goodNodesUptoSubtree(root->left,root->val)+goodNodesUptoSubtree(root->right,root->val);
        else
            return goodNodesUptoSubtree(root->left,maxNodeRootToCurr)+goodNodesUptoSubtree(root->right,maxNodeRootToCurr);
    }

    int goodNodes(TreeNode* root) {
        return goodNodesUptoSubtree(root,-1e4);
    }
};

// OLD Soluton
/*
class Solution {
public:
    // state defintion: no. of good nodes in subtree with root node 'root' 
    // where the max element found upto now is 'maxTillHere'
    int goodNodesWithMaxUptoHere(TreeNode *root, int maxTillHere){
        if(root==NULL)
            return 0;
        
        if(root->val>=maxTillHere)
            return 1+goodNodesWithMaxUptoHere(root->left,root->val)+goodNodesWithMaxUptoHere(root->right,root->val);
        else return goodNodesWithMaxUptoHere(root->left,maxTillHere)+goodNodesWithMaxUptoHere(root->right,maxTillHere);
    }
    
    int goodNodes(TreeNode* root) {
        return goodNodesWithMaxUptoHere(root,-1e4);
    }
};
*/
