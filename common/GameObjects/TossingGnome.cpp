
#include "TossingGnome.h"

USING_NS_CC;

TossingGnome::TossingGnome(){}

TossingGnome::~TossingGnome() {}

TossingGnome* TossingGnome::create(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor)
{
    
    TossingGnome* pRet = new TossingGnome();
    if (!pRet->init(aFileName, aRelativePos, aRelativeSizeFactor)) {
        delete pRet;
        pRet = nullptr;
    }
    return pRet;
}


void TossingGnome::setTossingPos(cocos2d::Point& aPos)
{
    _tossPoint = aPos;
}

cocos2d::Point& TossingGnome::getTossingPos()
{
    return _tossPoint;
}




