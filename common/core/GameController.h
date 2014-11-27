#ifndef __SantaGnomes__GameController__
#define __SantaGnomes__GameController__

/*
    The core class to implement game logic.
    Some part of functionality may be refactored into specific classes
    to maintain meaninful class structure
 */

#include "cocos2d.h"

#include "GameModel.h"
#include "PlayerData.h"
#include "GameState.h"

#include "TouchController.h"

class GameController : public cocos2d::Node {

public:
    GameController();
    
    ~GameController();
    
    static GameController* create(cocos2d::Layer aLayer);
    
    bool init(cocos2d::Layer aLayer);
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__GameController__) */
