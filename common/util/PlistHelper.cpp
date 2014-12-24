
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
    _data = FileUtils::getInstance()->getValueMapFromFile(aFileName);
    return true;
}

bool PlistHelper::updateButeValue(char& aValue, std::string aKey,cocos2d::ValueMap* aSource)
{
    bool retVal  = true;
    ValueMap* src = nullptr;
    if (aSource) {
        src = aSource;
        
    }
    else{
        src = &_data;
    }
    
    if (src->count(aKey)) {
        aValue  = src->at(aKey).asByte();
    }
    else{
        retVal = false;
    }
    
    return retVal;
}

bool PlistHelper::updateIntValue(int& aValue, std::string aKey,cocos2d::ValueMap* aSource)
{
    bool retVal  = true;
    ValueMap* src = nullptr;
    if (aSource) {
        src = aSource;
        
    }
    else{
        src = &_data;
    }
    
    if (src->count(aKey)) {
        aValue  = src->at(aKey).asInt();
    }
    else{
        retVal = false;
    }
    
    return retVal;
}

bool PlistHelper::updateFloatValue(float& aValue, std::string aKey,cocos2d::ValueMap* aSource)
{
    bool retVal  = true;
    ValueMap* src = nullptr;
    if (aSource) {
        src = aSource;
        
    }
    else{
        src = &_data;
    }
    
    if (src->count(aKey)) {
        aValue  = src->at(aKey).asFloat();
    }
    else{
        retVal = false;
    }
    
    return retVal;
}

bool PlistHelper::updateDoubleValue(double& aValue, std::string aKey,cocos2d::ValueMap* aSource)
{
    bool retVal  = true;
    ValueMap* src = nullptr;
    if (aSource) {
        src = aSource;
        
    }
    else{
        src = &_data;
    }
    
    if (src->count(aKey)) {
        aValue  = src->at(aKey).asDouble();
    }
    else{
        retVal = false;
    }
    
    return retVal;
}

bool PlistHelper::updateBoolValue(bool& aValue, std::string aKey,cocos2d::ValueMap* aSource)
{
    bool retVal  = true;
    ValueMap* src = nullptr;
    if (aSource) {
        src = aSource;
        
    }
    else{
        src = &_data;
    }
    
    if (src->count(aKey)) {
        aValue  = src->at(aKey).asBool();
    }
    else{
        retVal = false;
    }
    
    return retVal;
}

bool PlistHelper::updateStringValue(std::string& aValue, std::string aKey,cocos2d::ValueMap* aSource)
{
    bool retVal  = true;
    ValueMap* src = nullptr;
    if (aSource) {
        src = aSource;
        
    }
    else{
        src = &_data;
    }
    
    if (src->count(aKey)) {
        aValue  = src->at(aKey).asString();
    }
    else{
        retVal = false;
    }
    
    return retVal;
}

bool PlistHelper::updateValueVectorValue(cocos2d::ValueVector& aValue, std::string aKey,cocos2d::ValueMap* aSource)
{
    bool retVal  = true;
    ValueMap* src = nullptr;
    if (aSource) {
        src = aSource;
        
    }
    else{
        src = &_data;
    }
    
    if (src->count(aKey)) {
        aValue  = src->at(aKey).asValueVector();
    }
    else{
        retVal = false;
    }
    
    return retVal;
}

bool PlistHelper::updateValueMapValue(cocos2d::ValueMap& aValue, std::string aKey,cocos2d::ValueMap* aSource)
{
    bool retVal  = true;
    ValueMap* src = nullptr;
    if (aSource) {
        src = aSource;
        
    }
    else{
        src = &_data;
    }
    
    if (src->count(aKey)) {
        aValue  = src->at(aKey).asValueMap();
    }
    else{
        retVal = false;
    }
    
    return retVal;
}

bool PlistHelper::updateIntKeyMapValue(cocos2d::ValueMapIntKey aValue, std::string aKey,cocos2d::ValueMap* aSource)
{
    bool retVal  = true;
    ValueMap* src = nullptr;
    if (aSource) {
        src = aSource;
        
    }
    else{
        src = &_data;
    }
    
    if (src->count(aKey)) {
        aValue  = src->at(aKey).asIntKeyMap();
    }
    else{
        retVal = false;
    }
    
    return retVal;
}
