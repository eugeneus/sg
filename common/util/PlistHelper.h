#ifndef __SantaGnomes__PlistHelper__
#define __SantaGnomes__PlistHelper__

#include "cocos2d.h"

class PlistHelper : public cocos2d::Ref {

public:
    PlistHelper();
    
    ~PlistHelper();
    
    static PlistHelper* create(std::string aFileName);
    
    bool init(std::string aFileName);
    
    bool updateButeValue(char& aValue, std::string aKey,cocos2d::ValueMap* aSource);
    
    bool updateIntValue(int& aValue, std::string aKey,cocos2d::ValueMap* aSource);
    
    bool updateFloatValue(float& aValue, std::string aKey,cocos2d::ValueMap* aSource);
    
    bool updateDoubleValue(double& aValue, std::string aKey,cocos2d::ValueMap* aSource);
    
    bool updateBoolValue(bool& aValue, std::string aKey,cocos2d::ValueMap* aSource);
    
    bool updateStringValue(std::string& aValue, std::string aKey,cocos2d::ValueMap* aSource);
    
    bool updateValueVectorValue(cocos2d::ValueVector& aValue, std::string aKey,cocos2d::ValueMap* aSource);
    
    bool updateValueMapValue(cocos2d::ValueMap& aValue, std::string aKey,cocos2d::ValueMap* aSource);
    
    bool updateIntKeyMapValue(cocos2d::ValueMapIntKey aValue, std::string aKey,cocos2d::ValueMap* aSource);
    
    
protected:
    
    cocos2d::ValueMap _data;

private:
    
};

#endif /* defined(__SantaGnomes__PlistHelper__) */
