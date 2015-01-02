#ifndef __SantaGnomes__TossingGnome__
#define __SantaGnomes__TossingGnome__

#include "cocos2d.h"
#include "GameObjectBase.h"

class TossingGnome : public GameObjectBase {

public:
    TossingGnome();
    
    ~TossingGnome();
    
    static TossingGnome* create(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor);
    
    //bool init();
    
    void setTossingPos(cocos2d::Point& aPos);
    
    cocos2d::Point& getTossingPos();
    
protected:
    
    cocos2d::Point _tossPoint;

private:
    
};

#endif /* defined(__SantaGnomes__TossingGnome__) */
