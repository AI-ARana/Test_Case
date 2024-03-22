/*Write a function that inserts a list of n numbers into a 
binary search tree that runs at O(n log n) time.*/
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }

    if (val < root->val) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

TreeNode* constructBST(std::vector<int>& nums) {
    TreeNode* root = nullptr;
    for (int num : nums) {
        insert(root, num);
    }
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    std::vector<int> nums = {5, 2, 7, 4, 1, 8, 3};
    TreeNode* root = constructBST(nums);

    std::cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
