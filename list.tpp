#pragma once
#include "list.hpp"


//Member functions

template <typename T>
List<T>::iterator List<T>::insert(const iterator pos, const T& value)
{
    Node* n = new Node<T>{value};
    Node* curr = pos.curr;
    curr->prev->next = n;
    n->prev = curr->prev;
    curr->prev = n;
    n->next = curr;
    size++;
    return iterator(n);
}

template <typename T>
List<T>::iterator List<T>::insert(const iterator pos, T&& value)
{
    Node* n = new Node<T>{std::move(value)};
    Node* curr = pos.curr;
    curr->prev->next = n;
    n->prev = curr->prev;
    curr->prev = n;
    n->next = curr;
    size++;
    return iterator(n);
}

template <typename T>
List<T>::iterator List<T>::insert(const iterator pos, const size_t count, const T& value)
{
    for (size_t i{}; i < count-1; ++i)
    {
        insert(pos, value);
    }
    return insert(pos, value);
}
// template <typename T>
// List<T>::List(const List& other) : _head{nullptr}, _tail{nullptr}
// {
//     Node<T>* cur = other._head;

//     while(cur)
//     {
//         if (!_head)
//         {
//             _head = new Node<T>(cur->_data);
//             _tail = _head;
//             _head->_prev = nullptr;
//         }

//         else
//         {
//             _tail->_next = new Node<T>(cur->_data);
//             _tail->_next->_prev = _tail;
//             _tail = _tail->_next;

//         }
//         cur = cur->_next;

//         if (_tail) _tail->_next = nullptr;

//     }
// }

// template <typename T>
// List<T>::List(List&& other) : _head{other._head}, _tail{other._tail}
// {
//     other._head = nullptr;
//     other._tail = nullptr;
// }

// template <typename T>
// List<T>& List<T>::operator=(const List& other) 
// {
//     if (this == &other) return *this;
    
//     while(_head)
//     {
//         Node<T>* _next = _head->_next;
//         delete _head;
//         _head = _next;
//     }
//     _tail = nullptr;

//     Node<T>* cur = other._head;
//     while(cur)
//     {
//         if (!_head)
//         {
//             _head = new Node<T>{cur->_data};
//             _tail = _head;
//             _head->_prev = nullptr;
//         }
        
//         else
//         {
//             _tail->_next = new Node<T>{cur->_data};
//             _tail->_next->_prev = _tail;
//             _tail = _tail->_next;
//         }
//         cur = cur->_next;
//     }

//     if (_tail) _tail->_next = nullptr;
    
//     return *this;
// }

// template <typename T>
// List<T>& List<T>::operator=(List&& other)
// {
//     if (this == &other) return *this;

//     while (_head)
//     {
//         Node<T>* _next = _head->_next;
//         delete _head;
//         _head = _next;
//     }
//     _head = other._head;
//     _tail = other._tail;
//     other._head = other._tail = nullptr;
//     return *this;
// }


// template <typename T>
// List<T>::~List()
// {
//     clear();
// }

// template <typename T>
// void List<T>::assign(size_t count, const T& value)
// {
//     Node<T>* cur = _head;
//     size_t i = 0;
//     while (cur && i < count)
//     {
//         cur->_data = value;
//         cur = cur->_next;
//         ++i;
//     }

//     while (i < count)
//     {
//         Node<T>* n = new Node<T>{value};

//         if (!_head)
//         {
//             _head = _tail = n;
//             n->_prev = nullptr;
//         }

//         else
//         {
//             n->_prev = _tail;
//             _tail->_next = n;
//             _tail = n;
//         }

//         i++;
//     }

//     while (cur)
//     {
//         Node<T>* next = cur->_next;
//         delete cur;
//         cur = next;
//     }

//     if (_tail) _tail->_next = nullptr;

// }

// // Element access

// // Capacity
// template <typename T>
// size_t List<T>::size() const noexcept
// {
//     Node<T>* cur = _head;
//     size_t size = 0;
//     while (cur)
//     {
//         ++size;
//         cur = cur->_next;
//     }

//     return size;
// }


// // Modifiers
// template <typename T>
// void List<T>::clear()
// {
//     while (_head)
//     {
//         Node<T>* next = _head->_next;
//         delete _head;
//         _head = next;
//     }
// }

// template <typename T>
// void List<T>::insert(size_t pos, const T& value)
// {
//     if (pos > size()) return;
//     if (pos == 0) 
//     {
//         Node<T>* n = new Node<T>{value};
//         n->_next = _head;
//         n->_prev = nullptr;
//         if(_head) _head->_prev = n;
//         _head = n;
//         if (!_tail) _tail = _head;
//         return;
//     }
    
//     Node<T>* cur = _head;
//     for (size_t i{0}; i < pos - 1; i++)
//     {
//         cur = cur->_next;
//     } 

//     Node<T>* n = new Node<T>{value};
//     if (cur->_next) cur->_next->_prev = n;
//     n->_next = cur->_next;
//     n->_prev = cur;
//     cur->_next = n;
//     if (n->_next == nullptr) _tail = n;
// }

// template <typename T>
// void List<T>::insert(size_t pos, T&& value)
// {
//     if (pos > size()) return;
//     if (pos == 0) 
//     {
//         Node<T>* n = new Node<T>{std::move(value)};
//         n->_next = _head;
//         n->_prev = nullptr;
//         if(_head) _head->_prev = n;
//         _head = n;
//         if (!_tail) _tail = _head;
//         return;
//     }
    
//     Node<T>* cur = _head;
//     for (size_t i{0}; i < pos - 1; i++)
//     {
//         cur = cur->_next;
//     } 

//     Node<T>* n = new Node<T>{std::move(value)};
//     if (cur->_next) cur->_next->_prev = n;
//     n->_next = cur->_next;
//     n->_prev = cur;
//     cur->_next = n;
//     if (n->_next == nullptr) _tail = n;
// }

// template <typename T>
// void List<T>::insert(size_t pos, size_t count, const T& value)
// {
//     for (size_t i{0}; i < count; ++i)
//     {
//         insert(i+pos, value);
//     }
// }

// template <typename T>
// void List<T>::erase(size_t pos)
// {
//     if (!_head || pos >= size()) return;
//     if (pos == 0)
//     {
//         Node<T>* tmp = _head;
//         _head = _head->_next;
//         if (_head) _head->_prev = nullptr;
//         else _tail = nullptr;

//         delete tmp;
//         return;
//     }

//     Node<T>* cur = _head;
//     for (size_t i{1}; i < pos; ++i)
//     {
//         cur = cur->_next;
//     }
//     cur->_prev->_next = cur->_next;
//     if (cur->_next) cur->_next->_prev = cur->_prev;
//     else _tail = cur->_prev;
//     delete cur; 
// }

// template <typename T>
// void List<T>::erase(size_t from, size_t to)
// {
//     if (from >= size() || from >= to) return;
//     if (to > size()) to = size();

//     for (size_t i{from}; i < to; ++i)
//     {
//         erase(from);
//     }
// }

// template <typename T>
// void List<T>::push_back(const T& data)
// {
//     if (!_tail)
//     {
//         _tail = new Node{data};
//         _head = _tail;
//         return;
//     }
//     _tail->_next = new Node{data};
//     _tail->_next->_prev = _tail;
//     _tail = _tail->_next;
//     _tail->_next = nullptr; 
// }

// template <typename T>
// void List<T>::push_back(T&& data)
// {
//     if (!_tail)
//     {
//         _tail = new Node{std::move(data)};
//         _head = _tail;
//         return;
//     }
//     _tail->_next = new Node{std::move(data)};
//     _tail->_next->_prev = _tail;
//     _tail = _tail->_next;
//     _tail->_next = nullptr; 
// }

// template <typename T>
// void List<T>::pop_back()
// {
//     if (!_tail) return; 
//     Node<T>* tmp = _tail;
//     _tail = _tail->_prev;
//     delete tmp;
//     if (_tail) _tail->_next = nullptr;
//     else _head = nullptr;
// }

// template <typename T>
// void List<T>::push_front(const T& data)
// {
//     if (!_head)
//     {
//         _head = new Node<T>{data};
//         _tail = _head;
//         return;
//     }
//     _head->_prev = new Node<T>{data};
//     _head->_prev->_next = _head;
//     _head = _head->_prev;
//     _head->_prev = nullptr;
// }

// template <typename T>
// void List<T>::push_front(T&& data)
// {
//     if (!_head)
//     {
//         _head = new Node<T>{std::move(data)};
//         _tail = _head;
//         return;
//     }
//     _head->_prev = new Node<T>{std::move(data)};
//     _head->_prev->_next = _head;
//     _head = _head->_prev;
//     _head->_prev = nullptr;
// }

// template <typename T>
// void List<T>::pop_front()
// {
//     if (!_head) return; 
//     Node<T>* tmp = _head;
//     _head = _head->_next;
//     delete tmp;
//     if (_head) _head->_prev = nullptr;
//     else _tail = nullptr;
// }

// template <typename T>
// void List<T>::swap(List<T>& other)
// {
//     std::swap(_head, other._head);
//     std::swap(_tail, other._tail);
// }

// template <typename T>
// template <typename...Args>
// void List<T>::emplace(size_t pos, Args&&...args)
// {
//     if (pos > size()) return;
//     if (pos == 0) 
//     {
//         Node<T>* n = new Node<T>{forward<Args>(args...)};
//         n->_next = _head;
//         n->_prev = nullptr;
//         if(_head) _head->_prev = n;
//         _head = n;
//         if (!_tail) _tail = _head;
//         return;
//     }
    
//     Node<T>* cur = _head;
//     for (size_t i{0}; i < pos - 1; i++)
//     {
//         cur = cur->_next;
//     } 

//     Node<T>* n = new Node<T>{forward<Args>(args...)};
//     if (cur->_next) cur->_next->_prev = n;
//     n->_next = cur->_next;
//     n->_prev = cur;
//     cur->_next = n;
//     if (n->_next == nullptr) _tail = n;
// }

// // Operations
// template <typename T>
// void List<T>::sort()
// {
//     if (!_head) return;
//     size_t n = size();
//     Node<T>* cur = _head;
//     Node<T>* cmp = _head;
//     while(cur->next)
//     {
//         cmp = _head;
//         while (cmp->next)
//         {
//             if(cmp->_data > cmp->next->_data)
//             {
//                 std::swap(cmp->_data, cmp->_next->_data);
//             }
//             cmp = cmp->next;
//         }
//         cur = cur->_next;
//     }
// }

// template <typename T>
// void List<T>::merge(List<T>& other)
// {
//     if (this == &other) return;
//     if (!other._head) return;
//     if (!_head)
//     {
//         _head = other._head;
//         _tail = other._tail;
//         other._head = other._tail = nullptr;
//         return;
//     }
//     _tail->_next = other._head;
//     other._head->_prev = _tail;
//     _tail = other._tail;

//     other._head = other._tail = nullptr;
// }

// template <typename T>
// void List<T>::reverse()
// {
//     size_t n = size()/2;
//     Node<T>* start = _head;
//     Node<T>* end = _tail;
//     for (size_t i{0}; i < n; ++i)
//     {
//         std::swap(start->_data, end->_data);
//         start = start->_next;
//         end = end->_prev; 
//     }
// }

// template <typename T>
// void List<T>::print_list()
// {
//     Node<T>* cur = _head;
//     while (cur) { 
//         std::cout << cur->_data; 
//         cur = cur->_next;
//     }
// }