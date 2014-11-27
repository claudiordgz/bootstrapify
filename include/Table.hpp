#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <string>

namespace StudySeries {

/*! @brief Enclose all tables with <div class="table-responsive"> and </div>
	*  @param fileContents the string of html content that contains the table environment
	*  @return string with new changed content */
std::string replaceTableWithReponsive(std::string const &fileContents);


}

#endif