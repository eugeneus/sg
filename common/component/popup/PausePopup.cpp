#include "PausePopup.h"
#include "GameScene.h"
#include "UIConstants.h"

USING_NS_CC;

PausePopup::PausePopup(){}

PausePopup::~PausePopup() {}

PausePopup* PausePopup::create(PausePopupCallback *callback) {
    
    PausePopup* pRet = new PausePopup();
    
    if (!pRet->init(callback))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
    
}

bool PausePopup::init(PausePopupCallback *callback) {

    
    if (!PopupRenderer::init()) {
        
        return false;
    }
    
    _callback = callback;
    
    return true;
}

void PausePopup::initButtons(cocos2d::Layer *pTarget) {
    this->addButton(PAUSE_RESUME_BTN, PAUSE_RESUME_BTN_SEL, CC_CALLBACK_1(PausePopup::onResumeClicked, this), Vec2(-175, 110));
    this->addButton(PAUSE_REPLAY_BTN, PAUSE_REPLAY_BTN_SEL, CC_CALLBACK_1(PausePopup::onReplayClicked, this), Vec2(-340, -40));
    this->addButton(PAUSE_SOUND_BTN, PAUSE_SOUND_BTN_SEL, CC_CALLBACK_1(PausePopup::onSoundClicked, this), Vec2(-10, -40));
    this->addButton(PAUSE_MENU_BTN, PAUSE_MENU_BTN_SEL, CC_CALLBACK_1(PausePopup::onMainMenuClicked, this), Vec2(-175, -190));
}

cocos2d::Sprite* PausePopup::createPopupBg() {
    return POPUP_BG;
}

cocos2d::Sprite* PausePopup::createContentBg() {
    return Sprite::createWithSpriteFrameName(POPUP_PAUSE_BG);
}

void PausePopup::onResumeClicked(cocos2d::Ref *pSender) {
    _callback->pauseCallbackResume();
}

void PausePopup::onReplayClicked(cocos2d::Ref *pSender) {
    _callback->pauseCallbackReplay();
}

void PausePopup::onSoundClicked(cocos2d::Ref *pSender) {
    _callback->pauseCallbackSound(true);
}

void PausePopup::onMainMenuClicked(cocos2d::Ref *pSender) {
    _callback->pauseCallbackMainMenu();
}