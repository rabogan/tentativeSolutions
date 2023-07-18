class Solution {
public:
    pair<Node*,Node*>treeToDoublyLinkedTraversal(Node*root){
        if(!root)
            return{nullptr,nullptr};
        
        pair<Node*,Node*>left = treeToDoublyLinkedTraversal(root->left);
        pair<Node*,Node*>right = treeToDoublyLinkedTraversal(root->right);
        
        Node*first = root;
        Node*last = root;
        
        if(left.first){
            root->left = left.second;
            left.second->right = root;
            first = left.first;
        }
        if(right.first){
            root->right = right.first;
            right.first->left = root;
            last = right.second;
        }
        return{first,last};
    }
    
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return nullptr;
        
        pair<Node*,Node*>dll = treeToDoublyLinkedTraversal(root);
        dll.first->left = dll.second;
        dll.second->right = dll.first;
        
        return dll.first;
    }
};
