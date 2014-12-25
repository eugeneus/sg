
#include "ProductFactory.h"

USING_NS_CC;

ProductFactory::ProductFactory(){}

ProductFactory::~ProductFactory() {}

ProductFactory* ProductFactory::create() {

    ProductFactory* pRet = new ProductFactory();
    if (!pRet->init()) {
        delete pRet;
        pRet = nullptr;
    }
    return pRet;
}

bool ProductFactory::init()
{
   return true;
}



