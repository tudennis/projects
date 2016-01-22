/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity,
it should invalidate the least recently used item before inserting a new item.
*/

/*
1. There's a capacity limit
2. There's a timestamp associated
3. Every set/get will need to update timestamp
4. Fast retrieve least recent timestamp (smallest)
*/

#include <iostream>
#include <map>
using namespace std;

template <typename T>
struct DoubleLinkedListNode
{
    T val;
    DoubleLinkedListNode * previous;
    DoubleLinkedListNode * next;
    DoubleLinkedListNode(T& v) : val(v), previous(0), next(0) {}
};

template <typename T>
class DoubleLinkedList
{
private:
    DoubleLinkedListNode<T> * head;
    int size;
public:
    DoubleLinkedList() : head(0), size(0) {}
    ~DoubleLinkedList()
    {
        while (head != 0)
        {
            DoubleLinkedListNode<T> * p = head;
            head = head->next;
            delete p;
        }
    }

    int getSize() const { return size; }

    void moveFront(DoubleLinkedListNode<T> * n)             // Move an existing node to the front of the list
    {
        if (head == 0)
        {
            head = n;
            head->next = head;
            head->previous = head;
            return;
        }

        DoubleLinkedListNode<T> * previous = n->previous;
        DoubleLinkedListNode<T> * next = n->next;

        previous->next = next;
        next->previous = previous;

        n->next = head;
        n->previous = head->previous;
        head->previous->next = n;
        head->previous = n;

        head = n;

    }

    void addToFront(DoubleLinkedListNode<T> * n)           // Add a new node to the front of the list
    {
        ++ size;

        if (head == 0)
        {
            head = n;
            head->next = head;
            head->previous = head;
            return;
        }

        n->next = head;
        n->previous = head->previous;

        n->previous->next = n;
        head->previous = n;

        head = n;
    }

    void removeLast()                                       // Remove last node
    {
        if (head == 0)
        {
            return;
        }

        DoubleLinkedListNode<T> * last = head->previous;
        DoubleLinkedListNode<T> * newLast = last->previous;

        newLast->next = head;
        head->previous = newLast;

        delete last;
    }

    DoubleLinkedListNode<T> * last()
    {
        if (head == 0)
            return 0;
        else
        {
            return head->previous;
        }
    }

    void print()
    {
        DoubleLinkedListNode<T> * current = head;
        while (current != 0 && current->next != head)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};


template <typename K, typename V>
class LRUCache
{
private:
    DoubleLinkedList<V> list;
    map< K, DoubleLinkedListNode<V> * > m;

    int capacity;

public:
    LRUCache(int size) : capacity(size) {}
    bool get(const K& k, V& v)
    {
        if (m.find(k) != m.end())
        {
            v = m[k]->val;     // Return value
            list.moveFront(m[k]);   // Move m.find(k) to front of list
            return true;
        }

        return false;
    }

    void set(const K& k, const V& v)
    {
        if (m.find(k) != m.end())
        {
            m[k]->val = v;          // Update value
            list.moveFront(m[k]);      // Move m.find(k) to front of list
        }
        else
        {
            DoubleLinkedListNode<V> *newNode = new DoubleLinkedListNode<V>(v);

            if (m.size() < capacity)
            {
                m[k] = newNode;             // Add to map
                list.addToFront(newNode);   // Add the node to the front of the list
            }
            else
            {
                DoubleLinkedListNode<T> * last = list.last();
                // Remove from map
                list.removeLast();          // Remove the least recent node
                list.addToFront(newNode);   // Add the node to the front of the list
            }

        }
    }

    void printList()
    {
        list.print();
    }
};

int main(int argc, char ** argv)
{
    LRUCache<int, string> c(5);
    c.set(1, "one");
    c.set(2, "two");
    c.set(3, "three");
    c.set(4, "four");
    c.set(5, "five");

    c.printList();

    string v;
    cout << c.get(5, v) << endl;
    c.printList();

    return 0;
}
