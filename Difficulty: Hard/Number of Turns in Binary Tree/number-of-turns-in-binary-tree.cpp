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
}; */

class Solution {
  public:
    virtual bool pathStore(Node *root, int tar, vector<char> &path){
      if(!root) return false;
      if(root->data == tar) return true;

      path.push_back('L');
      if(pathStore(root->left, tar, path)) return true;
      path.pop_back();      

      path.push_back('R');
      if(pathStore(root->right, tar, path)) return true;
      path.pop_back();

      return false;

    }

    virtual int numberOfTurns(Node* root, int p, int q){
      vector<char> pathP, pathQ;
      pathStore(root, p, pathP);
      pathStore(root, q, pathQ);

      int i=0;
      while(i<pathP.size() && i<pathQ.size() && pathP[i]==pathQ[i]) i++;



      vector<char> path;
      for(int j=pathP.size()-1; j>=i; j--){
        path.push_back(pathP[j]);  
      }
      for(int j=i; j<pathQ.size(); j++){
        path.push_back(pathQ[j]);  
      }


      if(path.size() < 2) return -1;

      int turn=0;
      for(int i=1; i<path.size(); i++) if(path[i]!=path[i-1]) turn++;

      return turn==0? -1: turn;
    }
};