#include "Application.h"

namespace GritEngine
{
	std::vector<Delay*> Delay::DelayHandleList = std::vector<Delay*>();
	bool Application::ApplicationRunning = true;
	void Application::application_end()
	{
		RenderComponent::releaseallsprites();
		for (auto& element : MasterList::mastermap)
		{
			delete element.second;
		}
		for (auto element : Delay::DelayHandleList)
		{
			delete element;
		}
		Engine::JobSystem::RequestShutdown();
		Physics::PhysicsList.clear();
		Physics::PhysicsList.reserve(0);
		Physics::PhysicsList.shrink_to_fit();
		RenderComponent::RenderList.clear();
		RenderComponent::RenderList.reserve(0);
		RenderComponent::RenderList.shrink_to_fit();
		collision::collisionlist.clear();
		collision::collisionlist.shrink_to_fit();
		Delay::DelayHandleList.clear();
		Delay::DelayHandleList.shrink_to_fit();
		destroyfunctionmap();
		MasterList::mastermap.clear();
		ApplicationRunning = false;
	}
	void Application::application_update()
	{
		if(ApplicationRunning)
		{ 
		float dt;
		dt = GritEngine::DeltaTime();
		RenderComponent::update();
		Physics::update(dt/1000);
		collision::update(dt/1000);
		if(Delay::DelayHandleList.size() > 0)
		{
			for (auto element : Delay::DelayHandleList)
			{
				if (element->value <= 0 && element->done!=true)
				{
					element->done = true;
					Delay::DelayHandleList.shrink_to_fit();
				}
				else
				{
					element->value -= dt;
				}
			}
		}
		}
	}
	void Application::application_initialize()
	{
		InitializeClock();
		Engine::JobSystem::Init();
		//TempMasterMap = {};
		CreateGameObject();
	}


}