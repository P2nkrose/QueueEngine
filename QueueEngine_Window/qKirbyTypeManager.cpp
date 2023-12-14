#include "qKirbyTypeManager.h"
#include "qKirby.h"
#include "qIceKirby.h"
#include "qInput.h"


namespace Q
{
	//KirbyTypeManager::ChangeKirby(L"Basic");

	std::map<std::wstring, GameObject*> KirbyTypeManager::mKirbyType = {};

}