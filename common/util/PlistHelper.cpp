
#include "PlistHelper.h"

USING_NS_CC;

PlistHelper::PlistHelper(){}

PlistHelper::~PlistHelper() {}

PlistHelper* PlistHelper::create(std::string aFileName) {
    
    PlistHelper* pRet = new PlistHelper();
    if (!pRet->init(aFileName)) {
        delete pRet;
        pRet = nullptr;
    }
   return pRet;
}

bool PlistHelper::init(std::string aFileName)
{
   return true;
}

bool updateValue(int* aValue, cocos2d::ValueMap* aSource)
{
    return true;
}



