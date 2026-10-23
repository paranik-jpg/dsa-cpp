#include <bits/stdc++.h>
using namespace std;

// This structure defines a node in a Binary Search Tree
struct TreeNode {
    // This stores the value of the node
    int val;
    // Pointer to the left child
    TreeNode* left;
    // Pointer to the right child
    TreeNode* right;

    // Constructor initializes node with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// This class contains the brute force solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        TreeNode* curr = root;

        while(curr != NULL) {
            if(curr->left == NULL) {
                inOrder.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if(prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    inOrder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inOrder;
    }

    bool twoSum(vector<int>& nums, int target) {
        map<int,int> mapy;
        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            int need = target - a;
            if(mapy.find(need) != mapy.end()) {
                return true;
            }
            mapy[a] = i;
        }
        return false;
    }

    // Function to check if there exists a pair with given sum in BST
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder = inorderTraversal(root);
        return twoSum(inorder, k);
    }
};

// Function to print inorder traversal of BST
void printInOrder(TreeNode* root) {
    // If node is null, stop recursion
    if (!root) return;
    // Visit left child
    printInOrder(root->left);
    // Print current node
    cout << root->val << " ";
    // Visit right child
    printInOrder(root->right);
}

// Driver code
int main() {
    // Create sample BST
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Print inorder traversal
    cout << "Tree Initialized: ";
    printInOrder(root);
    cout << endl;

    // Create solution object
    Solution solution;

    // Define target sum
    int target = 32;

    // Call function to check for pair
    bool exists = solution.findTarget(root, target);

    // Print result
    if (exists) cout << "Pair with sum " << target << " exists." << endl;
    else cout << "Pair with sum " << target << " does not exist." << endl;

    return 0;
}
