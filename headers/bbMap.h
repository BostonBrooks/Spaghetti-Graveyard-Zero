/**
 * @file
 * @brief bbMap stores game data pertaining to one map in the game
 */
#ifndef BBMAP_H
#define BBMAP_H

#include "headers/bbSystemIncludes.h"
#include "headers/bbMapConstants.h"
#include "headers/bbTextures.h"
#include "headers/bbSprites.h"
#include "headers/bbAnimation.h"
#include "headers/bbWidget.h"

typedef struct {

	bbMapConstants p_Constants;

	char* m_path;  //path to map folder

	char m_Name[128];
	bbTextures* m_Textures;
	bbSprites* m_Sprites;
	bbAnimations* m_Animations;
	//bbSkins* m_Skins;

	//vtables


	//bbElevations* m_Elevations;
	//bbTerrainSquares* m_Terrain;
	//bbDrawables* m_Drawables;
	//bbActors* m_Actors;
	bbWidgets* m_Widgets;

	//bbMapCoords m_Viewpoint;
	//int32_t m_ViewpointDrawable;


	/// Increased with every update of the map
	//int32_t m_MapTime;

} bbMap;


int32_t bbMap_new(bbMap** self, char* folderPath);

#endif //BBMAP_H
