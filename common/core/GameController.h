#ifndef __SantaGnomes__GameController__
#define __SantaGnomes__GameController__

/*
    The core class to implement game logic.
    Some part of functionality may be refactored into specific classes
    to maintain meaninful class structure
 */

#include "cocos2d.h"

class PlayerData;
class GameState;
class TouchController;
class GameModel;
class GameObjectBase;
//class ActorFactory;
//class ProductFactory;
class AnimationFactory;

class GameController : public cocos2d::Ref {

public:
    GameController();
    
    ~GameController();
    
    static GameController* create(cocos2d::Layer* aLayer);
    
    bool init(cocos2d::Layer* aLayer);
    
    void update(float dt);
    
protected:
    
    PlayerData* _playerData;
    GameModel* _theModel;
    TouchController* _touchCtl;
    //ActorFactory* _actorFactory;
    //ProductFactory* _productFactory;
    AnimationFactory* _animationFactory;
    
    float _launchCountDown;
    float _tossCountDown;
    float _tossCountCountDown;
    
    

private:
    
};

#endif /* defined(__SantaGnomes__GameController__) */
