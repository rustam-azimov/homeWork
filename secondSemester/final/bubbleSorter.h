#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

/**
  * @file bubbleSort.h
  * Implementation of container class BubbleSorter.
  */

/// @class BubbleSorter
/// This class to sort template array.
template <typename T>
class BubbleSorter
{
public:
    /// N - type of compare.
    template <typename N>
    /// Gets template array, his size and compare.
    void sort(T array[], const int arraySize, N &comp);
private:
    /// This method swap two array's elements.
    void swap(T &a, T &b)
    {
        T c = a;
        a = b;
        b = c;
    }
};

template <typename T>
template <typename N>
void BubbleSorter<T>::sort(T array[], const int arraySize, N &comp)
{
    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < arraySize - 1; i++)
            if (comp(array[i], array[i + 1]))
            {
                swap(array[i], array[i + 1]);
                isSorted = false;
            }
    }
}

#endif // BUBBLESORTER_H
