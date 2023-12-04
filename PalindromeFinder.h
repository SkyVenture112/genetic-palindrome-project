// This file defines the PalindromeFinder's constructors and methods.


#ifndef PALINDROMEFINDER_H
#define PALINDROMEFINDER_H

#include <iostream>
#include <string>
#include <fstream>
#include "DNASeq.h"

class PalindromeFinder {

  public:

    PalindromeFinder();

    virtual ~PalindromeFinder();

    void findPalindromes(std::string inputFile);


};


#endif 
