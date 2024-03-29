/**
 * @file
 * @brief The functions in this folder define the behavior of an object with class bbWidget and type NULL
 */
#define BBDEBUG

#include "headers/bbPrintf.h"

#include "headers/bbGeometry.h"
#include "headers/bbWidget.h"
#include "headers/bbGame.h"
#include "headers/bbMap.h"

///	Spawn a null widget on selected map at coordinates mc
int32_t bbWidget_Decal_new(bbWidget** reference, bbWidgets* widgets, bbScreenCoordsI sc, int32_t parent){

	bbPool* pool = widgets->m_Pool;

	//TODO make more use of this
	bbDictionary* dict = widgets->m_AddressDict;

	bbWidget* widget;
	int32_t flag;

	flag = bbPool_New(&widget, pool, f_PoolNextAvailable);


	bbScreenCoordsF SCF;
	bbScreenCoordsI SCI;
	SCF.x = 0;
	SCF.y = 0;
		SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	widget->m_ScreenCoords = SCI;

	SCF.x = 1280;
	SCF.y = 720;
	SCI = bbScreenCoordsF_getI(SCF, &g_Game->m_Maps[widget->p_Node.p_Pool.Map]->p_Constants);
	widget->m_Dimensions = sc;

	widget->m_Visible = true;
	widget->m_SubwidgetsVisible = true;


	bbDictionary* spriteDict = g_Game->m_Maps[widget->p_Node.p_Pool.Map]->m_Sprites->m_Dictionary;
	int32_t spriteInt = bbDictionary_lookup(spriteDict, "DECAL_1280");
	widget->m_SpriteInt = spriteInt;

	for(int32_t i = 0; i < ANIMATIONS_PER_WIDGET; i++){
		widget->m_AnimationInt[i] = f_None;
		widget->m_Angle[i] = 0;
		widget->m_Frame[i] = 0;
		widget->m_AnimationDraw[i] = f_None;
	}


	bbWidgetFunctions* functions = widgets->m_Functions;

	widget->m_OnDraw = bbWidgetFunctions_getInt(functions, wf_DrawFunction, "decal");
	widget->p_Node.p_Tree.Parent = f_None;
	widget->p_Node.p_Tree.Head = f_None;
	widget->p_Node.p_Tree.Tail = f_None;
	widget->p_Node.p_Tree.Prev = f_None;
	widget->p_Node.p_Tree.Next = f_None;

	widgets->m_Decal = widget;
	*reference = widget;

	return f_Success;
}

/// Update widget
int32_t bbWidget_Decal_update(bbWidget* widget){}

/// Send a command to the widget / update widget, etc
int32_t bbWidget_Decal_onCommand(bbWidget* widget, int32_t command, void* data){}

/// Delete widget
int32_t bbWidget_Decal_delete(bbWidget* widget){}

/// Draw widget to screen
int32_t bbWidget_Decal_draw(bbWidget* widget){

	//draw self
	int32_t map = widget->p_Node.p_Pool.Map;
	sfSprite* sprite = g_Game->m_Maps[map]->m_Sprites->m_Sprites[widget->m_SpriteInt];



	bbScreenCoordsF SCF = bbScreenCoordsI_getF(widget->m_ScreenCoords, &g_Game->m_Maps[map]->p_Constants);

	sfVector2f position;
	position.x = SCF.x;
	position.y = SCF.y;


	sfSprite_setPosition(sprite, position);

	sfRenderWindow_drawSprite(g_Game->m_Window, sprite, NULL);

	//draw subwidgets


	//draw subwidgets
	int32_t subwidgetInt = widget->p_Node.p_Tree.Head;
	bbWidget* subwidget;
	int32_t flag;
	bbPool* pool = g_Game->m_Maps[widget->p_Node.p_Pool.Map]->m_Widgets->m_Pool;


	while (subwidgetInt >= 0){
		flag = bbPool_Lookup(&subwidget, pool, subwidgetInt);
		bbWidget_draw(subwidget);
		subwidgetInt = subwidget->p_Node.p_Tree.Next;
	}



	return f_Success;
}
