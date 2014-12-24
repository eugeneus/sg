

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
    
    _popupBg = createPopupBg();
    if (_popupBg && _popupBg != nullptr)
        this->addChild(_popupBg, 2000);
    
    _contentBg = createContentBg();
    if (_contentBg && _contentBg != nullptr) {
        this->addChild(_contentBg, 2001);
        
        _btnsHolder = Menu::create();
        _contentBg->addChild(_btnsHolder);
    }
    
    return true;
}

void PopupRenderer::addButton(const std::string btnFN, const std::string btnSelFN, const cocos2d::ccMenuCallback &callback, cocos2d::Vec2 pos) {
    
    MenuItem *item = MenuItemSprite::create(Sprite::createWithSpriteFrameName(btnFN), Sprite::createWithSpriteFrameName(btnSelFN), callback);
    item->setPosition(pos);
    //_btns->pushBack(item);
    _btnsHolder->addChild(item);
}

cocos2d::Sprite *PopupRenderer::getContentBg() {
    return _contentBg;
}

PopupCallback *PopupRenderer::getCallback() {
    return _callback;
}

void PopupRenderer::setCallback(PopupCallback *callback) {
    _callback = callback;
}
