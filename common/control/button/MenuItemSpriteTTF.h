
#ifndef __SantaGnomes__MenuItemSpriteTTF__
#define __SantaGnomes__MenuItemSpriteTTF__

#include "cocos2d.h"

class MenuItemSpriteTTF : public cocos2d::MenuItemSprite {
public:
    static MenuItemSpriteTTF *create(std::string title, std::string ttfFontFileNm, float fontSize, cocos2d::Node* normalSprite, cocos2d::Node* selectedSprite, const cocos2d::ccMenuCallback& callback);
protected:
    bool init(std::string title, std::string ttfFontFileNm, float fontSize, cocos2d::Node* normalSprite, cocos2d::Node* selectedSprite, const cocos2d::ccMenuCallback& callback);
    
    MenuItemSpriteTTF();
    ~MenuItemSpriteTTF();
};

#endif /* defined(__SantaGnomes__MenuItemSpriteTTF__) */
