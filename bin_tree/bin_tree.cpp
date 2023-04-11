#include <iostream>

using namespace std;

struct Node{
    int key = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* root = nullptr;
};

struct Tree{
    Node* ROOT = nullptr;
    Node* NIL = nullptr;
};

Tree* create_empty_tree(){
    Node* NIL = new Node;
    Tree* tree = new Tree;
    tree->NIL = NIL;
    tree->ROOT = NIL;
    return tree;
}

Tree* add_element(Tree* tree_ptr, int key){
    if (tree_ptr == nullptr){
        return nullptr;
    }
    if (tree_ptr->ROOT == tree_ptr->NIL){
        Node* new_node = new Node;
        new_node->key = key;
        new_node->left = tree_ptr->NIL;
        new_node->right = tree_ptr->NIL;
        new_node->root = tree_ptr->NIL;
        tree_ptr->ROOT = new_node;
        return tree_ptr;
    }
    Node* current = tree_ptr->ROOT;
    while((current->left != tree_ptr->NIL) or (current->right != tree_ptr->NIL)){
        if (key < current->key){
            current = current->left;
        } else {
            current = current->right;
        }
    }
    Node* new_node = new Node;
    new_node->key = key;
    new_node->left = tree_ptr->NIL;
    new_node->right = tree_ptr->NIL;
    new_node->root = current;
    if (current->right != tree_ptr->NIL){
        if (key < current->right->key){
            current->right->left = new_node;
        } else {
            current->right->right = new_node;
        }
    } else if (current->left != tree_ptr->NIL){
        if (key < current->left->key){
            current->left->left = new_node;
        } else {
            current->left->right = new_node;
        }
    } else {
        if (key < current->key){
            current->left = new_node;
        } else {
            current->right = new_node;
        }
    }
    return tree_ptr;
}

Node* find_element(Tree* tree_ptr, int key){
    if ((tree_ptr == nullptr) or (tree_ptr->ROOT == tree_ptr->NIL)){
        return nullptr;
    }
    Node* current = tree_ptr->ROOT;
    while((current->left != tree_ptr->NIL) or (current->right != tree_ptr->NIL)){
        if (key < current->key){
            current = current->left;
        } else if (key > current->key){
            current = current->right;
        } else {
            return current;
        }
    }
    if (current->key == key){
        return current;
    } else{
        if ((current->left != tree_ptr->NIL) & (current->left->key == key)){
            return current->left;
        } else if ((current->right != tree_ptr->NIL) & (current->right->key == key)){
            return current->left;
        } else {
            return nullptr;
        }
    }
}

int main(){
    Tree* tree = create_empty_tree();
    tree = add_element(tree, 10);
    tree = add_element(tree, 12);
    tree = add_element(tree, 11);
    tree = add_element(tree, 9);
    if (find_element(tree, 9)->key == 9){
        cout << "OK" << endl;
    }
    return 0;
}