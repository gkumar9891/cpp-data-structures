#include <bits/stdc++.h>
using namespace std;

class LRUCache {

class Node {
    public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->val = val;
        this->key = key;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


public:
    int capacity;
    int remaining;
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->remaining = capacity;
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);

        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    int get(int key) {
        if(map.find(key) == map.end()) {
            return -1;
        }

        Node* n = map[key];
        Node *t = n->prev;
        t->next = n;
        n->next->prev = t;

        n->next = this->head->next;
        n->prev = this->head;
        this->head->next = n;

        return n->val;
    }

    void put(int key, int val) {
        if(this->remaining == 0) {
            Node *n = this->tail->prev;
            Node *t = n->prev;
            t->next = this->tail;
            this->tail->prev=t;
            this->map.erase(n->key);
            delete n;
            this->remaining++;
        }

        Node *n = new Node(key, val);
        Node* t = this->head->next;
        n->next = t;
        n->prev = this->head;
        this->head->next = n;
        t->prev = n;

        this->map[key] = n;

        this->remaining--;
    }
};


int main() {

    LRUCache* l = new LRUCache(2);
    l->put(1, 1);
    l->put(2, 2);
    l->get(1);
    l->put(3, 3);
    l->get(2);
    l->put(4, 4);
    l->get(1);
    l->get(3);
    l->get(4);


    return 0;
}