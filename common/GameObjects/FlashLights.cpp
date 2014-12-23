
#include "FlashLights.h"
#include "FlachLightsModeFactory.h"

USING_NS_CC;

FlashLights::FlashLights(){}

FlashLights::~FlashLights() {}

FlashLights* FlashLights::create(const std::string aFileMask, int spritesCount, float delay, cocos2d::Point aRelativePos, float aRelativeSizeFactor) {
    
    FlashLights* pRet = new FlashLights();
    
    if (!pRet->init(aFileMask, spritesCount, delay, aRelativePos, aRelativeSizeFactor))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
    
}

bool FlashLights::init(const std::string aFileMask, int spritesCount, float delay, cocos2d::Point aRelativePos, float aRelativeSizeFactor) {
    
    const std::string aFileName = CCString::createWithFormat(aFileMask.c_str(), 1)->getCString();
    if (!GameObjectBase::init(aFileName, Point(0.0, 0.0), aRelativeSizeFactor)) {
    
        return false;
    }
    
    this->setPosition(Point(aRelativePos.x, aRelativePos.y));
    
    FlachLightsModeFactory::runAction(0, this, delay, aFileMask, spritesCount);
    
    return true;
}
