#include "IOFunctions.hpp"

namespace StudySeries {

void outputFile(std::string const& fileName, std::string const &contents) {
	std::ofstream out(fileName);
	std::copy(contents.begin(), contents.end(), std::ostreambuf_iterator<char>(out));
}

std::string loadFile(std::ifstream &infile) {
	std::string fileData((std::istreambuf_iterator<char>(infile)),
		std::istreambuf_iterator<char>());
	infile.close();
	return fileData;
}

}