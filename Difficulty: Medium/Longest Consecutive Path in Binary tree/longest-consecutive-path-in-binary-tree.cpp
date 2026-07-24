class Solution {
public:
    int ans = 1;

    int dfs(Node* root) {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int curr = 1;

        if (root->left != nullptr &&
            root->left->data == root->data + 1) {
            curr = max(curr, left + 1);
        }

        if (root->right != nullptr &&
            root->right->data == root->data + 1) {
            curr = max(curr, right + 1);
        }

        ans = max(ans, curr);

        return curr;
    }

    int longestConsecutive(Node* root) {
        if (root == nullptr)
            return -1;

        dfs(root);

        return (ans == 1) ? -1 : ans;
    }
};