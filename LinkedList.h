#ifndef CPP_LABS_LINKEDLIST_H
#define CPP_LABS_LINKEDLIST_H

#include <iostream>

using namespace std;

template<class T>
struct Node {
    int key;
    T data;
    Node *next = nullptr;

    Node(int key, T data, Node *next) : key(key), data(data), next(next) {}
};

template<class T>
struct LinkedList {
    Node<T> *pBeg = nullptr;
    Node<T> *pEnd = nullptr;

public:
    void add(int key, T data);

    void first(int key, T data);

    Node<T> *find(int key);

    Node<T> *findPrev(int key);

    Node<T> *remove(int key);
};

template<class T>
void LinkedList<T>::add(int key, T data) {
    if (pBeg == nullptr) {
        first(key, data);
        return;
    }

    auto *pv = new Node<T>(key, data, nullptr);
    pEnd->next = pv;
    pEnd = pv;
}

template<class T>
void LinkedList<T>::first(int key, T data) {
    pBeg = new Node<T>(key, data, nullptr);
    pEnd = pBeg;
}

template<class T>
Node<T> *LinkedList<T>::find(int key) {
    Node<T> *cur = pBeg;
    while (cur->key != key) {
        cur = cur->next;
    }
    return cur;
}

template<class T>
Node<T> *LinkedList<T>::findPrev(int key) {
    Node<T> *prev = nullptr;
    Node<T> *cur = pBeg;
    while (cur->key != key) {
        prev = cur;
        cur = cur->next;
    }
    return cur->key == key ? prev : nullptr;
}

template<class T>
Node<T> *LinkedList<T>::remove(int key) {
    Node<T> *prev = findPrev(key);
    Node<T> *cur = find(key);
    if (cur == pBeg) {
        pBeg = nullptr;
        return cur;
    }
    prev->next = cur->next;
    return cur;
}

struct Bus {
    int number;
    const char *driver;
    int route;

    Bus(int _number, const char *_driver, int _route) {
        number = _number;
        driver = _driver;
        route = _route;
    }
};

struct Park {
    LinkedList<Bus> *inPark = new LinkedList<Bus>;
    LinkedList<Bus> *onRoute = new LinkedList<Bus>;

    void addBus(Bus bus);

    void goOnRoute(Bus bus);

    void goInPark(Bus bus);

    void print();
};

#endif //CPP_LABS_LINKEDLIST_H
