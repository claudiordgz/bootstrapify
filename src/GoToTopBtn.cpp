#include "GoToTopBtn.hpp"

namespace StudySeries {

std::string fixGoTotop(std::string const&contents) {
	size_t pos = 0;
	std::string retStr(contents);
	std::string findStr = "Go to Top</a>",
		insertStr = R"(<a href="#claudiordgzLogo" class="btn btn-default pull-right"><span class="glyphicon glyphicon-arrow-up"></span> )";
	while ((pos = retStr.find(findStr, pos)) != std::string::npos) {
		size_t beginPos = retStr.rfind("<a", pos);
		retStr.replace(retStr.begin() + beginPos, retStr.begin() + pos, insertStr);
		pos += insertStr.length() + findStr.length();
	}
	return retStr;
}

}