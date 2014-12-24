
#include "ShopPopup.h"

USING_NS_CC;

ShopPopup::ShopPopup(){}

ShopPopup::~ShopPopup() {}

ShopPopup* ShopPopup::create() {
    
    ShopPopup* pRet = new ShopPopup();
    
    if (!pRet->init())
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
    
}

bool ShopPopup::init() {
    
    if (!PopupRenderer::init()) {
        
        return false;
    }
    
    return true;
}

void ShopPopup::initButtons(cocos2d::Layer *pTarget) {
    this->addButton("btn_resume.png", "btn_resume_sel.png", CC_CALLBACK_1(ShopPopup::onResumeGame, this), Vec2(-175, 110));
    this->addButton("btn_replay.png", "btn_replay_sel.png", CC_CALLBACK_1(ShopPopup::onPaymentComplete, this), Vec2(-340, -40));
}

cocos2d::Sprite* ShopPopup::createPopupBg() {
    return Sprite::createWithSpriteFrameName("popup_bg.png");
}

cocos2d::Sprite* ShopPopup::createContentBg() {
    return Sprite::createWithSpriteFrameName("pause_bg.png");
}

void ShopPopup::onPaymentComplete(cocos2d::Ref *pSender) {
    //ShopPopupCallback *callback = (ShopPopupCallback *) getCallback();
    //callback->shopCallbackPaymentComplete();
}

void ShopPopup::onResumeGame(cocos2d::Ref *pSender) {
    //ShopPopupCallback *callback = (ShopPopupCallback *) getCallback();
    //callback->shopCallbackResume();
}