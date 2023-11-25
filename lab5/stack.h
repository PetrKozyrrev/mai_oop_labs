#ifndef STACK_H
#define STACK_H 

#include <memory>

namespace my_stl{

    template<class T, class Alloc = std::allocator<T>>
    class Stack{
    private:

        struct Node{
            T data;
            Node* next;
        };

        Node* _head; 
        int _size;

        void Copy(Node* head){
            if (head == nullptr)
                throw std::logic_error("NULL Head");
            
            Node* p = head; 
            bool f_first = true;
            Node* p2 = nullptr;
            Node* p3 = nullptr;

            _size = 0; 

            while (p != nullptr){
                p2 = Alloc_Node_traits::allocate(_m_alloc,1);
                p2->data = p->data;
                p2->next = nullptr;

                if (f_first){
                    _head = p2;
                    p3 = p2;
                    f_first = false;
                }
                else{
                    p3->next = p2;
                    p3 = p3->next;
                }
                _size++;
                p = p->next;
            }
        }

    protected:

        using Alloc_traits = std::allocator_traits<Alloc>;
        using Alloc_Node = typename Alloc_traits::rebind_alloc<Node>;
        using Alloc_Node_traits = std::allocator_traits<Alloc_Node>;

        Alloc_Node _m_alloc;

    public:

        class Iterator{
            friend Stack;
            Node* p;
        public:
            
            Iterator(): p(nullptr){};
            
            Iterator(Node* it): p(it){};

            Iterator(Iterator &it): p(it.p){};
                        
            ~Iterator(){p = nullptr;};

            
            bool operator!=(const Iterator &it){ return p != it.p;};
            
            bool operator==(const Iterator &it){ return p == it.p;};
            
            T& operator*(){ return p->data;};

            T* operator->(){ return &p->data;};
            
            Iterator& operator++(){
                p = p->next;
                return *this;
            };

            Iterator& operator++(int){
                p = p->next;
                return *this;
            };
        };

        class ConstIterator{
            friend Stack;
            Node* p;
        public:
            
            ConstIterator(): p(nullptr){};
            
            ConstIterator(Node* it): p(it){};

            ConstIterator(ConstIterator &it): p(it.p){};
                        
            ~ConstIterator(){p = nullptr;};

            
            bool operator!=(const ConstIterator &it) const{ return p != it.p;};
            
            bool operator==(const ConstIterator &it) const{ return p == it.p;};
            
            T& operator*() const{ return p->data;};

            T* operator->() const{ return &p->data;};
            
            ConstIterator& operator++(){
                p = p->next;
                return *this;
            };

            ConstIterator& operator++(int){
                p = p->next;
                return *this;
            };
        };
        
        Stack(): _m_alloc(){
            _head = Alloc_Node_traits::allocate(_m_alloc,1);
            _head->next = nullptr;
            _size = 0;
        };

        Stack(const Stack<T,Alloc>& other): _m_alloc(){
            Copy(other._head);
        };

        Stack(const Stack<T,Alloc>&& other): _m_alloc(){
            Copy(other._head);
        };

        ~Stack() = default;


        Stack<T,Alloc>& operator=(const Stack<T,Alloc> &other);

        Iterator begin();

        ConstIterator cbegin() const;

        Iterator end();

        ConstIterator cend() const;

        void Push(T item);

        void Pop();

        T Top();

        void Show();

        bool IsEmpty(){ return _size == 0;};

        int Size() const { return _size;};
    };

    template<class T, class Alloc>
    Stack<T,Alloc>& Stack<T,Alloc>::operator=(const Stack<T,Alloc>& other){
        if(this != &other){
            if (_size > 0)
            Copy(other._head);
        }
        return *this;
    }

    template<class T, class Alloc>
    typename Stack<T,Alloc>::Iterator Stack<T,Alloc>::begin(){
        return Iterator(_head);
    }

    template<class T, class Alloc>
    typename Stack<T,Alloc>::ConstIterator Stack<T,Alloc>::cbegin() const{
        return ConstIterator(_head);
    }

    template<class T, class Alloc>
    typename Stack<T,Alloc>::Iterator Stack<T,Alloc>::end(){
        Node* pt = nullptr;
        return Iterator(pt);
    }

    template<class T, class Alloc>
    typename Stack<T,Alloc>::ConstIterator Stack<T,Alloc>::cend() const{
        Node* pt = nullptr;
        return ConstIterator(pt);
    }

    template<class T, class Alloc>
    void Stack<T,Alloc>::Push(T item){
        if(_size == 0){
            _head = Alloc_Node_traits::allocate(_m_alloc,1);
            _head->next = nullptr;
            _head->data = item;
        }
        else{
            Node* p2 = Alloc_Node_traits::allocate(_m_alloc,1);
            p2->data = item;
            p2->next = nullptr;

            p2->next = _head;
            _head = p2;
        }
        _size++;
    }
    
    template<class T, class Alloc>
    void Stack<T,Alloc>::Pop(){
        if (_size == 0)
            throw std::logic_error("Empty Stack");

        Node* p = _head;
        _head = _head->next;
        _size--;

        // if(p != nullptr)
        //     delete p;
    }

    template<class T, class Alloc>
    T Stack<T,Alloc>::Top(){
        if (_size == 0)
            return 0;

        return _head->data;
    }

    template<class T, class Alloc>
    void Stack<T,Alloc>::Show(){
        Node* p = _head;
        std::cout << "Stack => ";
        while (p != nullptr){
            std::cout << p->data << "  ";
            p = p->next;
        }
        std::cout << std::endl;
    }

};

#endif //STACK_H 