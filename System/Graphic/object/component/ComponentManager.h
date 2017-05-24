#ifndef __COMPONENTMANAGER_H__
#define __COMPONENTMANAGER_H__

enum ComponentType {
	MESH3D, CAMERA
};

struct ComponentNode {
	ComponentType type;
	void* Component;
};

class baseComponent {
public:
	baseComponent();

private:
	ComponentType m_type;
};


class ComponentManager {
public:
	ComponentManager();
	~ComponentManager();
private:
};
#endif
