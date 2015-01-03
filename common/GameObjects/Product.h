#ifndef __SantaGnomes__Product__
#define __SantaGnomes__Product__

#include "cocos2d.h"
#include "GameObjectBase.h"

class Product : public GameObjectBase {

public:
    Product();
    
    ~Product();
    
    static Product* create(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor);
    
    void setTypeID(int aTypeID);
    int getTypeID();
    
    //bool init();
    
protected:
    
    int _typeID;

private:
    
};

#endif /* defined(__SantaGnomes__Product__) */
