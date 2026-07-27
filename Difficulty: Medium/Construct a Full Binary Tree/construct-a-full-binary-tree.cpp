/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {

        unordered_map<int, int> pos;

for (int i = 0; i < preMirror.size(); i++) {
    pos[preMirror[i]] = i;
}

function<Node*(int, int, int)> build =
[&](int preStart, int mirrorStart, int size) -> Node* {

    if (size <= 0) {
        return nullptr;
    }

    Node* root = new Node(pre[preStart]);

    if (size == 1) {
        return root;
    }

    int leftRoot = pre[preStart + 1];

    int p = pos[leftRoot];

    int rightSize = p - mirrorStart - 1;
    int leftSize = size - 1 - rightSize;

    root->left = build(
        preStart + 1,
        p,
        leftSize
    );

    root->right = build(
        preStart + 1 + leftSize,
        mirrorStart + 1,
        rightSize
    );

    return root;
};

return build(0, 0, pre.size());
    }
};