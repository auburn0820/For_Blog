#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    Node *next;
} Node;

class LinkedList {
private:
    Node *head;
    Node *tail;
    int linked_list_size;
public:
    LinkedList() {
        this->head = new Node();
        this->tail = new Node();
        this->linked_list_size = 0;
    }
    
    ~LinkedList() {
        this->delete_all_nodes();
        delete this->head;
        delete this->tail;
        cout << "Delete Linked List\n";
    }
    
    bool is_empty() {
        if(this->linked_list_size == 0)
            return true;
        else
            return false;
    }
    
    Node *set_node(int value) {
        Node *new_node = new Node();
        new_node->value = value;
        new_node->next = nullptr;
        return new_node;
    }
    
    void insert_node(int value) {
        Node *new_node = set_node(value);
        
        if(this->is_empty()) {
            head->next = new_node;
            tail->next = new_node;
        }
        else {
            tail->next->next = new_node;
            tail->next = new_node;
        }
        
        this->linked_list_size++;
    }
    
    void delete_all_nodes() {
        if(this->is_empty()) {
            cout << "Linked List is empty\n";
            return;
        }
        
        while(!is_empty()) {
            this->delete_node(this->head->next->value);
        }
        
        this->linked_list_size = 0;
    }
    
    void delete_node(int value) {
        if(this->is_empty()) {
            cout << "Linked List is empty\n";
            return;
        }
        if(!this->is_exist_node(value)) {
            cout << "Node having value " << value << " doesn't exist\n";
            return;
        }
        
        Node *node = head;
        
        while(node != nullptr) {
            if(node->next->value == value) {
                Node* temp = node->next;
                
                if(temp->next == nullptr) {
                    node->next = nullptr;
                }
                else {
                    node->next = temp->next;
                }
                
                delete temp;
                this->linked_list_size--;
                return;
            }
            
            node = node->next;
        }
    }
    
    bool is_exist_node(int value) {
        Node *node = head->next;
        
        while(node != nullptr) {
            if(node->value == value) {
                return true;
            }
            
            node = node->next;
        }
        
        return false;
    }
    
    Node* find_node(int value) {
        if(this->is_empty()) {
            cout << "Linked List is empty\n";
            return nullptr;
        }
        Node *node = head->next;
        
        while(node != nullptr) {
            if(node->value == value) {
                return node;
            }
            
            node = node->next;
        }
        
        cout << "Node having value " << value << " doesn't exist\n";
        return nullptr;
    }
    
    void print_all_nodes() {
        if(this->is_empty())
            return;
        Node *node = head->next;
        
        while(node != nullptr) {
            cout << node->value << ' ';
            node = node->next;
        }
        cout << '\n';
    }
};
