#ifndef __SantaGnomes__AnimationFactory__
#define __SantaGnomes__AnimationFactory__

#include "cocos2d.h"

// TODO:
// it may require reference to game object
// it may requre reference to GameModel
//    to some basic values directly from it
// it may require reference to Actors factory
//   to get AnimationnFrames, and times
// ..
class AnimationFactory : public cocos2d::Ref {

public:
    AnimationFactory();
    
    ~AnimationFactory();
    
    static AnimationFactory* create();
    
    bool init();
    
    cocos2d::FiniteTimeAction* getWalkingActionByType(int aTypeID, float aDuration, cocos2d::Point anEndPoint);

    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__AnimationFactory__) */
