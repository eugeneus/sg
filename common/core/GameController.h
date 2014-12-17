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

class GameController : public cocos2d::Node {

public:
    GameController();
    
    ~GameController();
    
    static GameController* create(cocos2d::Layer* aLayer);
    
    bool init(cocos2d::Layer* aLayer);
    
protected:
    
    PlayerData* _playerData;
    GameModel* _theModel;
    TouchController* _touchCtl;

private:
    
};

#endif /* defined(__SantaGnomes__GameController__) */
