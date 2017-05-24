#ifndef __INPUTMANAGER_H__
#define __INPUTMANAGER_H__

#define KEYMAP_SIZE 255


class InputManager {
public:
	InputManager();
	~InputManager();

	static InputManager* getInstance();
	
	void init();

	void keyup(int keycode);
	void keydown(int keycode);

	void reset();

private:

	bool keymap[KEYMAP_SIZE];

};
#endif
