#ifndef POINTERLIST_H
#define POINTERLIST_H

template <typename T>
/// @class PointerList
/// @brief Contains implementation of pointer linked list with functionality.
class PointerList
{
public:
    PointerList():
        list(NULL),
        length(0)
    {}

    ~PointerList();

    void addInPos(T value, int position);
    void addLast(T value) { addInPos(value, length + 1); }
    void addFirst(T value) { addInPos(value, 1); }

    int getLength() const { return length; }

    bool isEmpty() { return list == NULL; }
    bool isContained(T value) const;

    void removeValue(T value);

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
bool PointerList<T>::isContained(T value) const
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
void PointerList<T>::addInPos(T value, int position)
{
    if (isEmpty())
    {
        list = new ListElement(NULL, value);
        length++;
        return;
    }

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
void PointerList<T>::removeValue(T value)
{
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
PointerList<T>::~PointerList()
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

#endif // POINTERLIST_H
