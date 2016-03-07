/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        if (root->left == root->right && root->right == nullptr) return to_string(root->val);
        auto s = to_string(root->val) + "<" + serialize(root->left) + "|" + serialize(root->right) + ">";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        int i, j;
        for (i = 0; i < data.length() && (data[i] == '-' || data[i] <= '9' && data[i] >= '0'); i++);
        auto val = new TreeNode(stoi(data.substr(0, i)));
        
        if (i < data.length() && data[i] == '<') {
            int d = 1;
            for (j = ++i; j < data.length(); j++) {
                if (data[j] == '<') d++;
                else if (data[j] == '>') {
                    d--;
                    if (d == 0) {
                        val->right = deserialize(data.substr(i, j - i));
                        break;
                    }
                }
                else if (d == 1 && data[j] == '|') {
                    val->left = deserialize(data.substr(i, j - i));
                    i = j + 1;
                }
            }
        }
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));