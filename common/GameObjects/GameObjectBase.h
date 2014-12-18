#ifndef __SantaGnomes__GameObjectBase__
#define __SantaGnomes__GameObjectBase__

#include "cocos2d.h"

class GameObjectBase : public cocos2d::Sprite {

public:
    GameObjectBase();
    
    ~GameObjectBase();
    
    static GameObjectBase* create(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor);
    
    bool init(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor);
    
    // used for objects which have static position
    // or some king of static start/end point
    cocos2d::Point getRelativePosition();
    void setRelativePosition(cocos2d::Point aPosition);
    
    // used for all game objects which are displayed on game scene
    float getRelativeSizeFactor();
    void setRelativeSizeFactor(float aFactor);
    
protected:
    
    cocos2d::Point _relativePosition; // percent of half screen size
    
    float _relativeSizeFactor; // percent of max screen dimension

private:
    
};

#endif /* defined(__SantaGnomes__GameObjectBase__) */
