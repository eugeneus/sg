#ifndef __SantaGnomes__ProductFactory__
#define __SantaGnomes__ProductFactory__

#include "cocos2d.h"

class ProductFactory : public cocos2d::Ref {

public:
    ProductFactory();
    
    ~ProductFactory();
    
    static ProductFactory* create();
    
    bool init();
    
protected:

private:
    
};

#endif /* defined(__SantaGnomes__ProductFactory__) */
