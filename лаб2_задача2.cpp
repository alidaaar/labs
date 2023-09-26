#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}


DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* new_node = new DoublyLinkedListNode(5);
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (llist == nullptr) {
        return new_node;
    }

    if (data <= llist->data) {
        new_node->next = llist;
        llist->prev = new_node;
        return new_node;
    }

    DoublyLinkedListNode* current = llist;
    while (current->next != nullptr && current->next->data < data) {
        current = current->next;
    }

    if (current->next != nullptr) {
        new_node->next = current->next;
        current->next->prev = new_node;
    }

    current->next = new_node;
    new_node->prev = current;

    return llist;
}

