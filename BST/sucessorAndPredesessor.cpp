void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (root == NULL)
        return;
 
    // Search for given key in BST.
    while (root != NULL) {
 
        // If root is given key.
        if (root->key == key) {
 
            // the minimum value in right subtree
            // is predecessor.
            if (root->right) {
                suc = root->right;
                while (suc->left)
                    suc = suc->left;
            }
 
            // the maximum value in left subtree
            // is successor.
            if (root->left) {
                pre = root->left;
                while (pre->right)
                    pre = pre->right;
            }
 
            return;
        }
 
        // If key is greater than root, then
        // key lies in right subtree. Root
        // could be predecessor if left
        // subtree of key is null.
        else if (root->key < key) {
            pre = root;
            root = root->right;
        }
 
        // If key is smaller than root, then
        // key lies in left subtree. Root
        // could be successor if right
        // subtree of key is null.
        else {
            suc = root;
            root = root->left;
        }
    }
       
       


}
