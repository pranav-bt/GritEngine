#pragma once
#include <String>
template <class T>
class Smart_Ptr;
#include "MasterList.h"
namespace GritEngine
{
	// The initial plan was to make a template component class, incase the user wants add more custom components. 
	template <class T>
	class Component
	{
	private:
		T ComponentName;
	public:
		Component(Smart_Ptr<T> GO, Component<T> comp) { ComponentName = comp; RegisterComponent(GO,Name)};
		void RegisterComponent(Smart_Ptr<T> GO, std::string compname)
		{
			
		}
	};
}