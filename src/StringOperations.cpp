#include "StringOperations.hpp"

namespace StudySeries {

std::string replaceAll(std::string const& str, std::string const &from, std::string const &to) {
	std::string retStr(str);
	if (!from.empty()) {
		size_t start_pos = 0;
		while ((start_pos = retStr.find(from, start_pos)) != std::string::npos) {
			retStr.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
	}
	return retStr;
}

std::string replaceFirst(std::string const& str, std::string const &from, std::string const  &to) {
	std::string retStr(str);
	if (!from.empty()) {
		size_t start_pos = retStr.find(from);
		if (start_pos != std::string::npos) {
			retStr.replace(start_pos, from.length(), to);
		}
	}
	return retStr;
}

}