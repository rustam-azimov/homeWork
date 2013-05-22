#ifndef UNIQUELIST_H
#define UNIQUELIST_H

#include "pointerList.h"

/**
 * @file uniqueList.h
 *
 * Implementation of container class UniqueList.
 */

/// @namespace uniqueListException Contains classes for working with throw.
namespace uniqueListException
{
    /// @class UniqueListException
    /// @brief Main throw class, from which other throw classes inherited.
    class UniqueListException {};

    /// @class NotUniqueValue
    /// @brief Exception to add not unique value to the list.
    class NotUniqueValue : public UniqueListException {};

    /// @class NoSuchValue
    /// @brief Exception to remove not contained value from the list.
    class NoSuchValue : public UniqueListException {};
}

template <typename T>
/// @class UniqueList
/// @brief Contains implementation of unique list with functionality.
class UniqueList: public PointerList<T>
{
public:
    /// @throw uniqueListException::NotUniqueValue.
    void addInPos(T value, int position) throw(uniqueListException::NotUniqueValue);
    void addFirst(T value) { addInPos(value, 1); }
    void addLast(T value) { addInPos(value, PointerList<T>::length + 1); }

    /// @throw uniqueListException::NoSuchValue.
    void removeValue(T value) throw(uniqueListException::NoSuchValue);
};

template <typename T>
void UniqueList<T>::addInPos(T value, int position) throw(uniqueListException::NotUniqueValue)
{
    if (isContained(value))
        throw uniqueListException::NotUniqueValue();

    PointerList<T>::addInPos(value, position);
}

template <typename T>
void UniqueList<T>::removeValue(T value) throw(uniqueListException::NoSuchValue)
{
    if (!isContained(value))
    {
        throw uniqueListException::NoSuchValue();
    }

    PointerList<T>::removeValue(value);
}

#endif // UNIQUELIST_H
