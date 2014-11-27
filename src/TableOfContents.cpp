#include "TableOfContents.hpp"
#include "StringOperations.hpp"


namespace StudySeries {

std::string fixTableOfContents(std::string const &contents) {
	std::string toc = extractToc(contents);
	std::string fixedToc = fixToc(toc);
	return replaceFirst(contents, toc, fixedToc);
}
std::string extractToc(std::string const &fileContents) {
	std::string beginStr = R"(<div class="tableofcontents">)";
	size_t beginPos = fileContents.find(beginStr);
	std::string returnStr("");
	if (beginPos != std::string::npos) {
		std::string endStr = R"(<div class="col-md-7" id="docBody">)";
		size_t endPos = fileContents.find(endStr, beginPos);
		if (endPos != std::string::npos)
			returnStr.append(fileContents.begin() + beginPos, fileContents.begin() + endPos);
	}
	return returnStr;
}


std::string fixToc(std::string const &tableOfContents) {
	size_t beginPos = 0, counter = 1;
	std::string content(tableOfContents);
	std::string findStr = R"(<span class="chapterToc")", endStr = R"(</span>)";
	tocElement instance;
	std::string insertStr(instance.bodyEnd);
	while ((beginPos = content.find(findStr, beginPos)) != std::string::npos) {
		if (counter > 1) {
			content.insert(beginPos, insertStr);
			beginPos += insertStr.length();
		}
		else {
			content.insert(beginPos, instance.globalHeaderBegin);
			beginPos += instance.globalHeaderBegin.length();
		}
		size_t endingPos = content.find(endStr, beginPos);
		if (endingPos != std::string::npos) {
			std::string localHeader = instance.header;
			std::string title(content.begin() + beginPos, content.begin() + endingPos + endStr.length());
			localHeader = replaceAll(localHeader, "{{idx}}", std::to_string(counter));
			localHeader = replaceFirst(localHeader, "{{headerMarkup}}", title);
			content = replaceFirst(content, title, localHeader);
			beginPos = content.find(localHeader) + localHeader.length();
			counter++;
		}
		else {
			// parsing error
		}
	}
	content.append(insertStr);
	content.append(instance.globalHeaderEnd);
	return content;
}


}