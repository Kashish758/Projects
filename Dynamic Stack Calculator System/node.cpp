#include <iostream>
#include "node.h"
using namespace std;

Node ::Node(bool sentinel)
{
    this->is_sentinel = sentinel;
    this->next = nullptr;
    this->prev = nullptr;
}

Node ::Node(int v, Node *nxt, Node *prv)
{
    this->value = v;
    this->next = nxt;
    this->prev = prv;
    is_sentinel = false;
    value = v;
}

bool Node ::is_sentinel_node()
{
    return is_sentinel;
}

int Node ::get_value()
{
    return value;
}