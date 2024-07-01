#include <iostream>
#include <stdexcept>
#include "node.h"
#include "list.h"
using namespace std;

List ::List()
{
    size = 0;
    sentinel_head = new Node(true);
    sentinel_tail = new Node(true);
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
}

List ::~List()
{
    Node *currptr = sentinel_head->next;
    while (currptr != sentinel_tail)
    {
        Node *next_currptr = currptr->next;
        delete currptr;
        currptr = next_currptr;
    }
    delete sentinel_head;
    delete sentinel_tail;
}

void List ::insert(int v)
{
    Node *node_to_be_inserted = new Node(v, sentinel_tail, sentinel_tail->prev);
    sentinel_tail->prev->next = node_to_be_inserted;
    sentinel_tail->prev = node_to_be_inserted;
    size = size + 1;
}

int List ::delete_tail()
{
    if (size == 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        int v = sentinel_tail->prev->get_value();
        Node *node_to_be_deleted = sentinel_tail->prev;
        node_to_be_deleted->prev->next = sentinel_tail;
        sentinel_tail->prev = node_to_be_deleted->prev;
        delete node_to_be_deleted;
        size = size - 1;
        return v;
    }
}

int List ::get_size()
{
    return size;
}

Node *List ::get_head()
{
    return sentinel_head;
}