
#include "ShopMoneyLayer.h"
USING_NS_CC;

bool ShopMoneyLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto *label1 = Label::createWithTTF("MONEY", "Marker Felt.ttf", 24);
    // label1->setPosition(Point(.x, origin.y + visibleSize.height - label1->getContentSize().height));
    label1->setAnchorPoint(Point(0.0f, 0.0f));
    this->addChild(label1);
    
    return true;
}

