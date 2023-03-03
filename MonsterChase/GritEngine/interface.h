#pragma once
namespace GritEngine 
{
	class GameObject;
	template <class T>
	class Smart_Ptr;
	//void registerGO(Smart_Ptr<GameObject>*);
	//void tempRegisterGO(Smart_Ptr<GameObject>*);
	struct MasterObject;
	MasterObject* GetMasterObject(Smart_Ptr<GameObject>);
	
}


