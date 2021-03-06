
#include "ProductFactory.h"
#include "GameObjectBase.h"
#include "Product.h"

USING_NS_CC;

ProductFactory::ProductFactory(){}

ProductFactory::~ProductFactory() {}

ProductFactory* ProductFactory::create() {

    ProductFactory* pRet = new ProductFactory();
    if (!pRet->init("Products.plist")) {
        delete pRet;
        pRet = nullptr;
    }
    return pRet;
}

Product* ProductFactory::getProductByType(int aTypeID)
{
    
    
    ValueVector productArray;
    updateValueVectorValue(productArray, "Root",nullptr);
    
    ValueMap productMap = productArray.at(aTypeID).asValueMap();
    
    std::string baseFrameName;
    updateStringValue(baseFrameName, "BaseFrameName", nullptr);
    
    float posX = 0.0f;
    updateFloatValue(posX, "PosX", &productMap);
    float posY = 0.0f;
    updateFloatValue(posY, "PosY", &productMap);
    float size = 0.0f;
    updateFloatValue(size, "Size", &productMap);
    
    Product* product = Product::create(baseFrameName, cocos2d::Point(posX,posY), size);
    product->setTypeID(aTypeID);
    
    //// under construction
    // may create frame animation
    int frames;
    updateIntValue(frames, "countFrames", &productMap);
    if (frames) {
        // create frame animation
    }
    
    //// under construction
    
    return product;

}





