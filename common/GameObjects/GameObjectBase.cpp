
#include "GameObjectBase.h"

USING_NS_CC;

GameObjectBase::GameObjectBase(){}

GameObjectBase::~GameObjectBase() {}

GameObjectBase* GameObjectBase::create(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor)
{
	GameObjectBase* pRet = new GameObjectBase();

    if (!pRet->init(aFileName, aRelativePos, aRelativeSizeFactor))
    {
		delete pRet;
		pRet = nullptr;
    }

    return pRet;

}
    
bool GameObjectBase::init(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor)
{
		
		if(!initWithFile(aFileName)){ // initWithSpriteFrameName
			return false; 
		}
		
	_relativePosition = aRelativePos;
    _relativePosition.set(&aRelativeSizeFactor); // = aRelativeSizeFactor;

	return true;
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







