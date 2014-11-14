#ifndef __SantaGnomes__MainMenu__
#define __SantaGnomes__MainMenu__

#include "cocos2d.h"

class MainMenu : public cocos2d::Menu {

public:
    MainMenu();
    
    ~MainMenu();
    
    static MainMenu* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__MainMenu__) */
