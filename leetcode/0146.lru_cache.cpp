#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    Node(int key, int value) : key(key), value(value) { }
    int key, value;
    Node *next, *prev;
};

class DoubleList {
public:
    DoubleList()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addLast(Node *x)
    {
        x->prev = tail->prev;
        x->prev->next = x;
        x->next = tail;
        tail->prev = x;
        ++size;
    }
    void remove(Node *x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        --size;
    }
    Node* removeFirst()
    {
        if (head->next == tail) return nullptr;
        Node *first = head->next;
        remove(first);
        return first;
    }
    Node *head, *tail;
    int size;
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity)
    {
        cache = new DoubleList();
    }
    int get(int key)
    {
        if (map.find(key) == map.end()) {
            return -1;
        }
        makeRecently(key);
        return map[key]->value;
    }
    void put(int key, int value)
    {
        if (map.find(key) != map.end()) {
            deleteKey(key);
            addRecently(key, value);
            return ;
        }

        if (capacity == cache->size) {
            removeLeastRecently();
        }

        addRecently(key, value);
    }

    // 将某个key调整到最近使用
    void makeRecently(int key)
    {
        Node *x = map[key];
        cache->remove(x);
        cache->addLast(x);
    }
    // 添加最近使用的元素
    void addRecently(int key, int value)
    {
        Node *x = new Node(key, value);
        cache->addLast(x);
        map[key] = x;
    }
    // 删除某一个key
    void deleteKey(int key)
    {
        Node *x = map[key];
        cache->remove(x);
        map.erase(key);
    }
    // 删除最久未使用的key
    void removeLeastRecently()
    {
        Node *deletedNode = cache->removeFirst();
        int deletedKey = deletedNode->key;
        map.erase(deletedKey);
    }
private:
    int capacity;
    unordered_map<int, Node*> map;
    DoubleList *cache;
};

int main()
{
    return 0;
}
