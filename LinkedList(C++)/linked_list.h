#ifndef LIST_H
#define LIST_H
#include <iostream>

template<typename T>
struct ListNode
{
    T data;
    struct ListNode* next;
    ListNode(T data, ListNode* next = nullptr) :data(data), next(next) {}

};

template<typename T>
class LinkedList
{
private:
    size_t size;
    ListNode<T>* head;
    ListNode<T>* tail;
public:
    LinkedList() : head(nullptr), size(0), tail(nullptr) {}

    LinkedList(ListNode<T>* head) : head(head), tail(head), size(1) {}

    ~LinkedList()
    {
        clear();
    }

    void clear()
    {
        ListNode<T>* current = head;
        while (current != nullptr)
        {
            ListNode<T>* temp = current->next;
            delete current;
            current = temp;
        }
        head = nullptr;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push_back(ListNode<T>* node)
    {
        if (head == nullptr)
        {
            head = node;
            tail = head;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
        size++;
    }

    void push_front(ListNode<T>* node)
    {
        if (head == nullptr)
        {
            head = node;
            tail = head;
        }
        else
        {
            node->next = head;
            head = node;
        }
        size++;
    }

    void push_back(T data)
    {
        ListNode<T>* node = new ListNode<T>(data);
        push_back(node);
    }

    void push_front(T data)
    {
        ListNode<T>* node = new ListNode<T>(data);
        push_front(node);

    }

    const T& operator[](int index) const
    {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of range");
        ListNode<T>* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    size_t getSize()
    {
        return size;
    }
};

#endif

