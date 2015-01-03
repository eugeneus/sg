
#include "ShopPopup.h"
#include "TabPanel.h"
#include "ShopTabPanelConfig.h"
#include "ShopTabPanelPage.h"

USING_NS_CC;

ShopPopup::ShopPopup(){}

ShopPopup::~ShopPopup() {}

ShopPopup* ShopPopup::create(int pageType, int bonusType, ShopPopupCallback *callback) {
    
    ShopPopup* pRet = new ShopPopup();
    
    if (!pRet->init(pageType, bonusType, callback))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
    
}

bool ShopPopup::init(int pageType, int bonusType, ShopPopupCallback *callback) {
    
    if (!PopupRenderer::init()) {
        
        return false;
    }
    
    _pageType = pageType;
    _bonusType = bonusType;
    _callback = callback;
    
    return true;
}

void ShopPopup::initButtons(cocos2d::Layer *pTarget) {
    
    TabPanel *tabs = TabPanel::create(ShopTabPanelConfig::create(_callback, ShopTabPanelPage::create(_pageType, _bonusType)));
    tabs->openTabByTag(_pageType); //TODO: _pageType
    _contentBg->addChild(tabs, 100);
    
    TTFConfig ttfConfig32;
    ttfConfig32.fontSize = 24;
    ttfConfig32.fontFilePath = "Santa's Air Mail.ttf";
    
    const cocos2d::Color3B& colorWhite = Color3B(255, 255, 255);
    const cocos2d::Color3B& colorYellow = Color3B(255, 240, 104);
    
    Size winSize = Director::getInstance()->getWinSize();
    
    float height = winSize.height - 0;
    
    Label *moneyLabel = Label::createWithTTF(ttfConfig32, "MONEY:");
    moneyLabel->setColor(colorYellow);
    moneyLabel->setAnchorPoint(Vec2(0, 1));
    moneyLabel->setPosition(Vec2(winSize.width/2 - 400, height));
    _contentBg->addChild(moneyLabel, 1001);
    
    Label *moneyText = Label::createWithTTF(ttfConfig32, "10300");
    moneyText->setColor(colorWhite);
    moneyText->setAnchorPoint(Vec2(0, 1));
    moneyText->setPosition(Vec2(moneyLabel->getPosition().x + moneyLabel->getContentSize().width + 10, height));
    _contentBg->addChild(moneyText, 1001);
    
    Label *cookiesText = Label::createWithTTF(ttfConfig32, "12");
    cookiesText->setColor(colorWhite);
    cookiesText->setAnchorPoint(Vec2(1, 1));
    cookiesText->setPosition(Vec2(winSize.width/2 + 400, height));
    _contentBg->addChild(cookiesText, 1001);
    
    Label *cookiesLabel = Label::createWithTTF(ttfConfig32, "COOKIES:");
    cookiesLabel->setColor(colorYellow);
    cookiesLabel->setAnchorPoint(Vec2(1, 1));
    cookiesLabel->setPosition(Vec2(cookiesText->getPosition().x - cookiesText->getContentSize().width - 10, height));
    _contentBg->addChild(cookiesLabel, 1001);
}

cocos2d::Sprite* ShopPopup::createPopupBg() {
    return Sprite::createWithSpriteFrameName("popup_bg.png");
}

cocos2d::Sprite* ShopPopup::createContentBg() {
    return Sprite::createWithSpriteFrameName("shop_bg.png");
}

void ShopPopup::onPaymentComplete(cocos2d::Ref *pSender) {
    //ShopPopupCallback *callback = (ShopPopupCallback *) getCallback();
    //callback->shopCallbackPaymentComplete();
}

void ShopPopup::onResumeGame(cocos2d::Ref *pSender) {
    //ShopPopupCallback *callback = (ShopPopupCallback *) getCallback();
    //callback->shopCallbackResume();
}