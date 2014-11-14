#ifndef __SantaGnomes__GameScene__
#define __SantaGnomes__GameScene__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer {

public:
    GameScene();
    
    ~GameScene();
    
    static cocos2d::Scene* createScene();
    
    static GameScene* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__GameScene__) */
