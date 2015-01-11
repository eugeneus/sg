
#include "MenuItemSpriteTTF.h"
USING_NS_CC;

MenuItemSpriteTTF::MenuItemSpriteTTF() {}
MenuItemSpriteTTF::~MenuItemSpriteTTF() {}

MenuItemSpriteTTF *MenuItemSpriteTTF::create(std::string title, std::string ttfFontFileNm, float fontSize, cocos2d::Node *normalSprite, cocos2d::Node *selectedSprite, const cocos2d::ccMenuCallback &callback, const cocos2d::Color4B& outlineColor, float outlineSize) {
    MenuItemSpriteTTF* pRet = new MenuItemSpriteTTF();
    
    if (!pRet->init(title, ttfFontFileNm, fontSize, normalSprite, selectedSprite, callback, outlineColor, outlineSize))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

bool MenuItemSpriteTTF::init(std::string title, std::string ttfFontFileNm, float fontSize, cocos2d::Node *normalSprite, cocos2d::Node *selectedSprite, const cocos2d::ccMenuCallback &callback, const cocos2d::Color4B& outlineColor, float outlineSize) {
    
    if (!MenuItemSprite::initWithNormalSprite(normalSprite, selectedSprite, NULL, callback)) {
        return false;
    }
    
    TTFConfig ttfConfigDescr;
    ttfConfigDescr.fontSize = fontSize;
    ttfConfigDescr.fontFilePath = ttfFontFileNm;
    ttfConfigDescr.outlineSize = outlineSize;
    
    cocos2d::Label *label = cocos2d::Label::createWithTTF(ttfConfigDescr, title);
    label->enableOutline(outlineColor);
    label->setPosition(cocos2d::Vec2(this->getContentSize().width/2, this->getContentSize().height/2));
    this->addChild(label);
    
    return true;
}