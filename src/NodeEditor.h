#ifndef _NODEEDITOR_H_INCLUDED_
#define _NODEEDITOR_H_INCLUDED_
#include "common.h"
#include "EditorState.h"

class EditorMode;
class NodeEditor :public EditorMode
{
public:
	NodeEditor(EditorState* st);

	// Interface
	virtual void load();
	virtual void unload();
	virtual void update(double dtime);
	virtual void draw(irr::video::IVideoDriver* driver);
	virtual void viewportTick(Viewport window, irr::video::IVideoDriver* driver, rect<s32> offset);
	virtual bool OnEvent(const irr::SEvent &event);
	virtual irr::video::ITexture* icon();

	// The GUI ID numbers for this mode
	// NOTE: the maximum that can be here is 20
	//       see in MenuState.h to raise limit
	enum NODE_EDITOR_GUI_ID {
		ENG_GUI_MAIN_LISTBOX = GUI_SIDEBAR + 1,
		ENG_GUI_MAIN_ADD,
		ENG_GUI_MAIN_DEL,
		ENG_GUI_MAIN_EDIT,
		ENG_GUI_PROP,
		ENG_GUI_PROP_NAME,
		ENG_GUI_PROP_X,
		ENG_GUI_PROP_Y,
		ENG_GUI_PROP_Z,
		ENG_GUI_PROP_UPDATE,
		ENG_GUI_PROP_REVERT
	};
private:
	void load_ui();
	void fillProperties();
	void updateProperties();
};

#endif
