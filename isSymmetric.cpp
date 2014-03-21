/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
       queue<TreeNode *> queue_left;
       queue<TreeNode *> queue_right;
       if(root==NULL)
       return true;
       if(root->left==NULL && root->right==NULL)
       return true;
       else if((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right == NULL))
       return false;
       if(root->left->val==root->right->val)
       {
           queue_left.push(root->left);
           queue_right.push(root->right);
       }
       else return false;
       TreeNode * left, *right;
       while(!queue_left.empty())
       {
           left=queue_left.front();
           right=queue_right.front();
           queue_left.pop();
           queue_right.pop();
        
           
            
           
             if(left->left && right->right)
             if(left->left->val==right->right->val)
             {
                 queue_left.push(left->left);
                 queue_right.push(right->right);
             }
             else return false;
             else if(left->left !=right->right)
             return false;
             
             if(left->right && right->left)
             if(left->right->val==right->left->val)
             {
                 queue_left.push(left->right);
                 queue_right.push(right->left);
             }
             else return false;
             else if(left->right != right->left)
             return false;
             
           
       }
       return true;
       
    }
};
