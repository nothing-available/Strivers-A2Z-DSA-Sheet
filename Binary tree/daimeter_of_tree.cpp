class Solution{
  private:
  int height(Node* root, int &diameter)
  {
    if(root == NULL) return 0;
    int leftSubtree = height(root->left);
    int rightSubtree= height(root->right);
    
    diameter = max(diameter, leftSubtree+rightSubtree);
    return 1 + max(leftSubtree + rightSubtree);
  }
  public:
  int diameterOfTree(Node* root)
  {
    int diameter = 0
    height(root,diameter);
    return diameter;
};
  
  // TC - O(N)
  // sc - O(1) + O(H)
  
// [Detailed Sol.](https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/)
