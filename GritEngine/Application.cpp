#include "Application.h"
//#include <Thread>
namespace GritEngine
{
	bool Application::ApplicationRunning = true;
	void Application::application_end()
	{
		RenderComponent::releaseallsprites();
		for (auto& element : MasterList::mastermap)
		{
			delete element.second;
		}
		Physics::PhysicsList.clear();
		Physics::PhysicsList.reserve(0);
		Physics::PhysicsList.shrink_to_fit();
		RenderComponent::RenderList.clear();
		RenderComponent::RenderList.reserve(0);
		RenderComponent::RenderList.shrink_to_fit();
		MasterList::mastermap.clear();
		ApplicationRunning = false;
	}
	void Application::application_update()
	{
		if(ApplicationRunning)
		{ 
		float dt;
		dt = GritEngine::DeltaTime();
		//std::thread work(GritEngine::RenderComponent::update);
		RenderComponent::update();
		Physics::update(dt);
		}
	}
}