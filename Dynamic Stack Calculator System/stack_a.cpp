#include <iostream>
#include "stack_a.h"
#include <stdexcept>
using namespace std;

Stack_A ::Stack_A()
{

    size = 0;
}

void Stack_A ::push(int data)
{

    if (size == 1024)
    {
        throw runtime_error("Stack Full");
    }
    else
    {
        stk[size] = data;
        size = size + 1;
    }
}

int Stack_A ::pop()
{

    if (size == 0)
    {
        throw runtime_error("Empty Stack");
    }
    else
    {
        size = size - 1;
        return stk[size];
    }
}

int Stack_A ::get_element_from_top(int idx)
{

    if (size <= 0 || idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return stk[size - idx - 1];
    }
}

int Stack_A ::get_element_from_bottom(int idx)
{

    if (size <= 0 || idx >= size)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return stk[idx];
    }
}

void Stack_A ::print_stack(bool top_or_bottom)
{

    if (top_or_bottom == 1)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << stk[i] << endl;
        }
    }

    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << stk[i] << endl;
        }
    }
}

int Stack_A ::add()
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

int Stack_A ::subtract()
{

    if (size < 2)
    {
        throw runtime_error("Not Enough Arguments");
    }
    else
    {
        int operand2 = pop();
        int operand1 = pop();
        int difference = operand1 - operand2;
        push(difference);
        return difference;
    }
}

int Stack_A ::multiply()
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

int Stack_A ::divide()
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

int *Stack_A ::get_stack()
{

    return &stk[0];
}

int Stack_A ::get_size()
{

    return size;
}
