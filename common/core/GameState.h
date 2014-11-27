#ifndef __SantaGnomes__GameState__
#define __SantaGnomes__GameState__

#include "cocos2d.h"

#include "StateDataProvider.h"

class GameState : public cocos2d::Node {

public:
    GameState();
    
    ~GameState();
    
    static GameState* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__GameState__) */
