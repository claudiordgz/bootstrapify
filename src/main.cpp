#include "IOFunctions.hpp"
#include "TableOfContents.hpp"
#include "Table.hpp"
#include "GoToTopBtn.hpp"

#include <iostream>


int main(int argc, char* argv[]){
  std::cout << argv[0];
  if (argc == 2)
  {
    std::cout << "Not enough arguments." << std::endl;
    exit(1);
  }
  else
  {
    std::string fileName = argv[1];
    std::string outputFileName = argv[2];
    std::ifstream infile(fileName);
    if (infile) {
      auto contents = StudySeries::loadFile(infile);
      contents = StudySeries::replaceTableWithReponsive(contents);
      contents = StudySeries::fixTableOfContents(contents);
      contents = StudySeries::fixGoTotop(contents);
	  StudySeries::outputFile(outputFileName, contents);
    }
    else {
      std::cout << "file not found!\n";
      return 1;
    }
  }
   return 0 ;
}

