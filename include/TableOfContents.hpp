#ifndef __TABLEOFCONTENTS_HPP__
#define __TABLEOFCONTENTS_HPP__

#include <string>

namespace StudySeries {

/*! @brief Code to make a collapsable chapter in the TableOfContents */
struct tocElement {
	std::string globalHeaderBegin = R"(<div class="panel-group" id="accordionToc">)";
	std::string globalHeaderEnd = R"(</div>)";
	/// @brief the preamble, replace the markup {{}} elements. 
	/// idx with a unique number
	/// headerMarkup with the previous header markup
	std::string header = R"(
<div class="panel panel-default">
<div class="panel-heading">
    <h4 class="panel-title">
    <a class="accordion-toggle" data-toggle="collapse" data-parent="#accordionToc" href="#collapseToc{{idx}}">
<span class="pull-right clickable"><i class="glyphicon glyphicon-chevron-up"></i></span> 
{{headerMarkup}}
</h4>
</div>
<div id="collapseToc{{idx}}" class="panel-collapse collapse">
    <div class="panel-body">)";
	/// @brief closing tags for the preamble
	std::string bodyEnd = R"(
</div>
</div>
</div>)";
};


/*! @brief Each chapter in the TableOfContents must be enclosed with a Bootstrap 3 accordion
*  @param fileContents the string of html content that contains the table environment
*  @return string with new changed content */
std::string fixToc(std::string const &fileContents);

/*! @brief Find the TableOfContents in the file and extract it
*  @param fileContents the string of html content
*  @return string with new changed content */
std::string extractToc(std::string const &fileContents);

/*! @brief Replaces TableOfContents with Accordion and returns fixed one
*  @param contents */
std::string fixTableOfContents(std::string const &contents);

}

#endif