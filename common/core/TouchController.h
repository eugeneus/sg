#ifndef __SantaGnomes__TouchController__
#define __SantaGnomes__TouchController__

#include "cocos2d.h"

class TouchController : public cocos2d::Node {

public:
    TouchController();
    
    ~TouchController();
    
    static TouchController* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__TouchController__) */
