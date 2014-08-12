#ifndef SERPENTLIST_H
#define SERPENTLIST_H
#include "node.h"
#include <cstdlib>
#include <ctime>

template<typename N>
class SerpentList
{
public:
    SerpentList()
    {
        length = 0;
        beginning = 0;
        ending = beginning;
        current = beginning;
    }

	SerpentList(SerpentList<N>& copy)
    {
        length = 0;
        beginning = 0;
        ending = beginning;
        current = beginning;
        for(int i = 0; i < copy.size(); i++)
            add(copy.get(i));
    }

    bool operator== (SerpentList<N>& rhs)
    {
        if(size() != rhs.size())
            return false;
        for(int i = 0; i < rhs.size(); i++){
            if(get(i) != rhs.get(i))
                return false;
        }
        return true;
    }

    SerpentList<N> operator= (SerpentList<N>& rhs)
    {
        if(*this == rhs)
            return *this;
        empty();
        for(int i = 0; i < rhs.size(); i++)
            add(rhs.get(i));
        return *this;
    }

    bool operator!= (SerpentList<N>& rhs)
    {
        return !(*this == rhs);
    }

    int size()
    {
        return length;
    }

    N begin()
    {
        if(length > 0)
        {
            current = beginning;
            return beginning->element;
        }
        return N();
    }

    N end()
    {
        if(length > 0)
        {
            current = ending;
            return ending->element;
        }
        return N();
    }

    N next()
    {
        if(current == 0)
            return N();
        if(current->next == 0)
            return N();
		current = current->next;
        return current->element;
    }

    N get(int pos)
    {
        if(pos>=length || pos<0)
            return N();
        Node<N>* pointer = beginning;
        for(int i = 0; i < pos; i++, pointer = pointer->next);
        current = pointer;
        return pointer->element;
    }

    void add(N elem)
    {
        if(size() != 0)
        {
            ending->next = new Node<N>(elem);
            ending = ending->next;
            current = ending;
        }else{
            beginning = new Node<N>(elem);
            ending = beginning;
            current = beginning;
        }
        length++;
    }

    int remove(int pos)
    {
        if(pos>=length || pos<0)
            return -1;
        if(pos == 0){
            Node<N>* todelete = beginning;
            beginning = beginning->next;
            if(current == todelete)
                current = beginning;
            if(ending == todelete)
                ending = beginning;
            delete todelete;
            length--;
            return 0;
        }
        Node<N>* pointer = beginning;
        for(int i = 0; i < pos-1; i++, pointer = pointer->next);
        Node<N>* todelete = pointer->next;
        pointer->next = todelete->next;
        if(ending == todelete)
            ending = pointer;
        if(current == todelete)
            current = ending;
        length--;
        delete todelete;
        return 0;
    }

    int insert(int pos, N elem)
    {
        if(pos>length || pos<0)
            return -1;
        Node<N>* newElement = new Node<N>(elem);
        Node<N>* pointer = beginning;
        int posit = 0;
        if(pos == 0){
            newElement->next = beginning;
            beginning = newElement;
            current = beginning;
            length++;
            return 0;
        }
		for(int i = 0; i < pos-1; i++, pointer = pointer->next);
        newElement->next = pointer->next;
        pointer->next = newElement;
        current = newElement;
        length++;
        return 0;
    }

    void empty()
    {
        for(int i = size()-1; i >= 0; i--){
            remove(i);
        }
    }

    int indexOf(N elem)
    {
        for(int i = 0; i < length; i++){
            if(elem == get(i))
                return i;
        }
        return -1;
    }

    bool hasnext()
    {
        return current->next != 0;
    }

    int swap(int t1, int t2)
    {
        if(t1 < 0 || t1 >= size() || t2 < 0 || t2 >= size())
            return -1;
        N t1tmp = get(t1);
        N t2tmp = get(t2);
        insert(t1, t2tmp);
        remove(t1+1);
        insert(t2, t1tmp);
        remove(t2+1);
        return 0;
    }

    void shuffle()
    {
        shuffle(time(NULL));
    }

    void shuffle(int seed)
    {
        srand(seed);
        for (int i = size(); i > 1; i--)
            swap(i-1, rand() % i);
    }

private:
    int length;
    Node<N>* beginning;
    Node<N>* ending;
    Node<N>* current;
};

#endif // SERPENTLIST_H
