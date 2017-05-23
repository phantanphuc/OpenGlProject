#ifndef __OBJECTMANAGER_H__
#define __OBJECTMANAGER_H__

#include "GraphicObject.h"

struct ObjectNode
{
	GraphicObject* obj;
	ObjectNode* next = nullptr;
};

class ObjectManager {
public:
	ObjectManager();
	~ObjectManager();

	void addNode(GraphicObject* obj);

	void ExecuteObject();

private:
	ObjectNode* object_list = nullptr;
	ObjectNode* tail = nullptr;
};
#endif
