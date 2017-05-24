#include "ObjectManager.h"

ObjectManager* m_objectmanager_instance = nullptr;


ObjectManager::ObjectManager(){

}

ObjectManager::~ObjectManager(){
	while (object_list != nullptr) {
		ObjectNode* delptr = object_list;
		object_list = object_list->next;
		delete delptr->obj;
		delete delptr;
	}
}



void ObjectManager::addNode(GraphicObject * obj)
{
	if (object_list == nullptr) {
		object_list = new ObjectNode;
		object_list->obj = obj;
		tail = object_list;
	}
	else {
		tail->next = new ObjectNode;
		tail = tail->next;
		tail->obj = obj;
	}

}

void ObjectManager::ExecuteObject()
{
	for (ObjectNode* ptr = object_list; ptr != nullptr; ptr = ptr->next) {
		ptr->obj->Execute();
	}
}
