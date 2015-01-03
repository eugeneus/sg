
#include "ShopTabPanelConfig.h"
#include "ShopBonusLayer.h"
#include "ShopCookiesLayer.h"
#include "ShopMoneyLayer.h"

USING_NS_CC;

ShopTabPanelConfig::ShopTabPanelConfig() {}
ShopTabPanelConfig::~ShopTabPanelConfig() {}

ShopTabPanelConfig *ShopTabPanelConfig::create(ShopPopupCallback *callback, ShopTabPanelPage *page) {
    ShopTabPanelConfig* pRet = new ShopTabPanelConfig();
    
    if (!pRet->init(callback, page))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;

}

bool ShopTabPanelConfig::init(ShopPopupCallback *callback, ShopTabPanelPage *page) {
    _callback = callback;
    _pageInfo = page;
    
    if (!TabPanelConfig::init()) {
        return false;
    }
    
    return true;
}

void ShopTabPanelConfig::changeBtnState(cocos2d::MenuItem *tabBtn, bool isVisible) {
    MenuItemSprite *menuItemSprite = (MenuItemSprite *) tabBtn;
    Sprite *normalImage = (Sprite *) menuItemSprite->getNormalImage();
    Sprite *selectedImage = (Sprite *) menuItemSprite->getSelectedImage();
    
    SpriteFrame *normalSpriteFrame = normalImage->getSpriteFrame();
    SpriteFrame *selectedSpriteFrame = selectedImage->getSpriteFrame();
    
    normalImage->setSpriteFrame(selectedSpriteFrame);
    selectedImage->setSpriteFrame(normalSpriteFrame);
}

void ShopTabPanelConfig::initTabItems() {
    MenuItem *tabBtn1 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("shop_tab_btn_1.png"), Sprite::createWithSpriteFrameName("shop_tab_btn_1_sel.png"));
    this->createTabItem(tabBtn1, ShopMoneyLayer::create());
    
    MenuItem *tabBtn2 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("shop_tab_btn_2.png"), Sprite::createWithSpriteFrameName("shop_tab_btn_2_sel.png"));
    this->createTabItem(tabBtn2, ShopCookiesLayer::create());
    
    MenuItem *tabBtn3 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("shop_tab_btn_3.png"), Sprite::createWithSpriteFrameName("shop_tab_btn_3_sel.png"));
    this->createTabItem(tabBtn3, ShopBonusLayer::create(_pageInfo->getPageItem(), _callback));
}

Vec2 ShopTabPanelConfig::getTabsStartPos() {
    return Vec2(220, 500); //TODO:
}

Vec2 ShopTabPanelConfig::getTabsLayerPos() {
    return Vec2(50, 00); //TODO:
}
