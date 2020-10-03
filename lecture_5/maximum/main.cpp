typedef pair<int, int> ii;
#define INF 1e9

//the first return element is the maximum path from a leaf to root, the second return element is the maximum path we are looking for in the subtree with root root
ii r(Node* root){
    if(root->left == NULL && root->right == NULL) return make_pair(root->data, -INF);
    if(root->left != NULL && root->right == NULL) return make_pair(r(root->left).first + root->data, r(root->left).second);
    if(root->left == NULL && root->right != NULL) return make_pair(r(root->right).first +root->data, r(root->right).second);
    
    ii pleft = r(root->left), pright = r(root->right);
    int left = pleft.first, right = pright.first;
    int M = max(pleft.second, pright.second);
    
    return make_pair(max(left, right)+root->data, max(M, left+right+root->data));
    
}

int maxPathSum(Node* root)
{ 
    return r(root).second;
}
