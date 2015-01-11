
#include "ShopCookiesLayer.h"
USING_NS_CC;

bool ShopCookiesLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto *label1 = Label::createWithTTF("COOKIES", "Santa's Air Mail.ttf", 24);
    // label1->setPosition(Point(.x, origin.y + visibleSize.height - label1->getContentSize().height));
    label1->setAnchorPoint(Point(0.0f, 0.0f));
    this->addChild(label1);
    
    return true;
}