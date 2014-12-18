#ifndef __SantaGnomes__GameObjectBase__
#define __SantaGnomes__GameObjectBase__

#include "cocos2d.h"

class GameObjectBase : public cocos2d::Sprite {

public:
    GameObjectBase();
    
    ~GameObjectBase();
    
    static GameObjectBase* create();
    
    bool init();
    
    // used for objects which have static position
    // or some king of static start/end point
    cocos2d::Point getRelativePosition();
    void setRelativePosition(cocos2d::Point aPosition);
    
    // used for all game objects which are displayed on game scene
    float getRelativeSizeFactor();
    void setRelativeSizeFactor(float aFactor);
    
protected:
    
    cocos2d::Point _relativePosition;
    
    float _relativeSizeFactor;

private:
    
};

#endif /* defined(__SantaGnomes__GameObjectBase__) */
