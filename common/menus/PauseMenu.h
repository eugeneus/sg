#ifndef __SantaGnomes__PauseMenu__
#define __SantaGnomes__PauseMenu__

#include "cocos2d.h"

class PauseMenu : public cocos2d::Menu {
    
public:
    PauseMenu();
    
    ~PauseMenu();
    
    static PauseMenu* create();
    
    bool init();
    
protected:
    
    void menuCallback(cocos2d::Ref* pSender);
    
private:
};

#endif /* defined(__SantaGnomes__PauseMenu__) */
