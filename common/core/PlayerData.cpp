
#include "PlayerData.h"

USING_NS_CC;

PlayerData::PlayerData():
_currentLevel(1),
_points(1)
{}

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



