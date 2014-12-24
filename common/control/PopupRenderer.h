
#ifndef __SantaGnomes__PopupRenderer__
#define __SantaGnomes__PopupRenderer__

#include "PopupCallback.h"

class PopupRenderer : public cocos2d::Layer {
    
public:
    void addButton(const std::string btnFN, const std::string btnSelFN, const cocos2d::ccMenuCallback &callback, cocos2d::Vec2 pos);
    
    cocos2d::Sprite *getContentBg();
    void setCallback(PopupCallback *callback);
    
    virtual void initButtons(cocos2d::Layer *pTarget, PopupCallback *callback) = 0;
protected:
    virtual bool init();
    PopupRenderer();
    ~PopupRenderer();
    
    virtual cocos2d::Sprite* createPopupBg() = 0;
    virtual cocos2d::Sprite* createContentBg() = 0;
    
    PopupCallback *getCallback();
    
private:
    cocos2d::Sprite *_popupBg;
    cocos2d::Sprite *_contentBg;
    cocos2d::Vector<cocos2d::MenuItem *> *_btns;
    cocos2d::Menu *_btnsHolder;
    PopupCallback *_callback;
};

#endif /* defined(__SantaGnomes__PopupRenderer__) */
