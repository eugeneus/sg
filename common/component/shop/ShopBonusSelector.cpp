
#include "ShopBonusSelector.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

ShopBonusSelector *ShopBonusSelector::create(ShopBonusSelectorCallback *callback, int bonusType) {
    ShopBonusSelector* pRet = new ShopBonusSelector();
    
    if (!pRet->init(callback, bonusType))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

bool ShopBonusSelector::init(ShopBonusSelectorCallback *callback, int bonusType) {
    _callback = callback;
    
    if (!Layer::init()) {
        return false;
    }
    
    ScrollView *scrollView = ScrollView::create();
    scrollView->setDirection(ScrollView::Direction::HORIZONTAL);
    scrollView->setTouchEnabled(true);
    scrollView->setBounceable(true);
    scrollView->setContentSize(Size(600, 100));
    scrollView->setViewSize(Size(600, 100));
    scrollView->setPosition(Vec2(0, 0));
    scrollView->setAnchorPoint(Vec2(0, 0));
    this->addChild(scrollView);
    
    Menu *menu = Menu::create();
    menu->setPosition(Vec2(0,0));
    scrollView->addChild(menu);
    
    //TODO: bonus load
    for (int i=1; i <= 4; i++) {
        const char *frameName = CCString::createWithFormat("bonus_item_%i.png", i)->getCString();
        MenuItem *item = MenuItemSprite::create(Sprite::createWithSpriteFrameName(frameName), Sprite::createWithSpriteFrameName(frameName));
        item->setTag(i);
        item->setCallback(CC_CALLBACK_1(ShopBonusSelector::onItemSelected,this));
        item->setPosition(Vec2(item->getPosition().x + (i - 1) * item->getContentSize().width + item->getContentSize().width/2, item->getPosition().y + item->getContentSize().height/2));
        menu->addChild(item);
    }
    
    return true;
}

void ShopBonusSelector::onItemSelected(Ref *pSender) {
    MenuItem *item = (MenuItem *) pSender;
    int tag = item->getTag();
    
    _callback->onBonusSelected(tag);
}