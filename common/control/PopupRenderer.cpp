

#include "PopupRenderer.h"

USING_NS_CC;

PopupRenderer::PopupRenderer(){}

PopupRenderer::~PopupRenderer() {}

bool PopupRenderer::init() {
    
    if (!Layer::init()) {
        
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    this->setPosition(Vec2(winSize.width/2, winSize.height/2));
    
    Menu *popupBgMenu = Menu::create();
    popupBgMenu->setAnchorPoint(Vec2(0, 0));
    popupBgMenu->setPosition(Vec2(0, 0));
    this->addChild(popupBgMenu, 2000);
    
    _popupBg = createPopupBg();
    if (_popupBg && _popupBg != nullptr) {
        MenuItem *popupBgBtn = MenuItemSprite::create(_popupBg, NULL);
        popupBgMenu->addChild(popupBgBtn);
    }
    
    _contentBg = createContentBg();
    if (_contentBg && _contentBg != nullptr) {
        this->addChild(_contentBg, 2001);
        
        _btnsHolder = Menu::create();
        _contentBg->addChild(_btnsHolder);
    }
    
    return true;
}

void PopupRenderer::addButton(const std::string btnFN, const std::string btnSelFN, const cocos2d::ccMenuCallback &callback, cocos2d::Vec2 pos) {
    
    MenuItem *item = MenuItemSprite::create(Sprite::createWithSpriteFrameName(btnFN), Sprite::createWithSpriteFrameName(btnSelFN));
    this->addButton(item, callback, pos);
}

void PopupRenderer::addButton(MenuItem *item, const cocos2d::ccMenuCallback &callback, cocos2d::Vec2 pos) {
    
    item->setCallback(callback);
    item->setPosition(pos);

    _btnsHolder->addChild(item);
}

cocos2d::Sprite *PopupRenderer::getContentBg() {
    return _contentBg;
}