#ifndef __SantaGnomes__MainMenuScene__
#define __SantaGnomes__MainMenuScene__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Layer {

public:
    MainMenuScene();
    
    ~MainMenuScene();
    
    static cocos2d::Scene* createScene();
    
    static MainMenuScene* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__MainMenuScene__) */
