
#include "Product.h"

USING_NS_CC;

Product::Product(){}

Product::~Product() {}

Product* Product::create(const std::string aFileName, cocos2d::Point aRelativePos, float aRelativeSizeFactor) {

    Product* pRet = new Product();
    if (!pRet->init(aFileName,aRelativePos,aRelativeSizeFactor)) {
        delete pRet;
        pRet = nullptr;
    }
    return pRet;
}

//bool Product::init()
//{
//   return true;
//}

void Product::setTypeID(int aTypeID)
{
    _typeID = aTypeID;
}

int Product::getTypeID()
{
    return _typeID;
}



