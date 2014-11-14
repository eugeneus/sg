#ifndef __SantaGnomes__MainMenuScene__
#define __SantaGnomes__MainMenuScene__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Scene {

public:
    MainMenuScene();
    
    ~MainMenuScene();
    
    static Scene* createScene();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__MainMenuScene__) */
