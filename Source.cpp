#include<iostream>
#include <cstdio>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include "EngineInitializer.h"
#include "Point2D.h"
#include "test.cpp"
#include <vector>
#include <assert.h>
#include <stdint.h>
#include <Windows.h>
#include <DirectXColors.h>
#include "Rendering.h"
#include "GLib.h"
#include "Player.h"
#include"Monster.h"
#include "ClockTimer.h"
#include"Smart_Ptr.h"
#include "Application.h"
#include "GameObject.h"
#include <map>
using namespace GritEngine;
#if defined _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif // _DEBUG
static _CrtMemState gMemState;

char r[100];
unsigned int KEYID;


int MonsterChase();

void* operator new(size_t size)
{
    return malloc(size);
}

void operator delete(void* memory)
{
    free(memory);
}


void TestKeyCallback(unsigned int i_VKeyID, bool bWentDown)
{

    //const size_t	lenBuffer = 65;
    //char			Buffer[lenBuffer];
    //sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
    //OutputDebugStringA(Buffer);
    if(bWentDown==true)
    {
        KEYID = i_VKeyID;
    }
    else if (bWentDown == false)
    {
        KEYID = NULL;
    }

}

void MonsterLogic(std::vector<GritEngine::Smart_Ptr<GritEngine::GameObject>> monsterlist);

int WINAPI wWinMain(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow)
{
    // IMPORTANT: first we need to initialize GLib
   
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF);
    _CrtMemCheckpoint(&gMemState);
    atexit([]() { _CrtMemDumpAllObjectsSince(&gMemState); });

    bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "GLibTest", -1, 800, 600, true);

    if (bSuccess)
    {
        // IMPORTANT (if we want keypress info from GLib): Set a callback for notification of key presses
        GLib::SetKeyStateChangeCallback(TestKeyCallback);
        MonsterChase();
       
        // IMPORTANT:  Tell GLib to shutdown, releasing resources.
        GLib::Shutdown();
    }
    
#if defined _DEBUG
   // _CrtDumpMemoryLeaks();
#endif // _DEBUG
    //int r = 2;
}


int MonsterChase()
{
    int monsternumber = 2;
    //std::vector<GritEngine::Smart_Ptr<GritEngine::GameObject>> monsterlist;
    GritEngine::initialize();
    Smart_Ptr<GameObject> temp(new Monster("Default", Point2D(rand() % 100, rand() % 100)));
    getphysicscomponent(temp)->setphysics(true);
    getrendercomponent(temp)->addsprite("data\\BadGuy.dds");
    //monsterlist.push_back(temp);
   
    Smart_Ptr<GameObject> player(new Player("Player",Point2D(0,0)));
    auto player_physicscomp = getphysicscomponent(player);
    player_physicscomp->setphysics(true);
    player_physicscomp->physics->mass = 1;
    getrendercomponent(player)->addsprite("data\\GoodGuy.dds");
    char a = 'a';
    bool once = false;
    //MonsterLogic(monsterlist);
    while (a != 'q')
    {
        
        if (once == false)
        {
            auto pc = getphysicscomponent(temp);
            pc->physics->velocity = { -0.4,-0.3 };
            pc->physics->force = { -0.5,-0.5 };
            pc->physics->mass = 1;
            once = true;
        }
        if (KEYID == 0x0051)  //press q
        {
            Application::application_end();
            a ='q';
        }
        if (KEYID == 0x0044)
        {
            player_physicscomp->physics->velocity = { 1,0 };
            player_physicscomp->physics->force = { 0.7f,0};
            KEYID = NULL;
        }
        if (KEYID == 0x0053)
        {
            player_physicscomp->physics->velocity = { 0,-1 };
            player_physicscomp->physics->force = { 0,-0.7f };
            KEYID = NULL;
        }
        if (KEYID == 0x0057)
        {
            player_physicscomp->physics->velocity = { 0,1 };
            player_physicscomp->physics->force = { 0,0.7f };
            KEYID = NULL;
        }
        if (KEYID == 0x0041)
        {
            player_physicscomp->physics->velocity = { -1,0 };
            player_physicscomp->physics->force = { -0.7f,0 };
            KEYID = NULL;
        }
        Application::application_update();
        //GritEngine::Application::application_end();
        //a = 'q';
    }
    return 0;
}

void MonsterLogic(std::vector<Smart_Ptr<GameObject>> monsterlist)
{
    for (auto it = begin(monsterlist); it != end(monsterlist); ++it) 
    {
        auto pc = getphysicscomponent(*it);
        pc->physics->accelaration = {-0.01, -0.01};
        pc->physics->velocity = { -0.4,-0.4 };
        pc->physics->force = { 2,2 };
        pc->physics->mass = 1;
    }
}