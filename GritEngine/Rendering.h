#pragma once
#include <vector>
#include <assert.h>
#include <stdint.h>
#include <Windows.h>
#include <DirectXColors.h>
#include "GameObject.h"
#include"Weak_Ptr.h"
#include "GLib.h"
namespace GritEngine 
{
	class RenderComponent 
	{
	private:
		static bool bQuit; 
		bool renderingactive=true;
		GLib::Sprite* sprite = nullptr;
		Weak_Ptr<GameObject> gameobject;
		void RenderSprite();
	public:
		static std::vector<RenderComponent*> RenderList;
		RenderComponent(Smart_Ptr<GameObject> go) : gameobject(go) { renderingactive = true; 
		RenderList.emplace_back(std::move(this)); }
		void addsprite(const char*);
		static void update();
		void setrendering(bool);
		void releasesprite();
		static void releaseallsprites();

	};
	void* LoadFile(const char* i_pFilename, size_t& o_sizeFile);
	GLib::Sprite* CreateSprite(const char* i_pFilename);
	
}

