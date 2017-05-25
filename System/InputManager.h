#ifndef __INPUTMANAGER_H__
#define __INPUTMANAGER_H__

#include <Windows.h>

#define KEYMAP_SIZE 255

struct keymap
{
public:
	bool getKeyState(int key_id);
private:
	bool map[KEYMAP_SIZE];
	friend class InputManager;
};

class InputManager {
public:
	InputManager();
	~InputManager();

	static InputManager* getInstance();
	
	void init();

	void keyup(int keycode);
	void keydown(int keycode);

	void reset();

	keymap * getKeyMap();

private:

	keymap map;

	

};
#endif
