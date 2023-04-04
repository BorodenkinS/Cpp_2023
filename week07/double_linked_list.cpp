#include <iostream>

using std::cout;
using std::endl;

struct Node{
    int key = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct List{
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;
};

List* create_empty_list(){
    List* list = new List;
    Node* NIL = new Node;
    list->NIL = NIL;
    list->HEAD = NIL;
    list->TAIL = NIL;
    return list;
}

List* push_front(List* list_ptr, int new_key){
    if (list_ptr == nullptr){
        return nullptr;
    }
    if (list_ptr->HEAD == list_ptr->NIL){
        Node* new_node = new Node;
        new_node->key = new_key;
        new_node->prev = list_ptr->NIL;
        new_node->next = list_ptr->NIL;
        list_ptr->HEAD = new_node;
        list_ptr->TAIL = new_node;
        list_ptr->size++;
        return list_ptr;
    }
    Node* used_head = list_ptr->HEAD;
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = used_head;
    new_node->prev = list_ptr->NIL;
    list_ptr->HEAD = new_node;
    used_head->prev = list_ptr->HEAD;
    list_ptr->size++;
    return list_ptr;
}

List* push_back(List* list_ptr, int new_key){
    if (list_ptr == nullptr){
        return nullptr;
    }
    if (list_ptr->HEAD == list_ptr->NIL){
        Node* new_node = new Node;
        new_node->key = new_key;
        new_node->prev = list_ptr->NIL;
        new_node->next = list_ptr->NIL;
        list_ptr->HEAD = new_node;
        list_ptr->TAIL = new_node;
        list_ptr->size++;
        return list_ptr;
    }
    Node* used_tail = list_ptr->TAIL;
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->prev = used_tail;
    new_node->next = list_ptr->NIL;
    list_ptr->TAIL = new_node;
    used_tail->next = list_ptr->TAIL;
    list_ptr->size++;
    return list_ptr;
}

List* insert_after(List* list_ptr, Node* prev_ptr, int new_key){
    if (list_ptr == nullptr){
        return nullptr;
    }
    if (prev_ptr == list_ptr->NIL){
        return list_ptr;
    }
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->prev = prev_ptr;
    new_node->next = prev_ptr->next;
    prev_ptr->next = new_node;
    if (new_node->next != list_ptr->NIL) {
        new_node->next->prev = new_node;
    } else {
        list_ptr->TAIL = new_node;
    }
    list_ptr->size++;
    return list_ptr;
}

void print_list(const List *list_ptr) {
    if ((list_ptr == nullptr) or (list_ptr->HEAD == list_ptr->NIL)){
        return;
    }
    Node* current = list_ptr->HEAD;
    while (current->next != list_ptr->NIL) {
        std::cout << current->key << ' ';
        current = current->next;
    }
    std::cout << current->key << std::endl;
    return;
}

void clear_list(List *list_ptr) {
    if ((list_ptr == nullptr) or (list_ptr->HEAD == list_ptr->NIL)){
        return;
    }
    Node *current = list_ptr->HEAD;
    while (current->next != list_ptr->NIL) {
        current = current->next;
        delete current->prev;
        list_ptr->size--;
    }
    delete current;
    list_ptr->size--;
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
    return;
}

void destroy_list(List *list_ptr) {
    if (list_ptr == nullptr){
        return;
    }
    if (list_ptr->HEAD == list_ptr->NIL) {
        delete list_ptr->NIL;
        delete list_ptr;
        return;
    }
    Node *current = list_ptr->HEAD;
    while (current->next != list_ptr->NIL) {
        current = current->next;
        delete current->prev;
    }
    delete current;
    delete list_ptr->NIL;
    delete list_ptr;
    return;
}

Node* find_key(List* list_ptr, int key){
    if (list_ptr->HEAD == list_ptr->NIL){
        return list_ptr->NIL;
    }
    Node* current = list_ptr->HEAD;
    while (current != nullptr){
        if (current->key == key){
            return current;
        }
        current = current->next;
    }
    return current;
}

void remove_key(List* list_ptr, int key){
    if ((list_ptr == nullptr) or (list_ptr->HEAD == list_ptr->NIL)){
        return;
    }
    Node* current = list_ptr->HEAD;
    while (current != nullptr){
        if (current->key == key){
            break;
        }
        current = current->next;
    }
    if (current != list_ptr->NIL){
        if (current != list_ptr->HEAD){
            current->prev->next = current->next;
        } else {
            current->next->prev = list_ptr->NIL;
            list_ptr->HEAD = current->next;
        }
        if (current != list_ptr->TAIL){
            current->prev->next = current->next;
        } else {
            current->prev->next = list_ptr->NIL;
            list_ptr->TAIL = current->prev;
        }
    }
    delete current;
    return;
}

int main() {
  return 0;
}