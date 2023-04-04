#include <iostream>

using std::cout;
using std::endl;

struct Node{
    int key = 0;
    Node* next = nullptr;
};

void push_back(Node*& head, int new_key){
    if (head == nullptr){
        head = new Node;
        head->key = new_key;
        return;
    }
    Node* current = head;
    while (current->next != nullptr){
        current = current->next;
    }
    current->next = new Node;
    current->next->key = new_key;
}

void push_front(Node*& head, int new_key){
    if (head == nullptr){
        head = new Node;
        head->key = new_key;
        return;
    }
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = head;
    head = new_node;
}

void insert_after(Node*& prev_ref, int new_key){
    if (prev_ref == nullptr){
        return;
    }
    Node* current_next = prev_ref->next;
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = current_next;
    prev_ref->next = new_node;
}

void destroy_list(Node*& head_ref){
    if (head_ref == nullptr) {
        return;
    }
    while (head_ref->next != nullptr){
        Node* current = head_ref->next->next;
        delete head_ref->next;
        head_ref->next = current;
    }
    delete head_ref->next;
    head_ref = nullptr;
}

void print_list(Node* head_ref){
    if (head_ref == nullptr) {
        cout << endl;
        return;
    }
    if (head_ref->next == nullptr) {
        cout << head_ref->key << endl;
        return;
    }
    Node *current = head_ref;
    while (current->next != nullptr) {
        cout << current->key << ' ';
        current = current->next;
    }
    cout << current->key << endl;
    return;
}

Node* find(Node* head_ref, int key){
    Node* current = head_ref;
    while (current != nullptr){
        if (current->key == key){
            return current;
        }
        current = current->next;
    }
    return current;
}

void remove_key(Node*& head_ref, int key){
    if (head_ref == nullptr){
        return;
    }
    if (head_ref->key == key){
        Node* new_head = head_ref->next;
        delete head_ref;
        head_ref = new_head;
        return;
    }
    Node* current = head_ref;
    while (current->next != nullptr){
        if (current->next->key == key){
            Node* buffer_current = current->next->next;
            delete current->next;
            current->next = buffer_current;
            return;
        }
        current = current->next;
    }
}

int main() {
  return 0;
}