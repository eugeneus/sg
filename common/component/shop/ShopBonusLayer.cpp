
#include "ShopBonusLayer.h"
#include "MenuItemSpriteTTF.h"
#include "ShopBonusSelector.h"

USING_NS_CC;

ShopBonusLayer* ShopBonusLayer::create(int selected, ShopPopupCallback *callback) {
    
    ShopBonusLayer* pRet = new ShopBonusLayer();
    
    if (!pRet->init(selected, callback))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
    
}

bool ShopBonusLayer::init(int selected, ShopPopupCallback *callback)
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    _callback = callback;

    auto *label1 = Label::createWithTTF("BONUS", "Santa's Air Mail.ttf", 24);
    label1->setAnchorPoint(Point(0.0f, 0.0f));
    this->addChild(label1);
    
    Size winSize = Director::getInstance()->getWinSize();
    
    //TODO: create separated components
    Sprite *bg = Sprite::createWithSpriteFrameName("bonus_bg.png");
    bg->setPosition(Vec2(winSize.width/2 - 50, winSize.height/2 - 30));
    this->addChild(bg);
    
   // MenuItemSprite *cancel =
    
    MenuItemSprite *cancel = MenuItemSpriteTTF::create("CANCEL", "Santa's Air Mail.ttf", 24, Sprite::createWithSpriteFrameName("shop_btn.png"), Sprite::createWithSpriteFrameName("shop_btn_sel.png"), CC_CALLBACK_1(ShopBonusLayer::onCancelClicked, this));
    cancel->setAnchorPoint(Vec2(0, 0));
    cancel->setPosition(Vec2(winSize.width/2 + 100, 40));
    
    MenuItemSprite *buy = MenuItemSpriteTTF::create("BUY", "Santa's Air Mail.ttf", 24, Sprite::createWithSpriteFrameName("shop_btn.png"), Sprite::createWithSpriteFrameName("shop_btn_sel.png"), CC_CALLBACK_1(ShopBonusLayer::onBuyClicked, this));
    buy->setAnchorPoint(Vec2(1, 0));
    buy->setPosition(Vec2(winSize.width/2 - 100, 40));
    
    Menu *menu = Menu::create(buy, cancel, NULL);
    menu->setAnchorPoint(Vec2(0, 0));
    menu->setPosition(Vec2(0, 0));
    this->addChild(menu);
    
    _bonusThumb = Sprite::create();
    _bonusThumb->setPosition(Vec2(100, 400));
    this->addChild(_bonusThumb);
    
    TTFConfig ttfConfigName;
    ttfConfigName.fontSize = 24;
    ttfConfigName.fontFilePath = "Santa's Air Mail.ttf";
    
    TTFConfig ttfConfigDescr;
    ttfConfigDescr.fontSize = 16;
    ttfConfigDescr.fontFilePath = "Santa's Air Mail.ttf";
    
    const Color3B &colorYellow = Color3B(255, 240, 104);
    const Color3B &colorBlack = Color3B(0, 0, 0);
    
    _bonusName = Label::createWithTTF(ttfConfigName, "");
    _bonusName->setColor(colorYellow);
    _bonusName->setPosition(Vec2(400, 400));
    _bonusName->setAnchorPoint(Vec2(0, 0));
    this->addChild(_bonusName);
    
    _bonusDescr = Label::createWithTTF(ttfConfigDescr, "");
    _bonusDescr->setColor(colorBlack);
    _bonusDescr->setPosition(Vec2(400, 350));
    _bonusDescr->setAnchorPoint(Vec2(0, 0));
    this->addChild(_bonusDescr);
    
    this->onBonusSelected(selected);
    
    ShopBonusSelector *selector = ShopBonusSelector::create(this, 1);
    selector->setPosition(Vec2(100, 150));
    this->addChild(selector);
    
    return true;
}

void ShopBonusLayer::onCancelClicked(Ref *pSender) {
    _callback->shopCallbackCancel();
}

void ShopBonusLayer::onBuyClicked(Ref *pSender) {
    //_callback->shopCallbackCancel();
}

void ShopBonusLayer::onBonusSelected(int bonusType) {
    SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(CCString::createWithFormat("bonus_item_%i.png", bonusType)->getCString());
    _bonusThumb->setSpriteFrame(spriteFrame);
    
    _bonusName->setString(CCString::createWithFormat("BONUS %i", bonusType)->getCString());
    _bonusDescr->setString(CCString::createWithFormat("BONUS DESCRIPTION %i", bonusType)->getCString());
}