#ifndef __SantaGnomes__StateDataProvider__
#define __SantaGnomes__StateDataProvider__

#include "cocos2d.h"

class StateDataProvider : public cocos2d::Node {

public:
    StateDataProvider();
    
    ~StateDataProvider();
    
    static StateDataProvider* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__StateDataProvider__) */
