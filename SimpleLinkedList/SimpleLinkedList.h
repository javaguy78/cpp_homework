#ifndef SIMPLE_LINKED_LIST_H
#define SIMPLE_LINKED_LIST_H

#include <string>
Template<typename T>
struct Element {
    Element * next;
    T data;
    Element(T t) : next{ nullptr } {
        data = t;
    }
};

template<typename T>
class SimpleLinkedList {
public:
    SimpleLinkedList<T>() :
        first{ nullptr },
        last{ nullptr },
        size{0u} {}

    SimpleLinkedList<T>(T type) : SimpleLinkedList<T>() 
    {
        last = first = new Element<T>(type);
        ++size;
    }

    SimpleLinkedList(const SimpleLinkedList & in)
    {
        try 
        {
            if (in.first != nullptr) 
            {
                first = new Element<int>(in.first->data);
                auto * tmpLocal = first;
                auto * tmpCopy = in.first;
                while (tmpCopy->next != nullptr) 
                {
                    tmpCopy = tmpCopy->next;
                    tmpLocal->next = new Element<int>(tmpCopy->data);
                    tmpLocal = tmpLocal->next;
                    last = tmpLocal;
                    ++size;
                }
            }
        }
        catch (...) {
            unwind();
            throw;
        }
    }

    SimpleLinkedList(SimpleLinkedList && in) 
    {
        first = in.first;
        last = in.last;
        size = in.size;

        in.first = nullptr;
        in.last = nullptr;
        in.size = 0;
    }

    ~SimpleLinkedList() 
    {
        unwind();
    }

    Element<T> const * getFirst() const
    {
        return first;
    }
    
    void add(T type) 
    {
        addLast(type);
    }

    void addLast(T type) 
    {
        if (!first) 
        {
            last = first = new Element<T>(type);
        }
        else 
        {
            last->next = new Element<T>(type);
            last = last->next;
        }
    }

    void printAll() const 
    {
        std::cout << *this << endl;
    }
    
    unsigned int getSize() const 
    {
        return size;
    }

    SimpleLinkedList<T> & operator=(const SimpleLinkedList<T> & in) 
    {
        if (this != &in) 
        {
            SimpleLinkedList<T>(in).swap(*this);
        }
        return *this;
    }

    SimpleLinkedList<T> & operator=(SimpleLinkedList<T> && in)
    {
        using std::move;
        first = move(in.first);
        last = move(in.last);
        size = move(in.size);
        return *this;
    }

    void swap(SimpleLinkedList<T> & in)
    {
        using std::swap;
        swap(this->first, in.first);
        swap(this->last, in.last);
        swap(this->size, in.size);

    }

private:
    Element<T> * first;
    Element<T> * last;
    unsigned int size;

    void unwind() 
    {
        auto * tmp = first;
        while (tmp) 
        {
            first = first->next;
            delete tmp;
            tmp = first;
        }
    }

};

template<typename T>
std::ostream & operator<<(std::ostream& out, const SimpleLinkedList<T>& sll) {
    auto * tmp = sll.getFirst();
    out << "{";
    while (tmp) {
        out << tmp->data;
        if (tmp->next) {
            out << ",";
        }
        tmp = tmp->next;
    };
    out << "}";
    return out;
}

#endif
