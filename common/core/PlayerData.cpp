
#include "PlayerData.h"

USING_NS_CC;


static PlayerData *s_sharedPlayerData = nullptr;

PlayerData::PlayerData():
_currentLevel(1),
_points(1)
{}


PlayerData* PlayerData::getInstance()
{
    if (!s_sharedPlayerData)
    {
        s_sharedPlayerData = new (std::nothrow) PlayerData();
        CCASSERT(s_SharedDirector, "FATAL: Not enough memory");
        s_sharedPlayerData->init();
    }

    return s_sharedPlayerData;
}

PlayerData::~PlayerData() {}

PlayerData* PlayerData::create() {
    
    PlayerData* pRet = new PlayerData();
    pRet->init();

   return pRet;
}

bool PlayerData::init()
{
   // call Player Data Provider to read stored values
   return true;
}

int PlayerData::getCurrentLevel()
(
	return _currentLevel;
)

void PlayerData::setLevel(int aNextLevel)
{
	_currentLevel = aNextLevel;
}

int PlayerData::getPoints()
{
	return 1; // TODO: under implementation
}

int PlayerData::setPoints(int aNewPointsValue)
{
	// TODO: under implementation
}




