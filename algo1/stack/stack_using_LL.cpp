#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data=data;
        next = NULL;
    }
};
template <typename T>
class Stack
{
public:
    Node<T> *head;
    int size;

    Stack()
    {
        head = NULL;
        size = 0;
    };
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(T ele)
    {
        Node<T> *n = new Node<T>(ele);
        n->next = head;
        head = n;
        size++;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
    T top()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return 0;
        }
        return head->data;
    }
};

int main()
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "size:" << s1.getSize()<< endl;
    cout << "Top element:" << s1.top() << endl;
    s1.pop();
    cout << "Top element:" << s1.top() << endl;

    return 0;
}