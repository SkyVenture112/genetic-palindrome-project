// This file defines the DNASeq's constructors and methods.

#ifndef DNASEQ_H
#define DNASEQ_H

#include "DblList.h"

#include <iostream>
#include <string>

  class DNASeq {

    public:

      DNASeq();

      DNASeq(std::string);

      virtual ~DNASeq();

      DNASeq* complement();

      DNASeq* substring(int, int);

      bool isGeneticPalindrome();

      DblList<char>* getSequence();

      void print();


    private:

      DblList<char>* sequence;

  };

#endif 