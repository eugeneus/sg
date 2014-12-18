#ifndef __SantaGnomes__Heap__
#define __SantaGnomes__Heap__

#include "cocos2d.h"

class Heap : public cocos2d::GameObjectBase {

public:
    Heap();
    
    ~Heap();
    
    static Heap* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__Heap__) */
