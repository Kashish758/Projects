#include <iostream>
#include "stack_b.h"
#include <stdexcept>
using namespace std;

Stack_B ::Stack_B()
{

    capacity = 1024;
    size = 0;
    stk = new int[capacity];
}

Stack_B ::~Stack_B()
{

    delete[] stk;
}

void Stack_B ::push(int data)
{

    if (size >= capacity)
    {
        capacity = capacity * 2;
        try{
            int *arr1 = new int[capacity];
            for (int i = 0; i <= size; i++)
            {
                arr1[i] = stk[i];
            }
            delete[] stk;
            stk = arr1;
        }
        catch(bad_alloc){
            throw runtime_error("Out of Memory");
        }
    }

    stk[size] = data;
    size = size + 1;
}

int Stack_B ::pop()
{

    if (size == 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        size = size - 1;
        if (size < 0.5 * capacity && capacity >= 2048)
        {
            capacity = 0.5*capacity;
            int *arr1 = new int[capacity];
            for (int i = 0; i <= size; i++)
            {
                arr1[i] = stk[i];
            }
            delete[] stk;
            stk = arr1;
        }
        return stk[size];
    }
}

int Stack_B ::get_element_from_top(int idx)
{

    if (size <= 0 || idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return (stk[size - 1 - idx]);
    }
}

int Stack_B ::get_element_from_bottom(int idx)
{

    if (size <= 0 || idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return (stk[idx]);
    }
}

void Stack_B ::print_stack(bool top_or_bottom)
{

    if (top_or_bottom == 1)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << (stk[i]) << endl;
        }
    }
    else
    {
        for (int i = 0; i < size - 1; i++)
        {
            cout << (stk[i]) << endl;
        }
    }
}

int Stack_B ::add()
{

    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int operand2 = pop();
        int operand1 = pop();
        int sum = operand1 + operand2;
        push(sum);
        return sum;
    }
}

int Stack_B ::subtract()
{

    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    int operand2 = pop();
    int operand1 = pop();
    int difference = operand1 - operand2;
    push(difference);
    return difference;
}

int Stack_B ::multiply()
{

    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int operand2 = pop();
        int operand1 = pop();
        int product = operand1 * operand2;
        push(product);
        return product;
    }
}

int Stack_B ::divide()
{

    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int operand2 = pop();
        int operand1 = pop();
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
            push(dividend);
            return dividend;
        }
    }
}

int *Stack_B ::get_stack()
{

    return stk;
}

int Stack_B ::get_size()
{

    return size;
}
