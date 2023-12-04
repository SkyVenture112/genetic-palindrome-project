// This file defines the DblList's constructors and methods.


#ifndef DBL_LIST_H
#define DBL_LIST_H
#include "ListNode.h"


  template <typename T>
  
  class DblList {

    public:
  
      DblList();
    
      virtual ~DblList();
    
      int getSize();
    
      bool isEmpty();
    
      void addBack(T);
    
      void addFront(T);
    
      void add(int, T);
    
      T removeBack();
    
      T removeFront();
    
      T remove(int);
    
      T get(int);
    
      bool contains(T);
    
      template <typename S>
    
      friend class PQueue;
  
    private:
  
      ListNode<T>* m_front;
    
      ListNode<T>* m_back;
    
      int m_size;
  
  };




  template <typename T>

  DblList<T>::DblList() { // Default constructor
    
    m_size = 0;
      
    m_front = nullptr;
      
    m_back = nullptr;
    
  }




  template <typename T>

  DblList<T>::~DblList() { // Destructor
    
    m_size = 0;
      
    m_front = nullptr;
      
    m_back = nullptr;
    
  }




  template <typename T>

  int DblList<T>::getSize() { // Returns the current size of the list
    
    return m_size;
    
  }


  template <typename T>

    bool DblList<T>::isEmpty() { // Returns true if the list is currently empty, and false if it is not
      
    if (m_size == 0) {
  
      return true;
  
    }
  
    else {
  
      return false;
      
    }
  
    
  }



  template <typename T>

  T DblList<T>::get(int position) { // Returns the data at the given position in the list. If the list is empty, the method returns -1

    if (isEmpty() == true) {

      return -1;
      
    }

    else {
    
      int currentPosition = 0;
        
      ListNode<T>* current = m_front;
        
      while (currentPosition != position) {
        
        current = current-> m_next;
          
        currentPosition += 1;
      
      }
      
      return current -> m_data;

    }
    
  }




  template <typename T>


  bool DblList<T>::contains(T data) { // Returns true if the given piece of data is present in the list and false if not.
    
    ListNode<T>* current = m_front;
      
    bool found = false;
      
    while (current != nullptr) {
      
      if (data == current -> m_data) {
        
        found = true;
          
        break;
        
      }
        
      current = current -> m_next;
        
    }
      
    return found;
    
  }




  template <typename T>

  void DblList<T>::addFront(T data) { // Adds a new piece of data to the front of the list
    
    ListNode<T>* newNode = new ListNode<T>(data);
      
    if (isEmpty() == false) {
      
      m_front -> m_previous = newNode;
      
      newNode -> m_next = m_front;
      
      } 
    
      else {
      
        m_back = newNode;
      
      }
    
    m_size += 1;
    
    m_front = newNode;
    
  }



  template <typename T>

  void DblList<T>::addBack(T data) { // Adds a new piece of data to the back of the list
    
    ListNode<T>* newNode = new ListNode<T>(data);
      
    if (isEmpty() == false) {
      
      m_back -> m_next = newNode;
        
      newNode -> m_previous = m_back;
    
    }
      
    else {
      
      m_front = newNode;
      
    }
      
    m_size += 1;
      
    m_back = newNode;
    
  }





  template <typename T>

  void DblList<T>::add(int position, T data) { // Adds a new piece of data at the given position in the list
    
    if (isEmpty() == true || position == 0) {
      
      addFront(data);
      
    } 
      
    else if (position >= m_size) {
      
      addBack(data);
      
    } 
    
    else {
      
    ListNode<T>* current = m_front;
      
    int currentPosition = 0; 
      
    while (currentPosition != position) {
      
      current = current -> m_next;
      
      currentPosition += 1;
      
    }
      
    ListNode<T>* newNode = new ListNode<T>(data);
      
    current -> m_previous -> m_next = newNode;
      
    newNode -> m_previous = current -> m_previous;
      
    current -> m_previous = newNode;
      
    newNode -> m_next = current;
      
    m_size += 1;
      
    }
    
  }




  template <typename T>

  T DblList<T>::removeFront() { // Removes the piece of data at the front of the list 

    T data;
    
    data = m_front -> m_data;
    
    if (m_size == 1) {
      
      delete m_front;
        
      m_front = nullptr;
        
      m_back = nullptr;
      
    } 
    
    else { 
      
      ListNode<T>* currentFront = m_front;
        
      m_front = m_front -> m_next;
        
      m_front -> m_previous = nullptr;
        
      currentFront -> m_next = nullptr;
        
      delete currentFront;
      
    }
    
    m_size -= 1;
    
    return data;
    
  }



  template <typename T>

  T DblList<T>::removeBack() { // Removes the piece of data at the back of the list
    
    T data;
       
    data = m_back -> m_data;
      
    if (m_size == 1) {
      
      delete m_back;
        
      m_front = nullptr;
        
      m_back = nullptr;
      
    } 
    
    else {
      
      ListNode<T>* currentBack = m_back;
        
      m_back = m_back -> m_previous;
        
      m_back -> m_next = nullptr;
        
      currentBack -> m_previous = nullptr;
        
      delete currentBack;
      
    }
    
    m_size -= 1;
    
    return data;
    
  }




  template <typename T>

  T DblList<T>::remove(int position) { // Removes the piece of data at the given position in the list. If the list is empty, the method returns -1.


    if (isEmpty() == true) {

      return -1;
      
    }
    
    T data;
    
    if (position == 0) {
      
      data = removeFront();
      
    } 
    
    else if (position >= m_size - 1) {
      
      data = removeBack();
      
    } 
    
    else {
      
      ListNode<T>* current = m_front;
        
      int currentPosition = 0;
      
      while (currentPosition != position) {
        
        current = current -> m_next;
          
        currentPosition += 1;
      
    }
      
    data = current -> m_data;
      
    current -> m_previous -> m_next = current -> m_next;
      
    current -> m_next -> m_previous = current -> m_previous;
      
    delete current;
      
    m_size -= 1;
      
    }
    
  }


#endif