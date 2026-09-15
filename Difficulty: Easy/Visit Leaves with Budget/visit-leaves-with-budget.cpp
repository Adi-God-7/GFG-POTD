/* Binary Tree Node Structure
class Node {
	public:
	int data;
	Node *left;
	Node *right;

	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
};
*/

class Solution {
	public:
	int getCount(Node *root, int k) {
		// code here
		int result = 0;
		int depth = 1;
		queue<Node*>q;
		q.push(root);

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i<size; ++i) {
				Node *node = q.front(); q.pop();
				if (node->left == nullptr && node->right == nullptr &&
				k >= depth) {
					result++;
					k -= depth;
				}
				if (node->left != nullptr)q.push(node->left);
				if (node->right != nullptr)q.push(node->right);
			}
			depth++;
		}
		return result;
	}
};