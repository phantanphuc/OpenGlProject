#include "InputManager.h"

InputManager* m_instance_inputManager = nullptr;

InputManager::InputManager(){

}

InputManager::~InputManager(){

}

InputManager * InputManager::getInstance()
{
	if (m_instance_inputManager == nullptr) {
		m_instance_inputManager = new InputManager;
	}
	return m_instance_inputManager;
}

void InputManager::init()
{
	reset();
}

void InputManager::keyup(int keycode)
{
	keymap[keycode] = false;
}

void InputManager::keydown(int keycode)
{
	keymap[keycode] = true;
}

void InputManager::reset()
{
	for (int i = 0; i < KEYMAP_SIZE; ++i) {
		keymap[i] = false;
	}
}
