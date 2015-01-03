
#include "SlidePanel.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

SlidePanel::SlidePanel(){}

SlidePanel::~SlidePanel() {}

SlidePanel* SlidePanel::create(SlidePanelItemsController *controller, SlidePanelConfig *config) {
    
    SlidePanel* pRet = new SlidePanel();
    
    if (!pRet->init(controller, config))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

bool SlidePanel::init(SlidePanelItemsController *controller, SlidePanelConfig *config) {
    
    if (!Layer::init()) {
        
        return false;
    }
    
    _controller = controller;
    _config = config;
    _isOpened = false;
    
    Size winSize = Director::getInstance()->getWinSize();
    float xPos = _config->isLeft() ? winSize.width : 0 ;
    
    
    _btnNormal = Sprite::createWithSpriteFrameName(CCString::createWithFormat(_config->getButtonMaskNormal().c_str(), 1)->getCString());
    
    xPos += (_config->isLeft() ? -1 : 1) * _btnNormal->getContentSize().width;
    
    this->setPosition(Vec2(xPos, _config->getYPos()));
    this->setContentSize(Size(_config->getPanelWidth() + _btnNormal->getContentSize().width, _btnNormal->getContentSize().height));
    _btn = MenuItemSprite::create(_btnNormal, nullptr, CC_CALLBACK_0(SlidePanel::toggle, this));
    _btn->setPosition(Vec2(xPos + 80, _config->getYPos())); //TODO : % of content size
   
    Menu *btnMenu = Menu::create(_btn, NULL);
    this->addChild(btnMenu);
    
    this->drawItems();
    
    this->waitActions();
    
    return true;
}

cocos2d::Animation *SlidePanel::createFrameAnimation(const std::string frameMask, int frameCount, float delay) {
    
    Animation *animation = Animation::create();
    animation->setDelayPerUnit(delay);
    
    for (int i=1; i <= frameCount; i++) {
        std::string frameName = CCString::createWithFormat(frameMask.c_str(), i)->getCString();
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
        animation->addSpriteFrame(frame);
    }
    
    return animation;
}

void SlidePanel::waitActions() {
    _btnNormal->stopAllActions();
    _btn->setEnabled(true);
    
    Animation *animation = this->createFrameAnimation(_config->getButtonMaskWait(), _config->getButtonFrameCountWait(), 1.0f);
    _btnNormal->runAction(RepeatForever::create(Animate::create(animation)));
}

void SlidePanel::toggleShowHide(float toXPos, const std::string toggleAnimFrameMask, int framesCount) {
    
    Animation *animation = createFrameAnimation(toggleAnimFrameMask, framesCount, 1.0f);
    
    Vec2 toPos = Vec2(toXPos, this->getPosition().y);
    Sequence *pulseSequence = Sequence::create(MoveTo::create(1.0, toPos), CallFunc::create(CC_CALLBACK_0(SlidePanel::waitActions, this)), nullptr);
    
    _btnNormal->runAction(RepeatForever::create(Animate::create(animation)));
    _btn->runAction(pulseSequence);
}

void SlidePanel::toggle() {
    _btnNormal->stopAllActions();
    _btn->setEnabled(false);
    
    float xPos = 0;
    std::string frameMask = "";
    int framesCount = 0;
    
    if (!_isOpened) {
        xPos = this->getPosition().x - (_config->isLeft() ? (- _config->getPanelWidth()) : _config->getPanelWidth());
        frameMask = _config->getButtonMaskShow();
        framesCount = _config->getButtonFrameCountShow();
    } else {
        xPos = (_config->isLeft() ? -1 : 1) * _btnNormal->getContentSize().width + 80; //TODO:
        frameMask = _config->getButtonMaskHide();
        framesCount = _config->getButtonFrameCountHide();
    }
    
    this->toggleShowHide(xPos, frameMask, framesCount);
    _isOpened = !_isOpened;
}

void SlidePanel::drawItems() {
    ScrollView *scrollView = ScrollView::create();
    scrollView->setDirection(ScrollView::Direction::HORIZONTAL);
    scrollView->setTouchEnabled(true);
    scrollView->setBounceable(true);
    scrollView->setViewSize(Size(_config->getPanelWidth(), _btnNormal->getContentSize().height));
    scrollView->setPosition(Vec2(scrollView->getPosition().x + (_config->isLeft() ? - _btnNormal->getContentSize().width : _btnNormal->getContentSize().width), _btnNormal->getPosition().y));

    _btn->addChild(scrollView);
    
    Menu *menu = Menu::create();
    menu->setPosition(Vec2(0,0));
    scrollView->addChild(menu);
    
    
    for (int i=1; i <= _controller->getItemsCount(); i++) {
        Node *item = _controller->getItemAtIndex(i - 1);
        item->setPosition(Vec2(item->getPosition().x + (i - 1) * item->getContentSize().width + item->getContentSize().width/2, item->getPosition().y + item->getContentSize().height/2)); //TODO: is left
        menu->addChild(item);
    }
    
    scrollView->setContentSize(Size(menu->getContentSize().width, _btnNormal->getContentSize().height));
}


