/*Imagine you've discovered a treasure map leading to a hidden chest filled with riches. Your task is to develop methods for encoding and decoding this intricate treasure map. Just like the branching paths of a tree, encoding involves representing the map's intricate details as a series of symbols or instructions, allowing it to be stored, shared, or deciphered by others. Your ultimate goal is to design algorithms that can encode the treasure map, resembling a tree's structure, into a string format. Then, you'll need to decode this string to accurately reconstruct the original tree-like map, leading to the coveted treasure chest.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        
        vector<string> result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                result.push_back(to_string(node->val));
                q.push(node->left);
                q.push(node->right);
            } else {
                result.push_back("null");
            }
        }
        
        // Remove trailing nulls
        while (result.back() == "null") {
            result.pop_back();
        }
        
        stringstream ss;
        ss << "[";
        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) ss << ",";
            ss << result[i];
        }
        ss << "]";
        
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;
        
        data = data.substr(1, data.size() - 2); // Remove brackets
        stringstream ss(data);
        string item;
        vector<string> nodes;
        
        while (getline(ss, item, ',')) {
            nodes.push_back(item);
        }
        
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        
        size_t i = 1;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (i < nodes.size() && nodes[i] != "null") {
                node->left = new TreeNode(stoi(nodes[i]));
                q.push(node->left);
            }
            ++i;
            if (i < nodes.size() && nodes[i] != "null") {
                node->right = new TreeNode(stoi(nodes[i]));
                q.push(node->right);
            }
            ++i;
        }
        
        return root;
    }
};

// Helper function to print the tree in level order
void printTree(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    vector<string> result;
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }
    
    // Remove trailing nulls
    while (result.back() == "null") {
        result.pop_back();
    }
    
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << ",";
        cout << result[i];
    }
    cout << "]" << endl;
}

// Test the Codec
int main() {
    Codec codec;
    
    // Test case 1
    TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(4), new TreeNode(5)));
    string serialized1 = codec.serialize(root1);
    cout << "Serialized: " << serialized1 << endl; // Output: [1,2,3,null,null,4,5]
    TreeNode* deserialized1 = codec.deserialize(serialized1);
    cout << "Deserialized: ";
    printTree(deserialized1); // Output: [1,2,3,null,null,4,5]
    
    // Test case 2
    TreeNode* root2 = nullptr;
    string serialized2 = codec.serialize(root2);
    cout << "Serialized: " << serialized2 << endl; // Output: []
    TreeNode* deserialized2 = codec.deserialize(serialized2);
    cout << "Deserialized: ";
    printTree(deserialized2); // Output: []
    
    return 0;
}
