#ifndef __SantaGnomes__PlistHelper__
#define __SantaGnomes__PlistHelper__

#include "cocos2d.h"

class PlistHelper : public cocos2d::Ref {

public:
    PlistHelper();
    
    ~PlistHelper();
    
    static PlistHelper* create(std::string aFileName);
    
    bool init(std::string aFileName);
    
    bool updateValue(int* aValue, cocos2d::ValueMap* aSource);
    
protected:
    
    cocos2d::ValueMap _data;

private:
    
};

#endif /* defined(__SantaGnomes__PlistHelper__) */
