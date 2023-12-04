// This file defines the ListNode's constructors and methods. This is required to implement the DblList class.

#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>

class ListNode {

  public:

    ListNode();

    ListNode(T);

    virtual ~ListNode();

    T m_data;

    ListNode<T>* m_previous;

    ListNode<T>* m_next;

    
};



  template <typename T>

  ListNode<T>::ListNode() { // Default constructor
  
    m_data = nullptr;
  
    m_previous = nullptr;
  
    m_next = nullptr;
  
  }


  template <typename T>

  ListNode<T>::ListNode(T data) { // Overloaded constructor

    m_data = data;

    m_previous = nullptr;

    m_next = nullptr;

  }


  template <typename T>

  ListNode<T>::~ListNode() { // Destructor

    delete m_previous;

    delete m_next;
    
  }


#endif 