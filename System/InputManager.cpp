#include "InputManager.h"

InputManager* m_instance_inputManager = nullptr;

InputManager::InputManager(){
	init();
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
	map.map[keycode] = false;
}

void InputManager::keydown(int keycode)
{
	map.map[keycode] = true;
}

void InputManager::reset()
{
	for (int i = 0; i < KEYMAP_SIZE; ++i) {
		map.map[i] = false;
	}
}

keymap * InputManager::getKeyMap()
{
	return &map;
}

bool keymap::getKeyState(int key_id)
{
	return map[key_id];
}
