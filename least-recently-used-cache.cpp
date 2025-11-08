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

        Node* c = map[key];
        Node *p = c->prev;
        Node *n = c->next;

        p->next = n;
        n->prev = p;

        c->next = nullptr;
        c->prev = nullptr;

        Node* head_next = this->head->next;
        c->next = head_next;
        c->prev = this->head;
        head_next->prev = c;
        this->head->next = c;

        return c->val;
    }

    void put(int key, int val) {

        if(this->map.find(key) != this->map.end()) {
            Node *c = map[key];
            Node *p = c->prev;
            Node *n = c->next;

            p->next = n;
            n->prev = p;

            this->map.erase(c->key);
            delete c;
            this->remaining++;
        }


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
    cout << l->get(2) << endl;
    l->put(2, 6);
    cout << l->get(1) << endl;
    l->put(1, 5);
    l->put(1, 2);
    cout << l->get(1) << endl;
    cout << l->get(2) << endl;

    return 0;
}