#include "deque.h"

Deque::Deque(int n): max(n)
{
    start = 0;
    end = 0;
    size = 0;
    array = new int [n];
}

Deque::~Deque()
{
    delete [] array;
}

bool Deque::is_empty()
{
    if (size == 0)
    {
        return true;
    }
    return false;
}

bool Deque::is_full()
{
    if (size == max)
    {
        return true;
    }
    return false;
}

int Deque::add_start(int key)
{
    if (is_full())
    {
        return 1;
    }

    if (is_empty())
    {
        start = 0;
        end = 0;
    }
    else 
    {
        if (start == 0)
        {
            start = max - 1;
        }
        else 
        {
            start --;
        }
    }

    array[start] = key;
    size++;
    return 0;
}

int Deque::add_end(int key)
{
    if (is_full())
    {
        return 1;
    }

    if (is_empty())
    {
        start = 0;
        end = 0;
    }
    else 
    {
        if (end == max)
        {
            end = 0;
        }
        else 
        {
            end ++;
        }
    }

    array[end] = key;
    size++;
    return 0;
}

int Deque::remove_start()
{
    if (is_empty())
    {
        return -999;
    }

    int key = array[start];

    if (start == end)
    {
        start = 0;
        end = 0;
    }
    else
    {
        if (start == max - 1)
        {
            start = 0;
        }
        else
        {
            start++;
        }
    }
    size--;
    return key;
}

int Deque::remove_end()
{
    if (is_empty())
    {
        return -999;
    }

    int key = array[end];

    if (start == end)
    {
        start = 0;
        end = 0;
    }
    else
    {
        if (end == 1)
        {
            end = max - 1;
        }
        else
        {
            end++;
        }
    }
    size--;
    return key;
}

int Deque::get_element(int index)
{
    return array[index];
}

int Deque::get_end()
{
    return end;
}
int Deque::get_start()
{
    return start;
}

