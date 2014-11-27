#ifndef __STRINGOPERATIONS__HPP__
#define __STRINGOPERATIONS__HPP__

#include <string>

namespace StudySeries {

/*! @brief Replaces all the strings with another
*  @param str source content string
*  @param from the original string to be replaced
*  @param to the end string
*  @return modified string */
std::string replaceAll(std::string const& str, std::string const &from, std::string const &to);

/*! @brief Replaces the first string with another
*  @param str source content string
*  @param from the original string to be replaced
*  @param to the end string
*  @return modified string */
std::string replaceFirst(std::string const& str, std::string const &from, std::string const  &to);
}
#endif