#include  "Table.hpp"

namespace StudySeries {

std::string replaceTableWithReponsive(std::string const &fileContents) {
	size_t pos = 0;
	std::string content(fileContents);
	std::string findStr = R"(<table)", insertStr = R"(<div class="table-responsive">)";
	while ((pos = content.find(findStr, pos)) != std::string::npos) {
		content.insert(pos, insertStr);
		std::string endStr = R"(</table>)", insertCloseStr = R"(</div>)";
		size_t endingPos = content.find(endStr, pos);
		if (endingPos != std::string::npos) {
			endingPos = endingPos + endStr.length();
			content.insert(endingPos, insertCloseStr);
		}
		pos += insertStr.length() + findStr.length();
	}
	return content;
}

}