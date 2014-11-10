
#ifndef __SantaGnomes__GameScene__
#define __SantaGnomes__GameScene__

#include "cocos2d.h"

class GameScene : Layer {

public:
    GameScene();
    
    ~GameScene();
    
    static cocos2d::Scene* createScene();
    
    
    //static GameScene* create();
    
    bool init();
    
protected:

private:
    typedef Layer super;
    

};
#endif /* defined(__SantaGnomes__GameScene__) */
