#pragma once
#include <iostream>
#include <initializer_list>
#include <type_traits>

template <typename T>
T&& forward(std::remove_reference_t<T>& arg)
{
  return static_cast<T&&> (arg);
}
template <typename T>
T&& forward(std::remove_reference_t<T>&& arg)
{
  return static_cast<T&&> (arg);
}

template <typename T>
struct Node
{
    T data;
    Node<T>* prev;
    Node<T>* next;
    
    Node(T _data = T()) : data{_data}, next{nullptr}, prev{nullptr} {}
    Node(Node<T>* _next, T _data = T())  : data(_data), prev(nullptr), next(_next) {}
    Node(Node<T>* _prev, Node<T>* _next, T _data = T()) : data(_data), prev(_prev), next(_next) {}
    Node(const Node& other) : data{other.data}, prev{nullptr}, next{nullptr} {}
    Node(Node&& other) noexcept : data(std::move(other.data)), prev(nullptr), next(nullptr) {}
    ~Node() = default;
};

template <typename T>
class List
{
    private:
        size_t size;
        Node<T>* sentinel;
    public:

        class iterator
        {
          private:
            Node<T>* curr;
            friend class const_iterator;
          public:
            iterator(Node<T>* _curr) : curr{_curr} {}
            
            bool operator==(const iterator& other) const { return curr == other.curr; }
            bool operator!=(const iterator& other) const { return curr != other.curr; }
            iterator& operator++() { curr = curr->next; return *this; }
            iterator operator++(int) { iterator tmp = *this; curr = curr->next; return tmp; }
            iterator& operator--() { curr = curr->prev; return *this; }
            iterator operator--(int) { iterator tmp = *this; curr = curr->prev; return tmp; }
            T& operator*() const { return curr->data; }
            T* operator->() const { return &curr->data; }
        };

        class const_iterator
        {
          private:
            const Node<T>* curr;
            friend class List;
          public:
            const_iterator(const Node<T>* _curr) : curr{_curr} {}
            const_iterator(const iterator& it) : curr(it.curr) {}

            bool operator==(const const_iterator& other) const { return curr == other.curr; }
            bool operator!=(const const_iterator& other) const { return curr != other.curr; }
            const_iterator& operator++() { curr = curr->next; return *this; }
            const_iterator operator++(int) { const_iterator tmp = *this; curr = curr->next; return tmp; }
            const_iterator& operator--() { curr = curr->prev; return *this; }
            const_iterator operator--(int) { const_iterator tmp = *this; curr = curr->prev; return tmp; }
            const T& operator*() const { return curr->data; }
            const T* operator->() const { return &curr->data; }
        };

        class reverse_iterator
        {
          private:
            iterator it;
            friend class const_reverse_iterator;
          public:
            reverse_iterator(const iterator& _it) : it{_it} {}
            
            bool operator==(const reverse_iterator& other) const { return it == other.it; }
            bool operator!=(const reverse_iterator& other) const { return it != other.it; }
            reverse_iterator& operator++() { --it; return *this; }
            reverse_iterator operator++(int) { reverse_iterator tmp = *this; --it; return tmp; }
            reverse_iterator& operator--() { ++it; return *this; }
            reverse_iterator operator--(int) { reverse_iterator tmp = *this; ++it; return tmp; }
            T& operator*() const 
            { 
              iterator tmp = it;
              --tmp;
              return *tmp; 
            }
            T* operator->() const { return &operator*(); }
        };

        class const_reverse_iterator
        {
          private:
            const_iterator it;
          public:
            const_reverse_iterator(const const_iterator& _it) : it{_it} {}
          
            bool operator==(const const_reverse_iterator& other) const { return it == other.it; }
            bool operator!=(const const_reverse_iterator& other) const { return it != other.it; }
            const_reverse_iterator& operator++() { --it; return *this; }
            const_reverse_iterator operator++(int) { const_reverse_iterator tmp = *this; --it; return tmp; }
            const_reverse_iterator& operator--() { ++it; return *this; }
            const_reverse_iterator operator--(int) { const_reverse_iterator tmp = *this; ++it; return tmp; }
            const T& operator*() const 
            { 
              const_iterator tmp = it;
              --tmp;
              return *tmp; 
            }
            const T* operator->() const { return &operator*(); }
        };

        iterator begin() const { return iterator(sentinel->next); }
        iterator end() const { return iterator(sentinel); }
        const_iterator cbegin() const { return const_iterator(sentinel->next); }
        const_iterator cend() const { return const_iterator(sentinel); }
        reverse_iterator rbegin() const { return reverse_iterator(end()); }
        reverse_iterator rend() const { return reverse_iterator(begin()); }
        const_reverse_iterator crbegin() const { return const_reverse_iterator(cend()); }
        const_reverse_iterator crend() const { return const_reverse_iterator(cbegin()); }
        //// Member functions
        List();
        List(size_t count, const T& _data = T());
        List(const List& other);
        List(List&& other) noexcept;
        List& operator=(const List& other);
        // List& operator=(List&& other);
        // ~List();
        // void assign(size_t count, const T& value);

        // Element access
        T& front() { if (size) return sentinel->next->data; }
        const T& front() const { if (size) return sentinel->next->data; }
        T& back() { if (size) return sentinel->prev->data; }
        const T& back() const { if (size) return sentinel->prev->data; }
        
        // Capacity
        bool empty() const noexcept { return size == 0; }
        size_t size() const noexcept { return size; }
        
        // // Modifiers
        void clear();
        iterator insert(const iterator pos, const T& value);
        iterator insert(const iterator pos, T&& value);
        iterator insert(const iterator pos, const size_t count, const T& value );
        iterator erase(iterator pos);
        iterator erase(iterator first, iterator last);
        void push_back(const T& data) { insert(end(), data); }
        void push_back(T&& data) { insert(end(), std::move(data)); }
        void pop_back() { erase(--end()); }
        void push_front(const T& data) { insert(begin(), data); };
        void push_front(T&& data) { insert(begin(), std::move(data)); }
        void pop_front() { erase(begin()); };
        void swap(List<T>& other);

        // template<typename ... Args>
        // void emplace(size_t pos, Args&&...args);

        // // Operations
        // void sort();
        // void merge(List<T>& other);
        // void reverse();
        void print_list();
};

#include "list.tpp"





