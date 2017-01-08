#include "display_object.h"
#include <string.h>
#include <vector>
class text_object : public display_object
{
public:
	
	void			draw(glm::mat4 display_matrix);

private:

	std::vector<std::string>			text;		//Text to display 


};