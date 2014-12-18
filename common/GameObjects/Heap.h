#ifndef __SantaGnomes__Heap__
#define __SantaGnomes__Heap__

#include "cocos2d.h"
#include "GameObjectBase.h"

class Heap : public GameObjectBase {

public:
    Heap();
    
    ~Heap();
    
    static Heap* create(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor);
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__Heap__) */
