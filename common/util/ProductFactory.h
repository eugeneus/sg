#ifndef __SantaGnomes__ProductFactory__
#define __SantaGnomes__ProductFactory__

#include "cocos2d.h"
#include "PlistHelper.h"

class GameObjectBase;

class ProductFactory : public PlistHelper {

public:
    ProductFactory();
    
    ~ProductFactory();
    
    static ProductFactory* create();
    
    GameObjectBase* getProductByType(int aTypeID);
    
protected:
    
    cocos2d::ValueMap _productDB;

private:
    
};

#endif /* defined(__SantaGnomes__ProductFactory__) */
