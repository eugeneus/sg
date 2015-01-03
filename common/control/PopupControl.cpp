
#include "PopupControl.h"

USING_NS_CC;

PopupControl::PopupControl(){}

PopupControl::~PopupControl() {}

PopupControl* PopupControl::create() {
    
    PopupControl* pRet = new PopupControl();
    
    if (!pRet->init())
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
    
}

bool PopupControl::init() {
    
    return true;
}

void PopupControl::showPopup(PopupRenderer *pRenderer, cocos2d::Layer *pTarget) {
    _renderer = pRenderer;
    _target = pTarget;
    
    _target->addChild(_renderer, 1000);
    
    Sprite *contentBg = _renderer->getContentBg();
    if (contentBg && contentBg != nullptr) {
        Vec2 targetPoint = contentBg->getPosition();
        contentBg->setPosition(Vec2(targetPoint.x, targetPoint.y + 5000));
        
     //   _renderer->setCallback(callback);
        _renderer->initButtons(_target);
        
        contentBg->runAction(Sequence::create(MoveTo::create(0.3, targetPoint), JumpTo::create(0.50, targetPoint, -120, 5), NULL));
    }
}

void PopupControl::hidePopup() {
    if (_renderer && _renderer != nullptr) {
        Sprite *contentBg = _renderer->getContentBg();
        if (contentBg && contentBg != nullptr) {
            Vec2 targetPoint = contentBg->getPosition();
        
            contentBg->runAction(
                                 Sequence::create(
                                                  JumpTo::create(0.50, targetPoint, -120, 5),
                                                  MoveTo::create(0.3, Vec2(targetPoint.x, targetPoint.y + 5000)),
                                                  CallFunc::create(CC_CALLBACK_0(PopupControl::removePopup, this)),
                                                  NULL));
            //_renderer->removeFromParentAndCleanup(true);
        } else {
            _renderer->removeFromParentAndCleanup(true);
        }
    }
}

void PopupControl::removePopup() {
    _renderer->removeFromParentAndCleanup(true);
}
