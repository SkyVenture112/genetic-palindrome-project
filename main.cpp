// The following main method instantiates a PalindromeFinder object and then utilizes that object to output the contents of the input file (which is given as a command-line argument).


#include "PalindromeFinder.h"


int main(int argc, char *argv[]) {

  PalindromeFinder* finder = new PalindromeFinder();

  finder -> findPalindromes(argv[1]);

  delete finder;

}