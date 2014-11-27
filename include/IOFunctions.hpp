#ifndef __IOFUNCTIONS__HPP__
#define __IOFUNCTIONS__HPP__

#include <string>
#include <fstream>

namespace StudySeries {

/*! @brief Reads a file into a string
	*  @param infile input file stream
	*  @return file contents in string */
std::string loadFile(std::ifstream &infile);

/*! @brief Writes string to a file
	*  @param fileName name with path of the file
	*  @param contents */
void outputFile(std::string const& fileName, std::string const &contents);

}

#endif