#ifndef _EDITORSTATE_H_INCLUDE_
#define _EDITORSTATE_H_INCLUDE_
#include "common.h"
#include "Configuration.hpp"
#include "Project.h"
#include "MenuState.h"

#define NUMBER_OF_KEYS 252
enum KeyState{
	EKS_UP = false,
	EKS_DOWN = true
};

enum Viewport
{
	VIEW_PERS,
	VIEW_XZ,
	VIEW_XY,
	VIEW_ZY
};


class Project;
class EditorMode;
class MenuState;
class EditorState
{
public:
	EditorState(irr::IrrlichtDevice* dev, Project* proj, Configuration* settings);

	// Irrlicht
	ITriangleSelector* plane_tri;
	IrrlichtDevice* device;

	// Project
	Project* project;

	// Editor
	EditorMode* Mode(int id) const
	{
		if (id < 0 || id >= 5) {
			return NULL;
		}
		return modes[id];
	}
	EditorMode* Mode() const
	{
		return Mode(currentmode);
	}

	void SelectMode(int id);
	
	void AddMode(EditorMode *value);	
	MenuState* Menu() const { return menu; }
	void SetMenu(MenuState* stat) { menu = stat; }	
	void CloseEditor() { close_requested = true; }
	bool NeedsClose() const { return close_requested; }

	// Input
	bool mousedown;
	irr::core::vector2di mouse_position;
	KeyState keys[NUMBER_OF_KEYS];
	
	Configuration* settings;
private:
	int currentmode;
	EditorMode* modes[5];
	int modeCount;
	MenuState* menu;
	bool close_requested;
};

class EditorMode : public irr::IEventReceiver
{
public:
	EditorMode(EditorState* st) : state(st) {}
	virtual void load() = 0;
	virtual void unload() = 0;
	virtual void update(double dtime) = 0;
	virtual void draw(irr::video::IVideoDriver* driver) = 0;
	virtual void viewportTick(Viewport window, irr::video::IVideoDriver* driver, rect<s32> offset) = 0;
	virtual bool OnEvent(const irr::SEvent &event) = 0;
	virtual irr::video::ITexture* icon() = 0;

	int id;
	EditorState* state;
};

#endif
