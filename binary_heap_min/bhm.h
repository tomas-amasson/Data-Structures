#ifndef BINARY_HEAP_MIN_H
#define BINARY_HEAP_MIN_H


/* ACCESS

left son    2i + 1
right son   2i + 2
father      floor((i - 1) / 2)
*/

/* MAIN FUNCTIONALITIES

ENQEUE:     O(1) + SHIFT DOWN
DEQEUE:     O(1) + SHIFT UP

SHIFT UP  : O(log n)
SHIFT DOWN: O(log n)

*/

class bheapm
{
    private:
        int *array;
        int size;

    public:
        bheapm();
    
        void enqeue(int key);
        void deqeue();

        void shift_up(int key);
        void shift_down(int key);
};

#endif