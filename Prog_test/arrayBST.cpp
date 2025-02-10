//Write an algorithm and program to converting the array to BST(inorder, preorder and postorder).	

#include <iostream>

using namespace std;

// Definition of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to convert sorted array to BST
TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) {
        return nullptr;
    }

    // Find the middle element and make it the root
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    // Recursively construct left and right subtrees
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Function to perform in-order traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Function to perform pre-order traversal of the BST
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform post-order traversal of the BST
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    system("cls");
    // Convert sorted array to BST
    TreeNode* root = sortedArrayToBST(arr, 0, n - 1);

    // Print the BST using in-order traversal
    cout << "In-order Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    // Print the BST using pre-order traversal
    cout << "Pre-order Traversal of BST: ";
    preorderTraversal(root);
    cout << endl;

    // Print the BST using post-order traversal
    cout << "Post-order Traversal of BST: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
