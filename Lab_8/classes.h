#ifndef LAB_8_CLASSES_H
#define LAB_8_CLASSES_H

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T>* previous_elem;
    Node<T>* next_elem;

    /*
     * Node constructor
     *
     * @param data data of list.
     */
    Node(T data){
        this->data = data;
        previous_elem = next_elem = nullptr;
    }

};


template <typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
public:

    /*
     * LinkedList constructor
     */
    LinkedList(){
        head = tail = nullptr;
        length = 0;
    }

    /*
     * LinkedList destructor
     */
    ~LinkedList(){
        while (head != nullptr)
            pop_front();
    }

    /*
     * Checking empty list or no
     *
     * @return flag of completing
     */
    bool checkEmpty(){
        if (head != nullptr || tail != nullptr)
            return 0; // not empty
        else
            return 1; // empty
    }

    /*
     * Getting list length
     *
     * @return list length
     */
    int getLength(){
        return length;
    }

    /*
     * Pushing list node in front
     *
     * @param data data of list
     */
    void push_front(T data){
        Node<T>* pointer = new Node<T>(data);
        pointer->next_elem = head;
        if (head != nullptr)
            head->previous_elem = pointer;
        if (tail == nullptr)
            tail = pointer;
        head = pointer;
        length++;
    }

    /*
     * Pushing list node in back
     *
     * @param data data of list
     */
    void push_back(T data){
        Node<T>* pointer = new Node<T>(data);
        pointer->previous_elem = tail;
        if (tail != nullptr)
            tail->next_elem = pointer;
        if (head == nullptr)
            head = pointer;
        tail = pointer;
        length++;
    }

    /*
     * Getting list node from front
     *
     * @return head node data
     */
    T getFrontElem(){
        return head->data;
    }

    /*
     * Getting list node from back
     *
     * @return tail node data
     */
    T getBackElem(){
        return tail->data;
    }

    /*
     * Deleting list node from front
     */
    void pop_front(){
        if (head == nullptr)
            return;

        Node<T>* pointer = head->next_elem;

        if (pointer != nullptr)
            pointer->previous_elem = nullptr;
        else
            tail = nullptr;

        delete head;
        head = pointer;
        length--;
    }

    /*
     * Deleting list node from back
     */
    void pop_back(){
        if (tail == nullptr)
            return;

        Node<T>* pointer = tail->previous_elem;

        if (pointer != nullptr)
            pointer->next_elem = nullptr;
        else
            head = nullptr;

        delete tail;
        tail = pointer;
        length--;
    }

    class Iterator{
    private:
        Node<T>* pointer;
    public:

        /*
         * Iterator constructor
         */
        Iterator(Node<T>* pointer) : pointer(pointer) {}

        /*
         * Overloading ++ operator
         *
         * @return iterator
         */
        Iterator& operator++(){
            pointer = pointer->next_elem;
            return *this;
        }

        /*
         * Overloading * operator
         *
         * @return data
         */
        T& operator*(){
            return pointer->data;
        }

        /*
         * Overloading != operator
         *
         * @param it iterator link
         * @return flag of completing
         */
        bool operator!=(Iterator& it){
            return it.pointer != pointer;
        }

    };

    /*
     * Returning begin iterator
     *
     * @return begin iterator
     */
    Iterator begin(){
        return Iterator(head);
    }

    /*
     * Returning end iterator
     *
     * @return end iterator
     */
    Iterator end(){
        return Iterator(tail->next_elem);
    }

};

#endif //LAB_8_CLASSES_H
