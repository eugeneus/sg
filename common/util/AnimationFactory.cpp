
#include "AnimationFactory.h"

USING_NS_CC;

AnimationFactory::AnimationFactory(){}

AnimationFactory::~AnimationFactory() {}

AnimationFactory* AnimationFactory::create() {

    AnimationFactory* pRet = new AnimationFactory();
    if (!pRet->init()) {
        delete pRet;
        pRet = nullptr;
    }
    return pRet;
}

bool AnimationFactory::init()
{
   return true;
}

cocos2d::FiniteTimeAction* AnimationFactory::getWalkingActionByType(int aTypeID, float aDuration, cocos2d::Point anEndPoint)
{
    FiniteTimeAction* walkCombinedAction = nullptr;
    
    switch (aTypeID) {
        case 1:
            walkCombinedAction = cocos2d::MoveTo::create(aDuration, anEndPoint);
            break;
            
        default:
            walkCombinedAction = cocos2d::MoveTo::create(aDuration, anEndPoint);
            break;
    }
    
    
    return walkCombinedAction;
    
    //for animation we wil need:
    
    //frames, farame time,  -- this is from factory
    // duration, end point  - from model
    
}




