#include <glm/glm.hpp>

class game
{
public:
	game(int argc, char** argv);

	void set_screensize(int size_x, int size_y, bool fullscreen);
	void set_screensize(glm::vec2 size, bool fullscreen);

	void init(void);

	void mainloop();


	//callbacks

	static void display();
	static void event_mouseMove(int x,int y);
	static void event_mouseClick(int button, int state, int x, int y);
	static void event_keyPress(int key, int state);


private:
//#####	Functions ######

	void init_glut();
	void init_glew();
	
//#####	Variables ######

	//Startup 
	int					argc;
	char**				argv;

	//OpenGL Variables

	glm::vec2			screeSize;			//Contains the Size of the screen
	bool				fullscreen;			//is the game fullscreen (default false)

};