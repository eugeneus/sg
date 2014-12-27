
#include "WalkingGnome.h"

WalkingGnome::WalkingGnome():
_typeID(0)
{}

WalkingGnome::~WalkingGnome() {}

WalkingGnome* WalkingGnome::create(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor)
{

    WalkingGnome* pRet = new WalkingGnome();
    if (!pRet->init(aFileName, aRelativePos, aRelativeSizeFactor)) {
        delete pRet;
        pRet = nullptr;
    }
    return pRet;
}

void WalkingGnome::setTypeID(int aTypeID)
{
    _typeID = aTypeID;
}

int WalkingGnome::getTypeID()
{
    return _typeID;
}



//void WalkingGnome::startWalkAnimation()
//{
//    this->runAction(_walkingAction);
//}
//
//void WalkingGnome::setWalkAnimation(cocos2d::FiniteTimeAction* aWalkAction)
//{
//    if (_walkingAction) {
//        //delete _walkingAction; //??
//        _walkingAction = nullptr;
//    }
//    
//    _walkingAction = aWalkAction;
//}


