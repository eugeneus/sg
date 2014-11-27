#ifndef __SantaGnomes__PlayerDataProvider__
#define __SantaGnomes__PlayerDataProvider__

#include "cocos2d.h"

class PlayerDataProvider : public cocos2d::Node {

public:
    PlayerDataProvider();
    
    ~PlayerDataProvider();
    
    static PlayerDataProvider* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__PlayerDataProvider__) */
