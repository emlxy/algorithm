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
class Solution114 {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    void test()
    {
        //TreeNode *p1 = new TreeNode(1);
        //TreeNode *p2 = new TreeNode(2);
        //TreeNode *p5 = new TreeNode(5);
        //TreeNode *p3 = new TreeNode(3);
        //TreeNode *p4 = new TreeNode(4);
        //TreeNode *p6 = new TreeNode(6);
        //p1->left = p2;
        //p1->right = p5;
        //p2->left = p3;
        //p2->right = p4;
        //p5->right = p6;

        TreeNode *p1 = new TreeNode(1);
        TreeNode *p2 = new TreeNode(2);
        TreeNode *p3 = new TreeNode(3);
        p1->left = p2;
        p2->left = p3;

        flatten(p1);
    }

    TreeNode *getlist(TreeNode *root)
    {
        TreeNode *tmpright = root->right;
        TreeNode *tail = root;
        if(root->left)
        {
            tail = getlist(root->left);
            root->right = root->left;
            root->left = nullptr;   //忘加这一句导致错误
            tail->right = tmpright;
        }
        if(!tmpright) return tail;
        return getlist(tmpright);
    }

    void flatten(TreeNode* root) {
        if(!root) return;
        getlist(root);
    }
};