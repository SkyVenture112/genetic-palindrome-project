// This file defines the DNASeq's constructors and methods.

#include "DNASeq.h"


  DNASeq::DNASeq() { // Default constructor
  
    sequence = new DblList<char>();
  
  }
  
  
  
  DNASeq::DNASeq(std::string DNA) { // Overloaded constructor that assigns the given DNA sequence to the char doubly-linked list private member variable
  
    sequence = new DblList<char>();
  
    sequence -> addFront(DNA[0]);
  
    for (int i = 1; i < DNA.length(); ++i) {
  
        sequence -> addBack(DNA[i]);
  
    }
  
  }
  
  
  
  
  DNASeq::~DNASeq() { // Destructor
  
    delete sequence;
  
  }
  
  
  
  
  
  DNASeq* DNASeq::complement() { // Computes and returns the complement of the class's list-based DNA sequence
  
    DNASeq* complementSequence = new DNASeq();
  
    for (int i = 0; i < sequence -> getSize(); ++i) {
  
      if (sequence -> get(i) == 'A') {
  
        complementSequence -> getSequence() -> addBack('T');
  
      }
  
      else if (sequence -> get(i) == 'T') {
  
        complementSequence -> getSequence() -> addBack('A');
  
      }
  
      else if (sequence -> get(i) == 'C') {
  
        complementSequence -> getSequence() -> addBack('G');
  
      }
  
      else {
  
        complementSequence -> getSequence() -> addBack('C');
  
      }
  
    }
  
    return complementSequence;
  
  }
  
  
  
  
  
  
  DNASeq* DNASeq::substring(int s, int e) { // Computes and returns a substring of the class's list-based DNA sequence given a start and end index
  
    DNASeq* substring = new DNASeq();
  
    for (int i = s; i < e; ++i) {
  
      substring -> getSequence() -> addBack(sequence -> get(i));
  
    }

  
    return substring;
  
  
  }
  
  
  
  
  
  
  
  bool DNASeq::isGeneticPalindrome() { // Returns true if the DNA sequence is a palindrome and false if not
  
    bool isPalindrome;
  
    DNASeq* reversed = new DNASeq();
  
    for (int i = complement() -> getSequence() -> getSize() - 1; i >= 0; --i) {
  
      reversed -> getSequence() -> addBack(complement() -> getSequence() -> get(i));
  
    }

  
    DNASeq* original = new DNASeq();
  
    for (int i = 0; i < sequence -> getSize(); ++i) {
  
      original -> getSequence() -> addBack(sequence -> get(i));
  
    }

    bool isEqual = true;


    for (int i = 0; i < reversed -> getSequence() -> getSize(); ++i) {

      if (original -> getSequence() -> get(i) == reversed -> getSequence() -> get(i)) {

        continue;

      }

      else {

        isEqual = false;

        break;


      }


      
    }

    return isEqual;

  }
    
    



  DblList<char>* DNASeq::getSequence() {
    
    return sequence;
    
  }


  void DNASeq::print() {

    for (int i = 0; i < sequence -> getSize(); ++i) {

      std::cout << sequence -> get(i);

    
    }

  
  }