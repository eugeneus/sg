#ifndef __SantaGnomes__ActorFactory__
#define __SantaGnomes__ActorFactory__

#include "cocos2d.h"


class GameObjectBase;
class WalkingGnome;

class ActorFactory : public cocos2d::Ref {

public:
    ActorFactory();
    
    ~ActorFactory();
    
    static ActorFactory* create();
    
    bool init();
    
    WalkingGnome* getActorByType(int aTypeID);
    
    
protected:
    
    cocos2d::ValueMap _actorsDB;

private:
    
};

#endif /* defined(__SantaGnomes__ActorFactory__) */
