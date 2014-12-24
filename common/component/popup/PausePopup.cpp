#include "PausePopup.h"
#include "GameScene.h"

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
    this->addButton("btn_resume.png", "btn_resume_sel.png", CC_CALLBACK_1(PausePopup::onResumeClicked, this), Vec2(-175, 110));
    this->addButton("btn_replay.png", "btn_replay_sel.png", CC_CALLBACK_1(PausePopup::onReplayClicked, this), Vec2(-340, -40));
    this->addButton("btn_sound.png", "btn_sound_sel.png", CC_CALLBACK_1(PausePopup::onSoundClicked, this), Vec2(-10, -40));
    this->addButton("btn_main_menu.png", "btn_main_menu_sel.png", CC_CALLBACK_1(PausePopup::onMainMenuClicked, this), Vec2(-175, -190));
}

cocos2d::Sprite* PausePopup::createPopupBg() {
    return Sprite::createWithSpriteFrameName("popup_bg.png");
}

cocos2d::Sprite* PausePopup::createContentBg() {
    return Sprite::createWithSpriteFrameName("pause_bg.png");
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