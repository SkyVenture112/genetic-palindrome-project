// This file defines the PalindromeFinder's constructors and methods.


#include "PalindromeFinder.h"


  PalindromeFinder::PalindromeFinder() { // Default constructor
  
  
  }
  
  
  
  
  PalindromeFinder::~PalindromeFinder() { // Destructor
  
  
  }
  
  
  
  void PalindromeFinder::findPalindromes(std::string inputFile) { // Takes in the name of an input file as a parameter and iterates through that file, stopping when "END" is read. For each valid DNA sequence in the file, the method outputs the original sequence and whether or not it is a genetic palindrome, as well as its substrings that are genetic palindromes from shortest to longest length. If the sequence is not valid, it skips over it.
  
    std::ifstream input;
    std::string sequenceLine;
  
    input.open(inputFile);
  
    while (getline(input, sequenceLine)) {
  
      if (sequenceLine != "END") {
  
        bool validSequence = true;
  
        DNASeq* sequence = new DNASeq(sequenceLine);
  
        for (int i = 0; i < sequence -> getSequence() -> getSize(); ++i) {
  
          if (sequence -> getSequence() -> get(i) != 'A' && sequence -> getSequence() -> get(i) != 'T' && sequence -> getSequence() -> get(i) != 'G' 
              && sequence -> getSequence() -> get(i) != 'C') {
  
            validSequence = false;
  
            break;
  
          }
  
        }
  
        if (validSequence == false) {
  
          std::cout << std::endl << "Invalid sequence." << std::endl;
  
          continue; 
  
        }
  
        std::cout << std::endl << sequenceLine << std::endl;
  
        if (sequence -> isGeneticPalindrome() == true) {
  
          std::cout << "This sequence is a genetic palindrome." << std::endl;
  
        }
  
        else {
  
          std::cout << "This sequence is not a genetic palindrome." << std::endl;
  
        }
  
        for (int i = 5; i < sequence -> getSequence() -> getSize(); ++i) {
  
          for (int j = 0; j < sequence -> getSequence() -> 
            getSize() - i + 1; ++j) {
  
            DNASeq* substring = sequence -> substring(j, j + i);

  
            if (substring -> isGeneticPalindrome()) {
  
              std::cout << "Substring Palindrome: ";
              
              substring -> print();
              
              std::cout << std::endl;
  
            }
  
            delete substring;
  
          }
  
        }
  
        delete sequence;
  
      }
  
  
    }
  
    std::cout << std::endl;
  
    input.close();
  
}