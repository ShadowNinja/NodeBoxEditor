#ifndef _NODE_H_INCLUDED_
#define _NODE_H_INCLUDED_

#include <vector>
#include "common.h"
#include "EditorState.h"
#include "NodeBox.h"

class EditorState;
class NodeBox;
class Node
{
public:
	// Construction / Destruction
	Node(IrrlichtDevice* mdevice,EditorState* state,unsigned int id);
	~Node();

	// Node box manager
	int GetId()const{ return _selected;}
	unsigned int NodeId()const{ return _nid; }
	NodeBox* GetCurrentNodeBox();
	NodeBox* GetNodeBox(int id);
	const std::vector<NodeBox*> & GetBoxes() { return boxes; }
	NodeBox* addNodeBox();
	void deleteNodebox(int id);
	void select(int id){_selected = id;}

	// Node properties	
	vector3di getPosition() const{return nd_position;}
	void setPosition(vector3di in){nd_position = in;}
	stringc name;

	// Node bulk updaters
	void remesh(); // creates the node mesh
private:
	// Data
	std::vector<NodeBox*> boxes;
	int _selected;
	unsigned int _nid; // the node's id.
	vector3di nd_position;

	// Irrlicht
	IrrlichtDevice* _device;
	EditorState* _state;
};

#endif
