#include <iostream>
#include "node.h"
#include "stack_c.h"
#include <stdexcept>
#include "list.h"
using namespace std;

Stack_C ::Stack_C()
{
    stk = new List();
}

Stack_C ::~Stack_C()
{
    delete stk;
}

void Stack_C ::push(int data)
{
    try{
        stk->insert(data);
    }
    catch(bad_alloc){
        throw runtime_error("Out of Memory");
    }
}

int Stack_C ::pop()
{
    if (stk->get_size() == 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        return stk->delete_tail();
    }
}

int Stack_C ::get_element_from_top(int idx)
{
    if (idx < 0 || idx >= stk->get_size())
    {
        throw runtime_error("Index out of Range");
    }
    else
    {
        Node *currptr = stk->get_head()->next;
        for (int i = 0; i < stk->get_size() - idx - 1; i++)
        {
            currptr = currptr->next;
        }
        return currptr->get_value();
    }
}

int Stack_C ::get_element_from_bottom(int idx)
{
    if (idx < 0 || idx >= stk->get_size())
    {
        throw runtime_error("Index out of Range");
    }
    else
    {
        Node *currptr = stk->get_head()->next;
        for (int i = 0; i < idx; i++)
        {
            currptr = currptr->next;
        }
        return currptr->get_value();
    }
}

void Stack_C ::print_stack(bool top_or_bottom)
{
    if (!top_or_bottom)
    {
        Node *currptr = stk->get_head()->next;
        while (!currptr->is_sentinel_node())
        {
            cout << currptr->get_value() << endl;
            currptr = currptr->next;
        }
    }
    else
    {
        Node *currptr = stk->get_head()->next;
        while (!currptr->is_sentinel_node())
        {
            currptr = currptr->next;
        }
        while (!currptr->is_sentinel_node())
        {
            cout << currptr->get_value() << endl;
            currptr = currptr->prev;
        }
    }
}

int Stack_C ::add()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int operand2 = stk->delete_tail();
        int operand1 = stk->delete_tail();
        stk->insert(operand1 + operand2);
        return (operand1 + operand2);
    }
}

int Stack_C ::subtract()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int operand2 = stk->delete_tail();
        int operand1 = stk->delete_tail();
        int difference = operand1 - operand2;
        stk->insert(difference);
        return difference;
    }
}

int Stack_C ::multiply()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int operand2 = stk->delete_tail();
        int operand1 = stk->delete_tail();
        int product = operand1 * operand2;
        stk->insert(product);
        return product;
    }
}

int Stack_C ::divide()
{
    if (stk->get_size() < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int operand2 = stk->delete_tail();
        int operand1 = stk->delete_tail();
        if (operand2 == 0)
        {
            throw runtime_error("Division by Zero Error");
        }
        else
        {
            int dividend = operand1 / operand2;
            if (operand1 * operand2 < 0)
            {
                dividend = dividend - 1;
            }
            stk->insert(dividend);
            return dividend;
        }
    }
}

List *Stack_C ::get_stack()
{
    return stk;
}

int Stack_C ::get_size()
{
    return stk->get_size();
}
