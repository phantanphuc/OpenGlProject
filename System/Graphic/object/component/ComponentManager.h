#ifndef __COMPONENTMANAGER_H__
#define __COMPONENTMANAGER_H__

//#include "System\Graphic\object\GraphicObject.h"

#include "SubComponentMMatrix.h"

enum ComponentType {
	NONE_COMPONENT, MESH3D, CAMERA, LIGHT_SOURCE
};




class baseComponent {
public:
	baseComponent();
	virtual ~baseComponent();


	ComponentType getType();

	SubComponentMMatrix* getSubComponentModel();
	void setSubComponentModel(SubComponentMMatrix* model);


	

protected:
	ComponentType m_type;
	SubComponentMMatrix* M_matrix_ref = nullptr;
};


class ComponentManager {
public:
	ComponentManager();
	~ComponentManager();
private:
};
#endif
