#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        return post_order_traversal_non_recursive(root);
    }
private:
    void post_order_traversal_recursive(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        else {
            post_order_traversal_recursive(root->left, v);
            post_order_traversal_recursive(root->right, v);
            v.push_back(root->val);
            return;
        }
    }
    vector<int> post_order_traversal(TreeNode* root) {
        vector<int> v;
        post_order_traversal_recursive(root, v);
        return v;
    }

    vector<int> post_order_traversal_non_recursive(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v {};
        if (root != nullptr) {
            s.push(root);
        }
        else {
            return v;
        }
        TreeNode* last {};
        while (s.size() != 0) {
            auto n = s.top();
            if (n->left == nullptr && n->right == nullptr) {
                s.pop();
                v.push_back(n->val);
                last = n;
            }
            else if ( last != nullptr && (n->left == last || n->right == last)) {
                s.pop();
                v.push_back(n->val);
                last = n;
            }
            else {
                if (n->right != nullptr) {
                    s.push(n->right);
                }
                if (n->left != nullptr) {
                    s.push(n->left);
                }
            }
        }

        return v;
    }
};

int main()
{
    TreeNode node_1(1);
    TreeNode node_2(2);

    TreeNode* root = &node_1;
    node_1.right = &node_2;

    Solution x;
    auto t = x.postorderTraversal(root);

    for (auto x:t) {
        cout << x << endl;
    }

    return 0;
}