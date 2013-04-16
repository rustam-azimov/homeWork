#ifndef UNIQUELIST_H
#define UNIQUELIST_H

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
class UniqueList
{
public:
    UniqueList():
        list(NULL),
        length(0)
    {}

    ~UniqueList();

    /// @throw uniqueListException::NotUniqueValue.
    void addInPos(T value, int position) throw(uniqueListException::NotUniqueValue);
    void addLast(T value) { addInPos(value, length + 1); }
    void addFirst(T value) { addInPos(value, 1); }

    int getLength() const { return length; }

    bool isEmpty() { return list == NULL; }
    bool isContained(T value) const;

    /// @throw uniqueListException::NoSuchValue.
    void removeValue(T value) throw(uniqueListException::NoSuchValue);

protected:
    /// @struct ListElement
    /// @brief Contains implementation of linked list.
    struct ListElement
    {
        T value;
        ListElement *next;

        ListElement(ListElement * nextElement, T x) :
            value(x),
            next(nextElement)
        {}
    };
    ListElement *list;
    int length;
};

template <typename T>
bool UniqueList<T>::isContained(T value) const
{
    ListElement *temp = list;
    int counter = 1;

    while (counter <= length)
    {
        if (temp->value == value)
            return true;

        temp = temp->next;
        counter++;
    }

    return false;
}

template <typename T>
void UniqueList<T>::addInPos(T value, int position) throw(uniqueListException::NotUniqueValue)
{
    if (isEmpty())
    {
        list = new ListElement(NULL, value);
        length++;
        return;
    }

    if (isContained(value))
        throw uniqueListException::NotUniqueValue();

    if (position > length)
        position = length + 1;

    ListElement *temp = list;
    for (int i = 1; i < (position - 1); i++)
        temp = temp->next;
    ListElement *newElement = new ListElement(temp->next, value);
    temp->next = newElement;
    length++;
}

template <typename T>
void UniqueList<T>::removeValue(T value) throw(uniqueListException::NoSuchValue)
{
    if (!isContained(value))
    {
        throw uniqueListException::NoSuchValue();
    }

    if (list->value == value)
    {
        ListElement *deletedElement = list;
        list = list->next;
        delete deletedElement;
        length--;
        return;
    }

    ListElement *temp = list;

    while (temp->next->value != value)
        temp = temp->next;

    ListElement *deletedElement = temp->next;
    temp->next = temp->next->next;

    length--;
    delete deletedElement;
}

template <typename T>
UniqueList<T>::~UniqueList()
{
    ListElement *temp = list;
    while (list)
    {
        temp = temp->next;
        delete list;
        list = temp;
    }
    delete list;
}



#endif // UNIQUELIST_H
