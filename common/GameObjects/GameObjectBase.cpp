
#include "GameObjectBase.h"

USING_NS_CC;

GameObjectBase::GameObjectBase(){}

GameObjectBase::~GameObjectBase() {}

GameObjectBase* GameObjectBase::create() {

   return nullptr;
}

bool GameObjectBase::init()
{
   return false;
}

cocos2d::Point GameObjectBase::getRelativePosition()
{
    return _relativePosition;
}

void GameObjectBase::setRelativePosition(cocos2d::Point aPosition)
{
    _relativePosition = aPosition;
}

float GameObjectBase::getRelativeSizeFactor()
{
    return _relativeSizeFactor;
}

void GameObjectBase::setRelativeSizeFactor(float aFactor)
{
    _relativeSizeFactor = aFactor;
}







