
#ifndef __SantaGnomes__WalkingGnome__
#define __SantaGnomes__WalkingGnome__

#include "GameObjectBase.h"

#include "cocos2d.h"

class WalkingGnome : public GameObjectBase {

public:
    WalkingGnome();
    
    ~WalkingGnome();
    
    static WalkingGnome* create(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor);
    
    //bool init();
    
    void setTypeID(int aTypeID);
    
    int getTypeID();
    
protected:
    
    int _typeID;

private:
    
};

#endif /* defined(__SantaGnomes__WalkingGnome__) */
