
#ifndef __SantaGnomes__PopupRenderer__
#define __SantaGnomes__PopupRenderer__

class PopupRenderer : public cocos2d::Layer {
    
public:
    void addButton(const std::string btnFN, const std::string btnSelFN, const cocos2d::ccMenuCallback &callback, cocos2d::Vec2 pos);
    void addButton(cocos2d::MenuItem *item, const cocos2d::ccMenuCallback &callback, cocos2d::Vec2 pos);
    cocos2d::Sprite *getContentBg();
    
    virtual void initButtons(cocos2d::Layer *pTarget) = 0;
protected:
    virtual bool init();
    PopupRenderer();
    ~PopupRenderer();
    
    virtual cocos2d::Sprite* createPopupBg() = 0;
    virtual cocos2d::Sprite* createContentBg() = 0;
    cocos2d::Sprite *_contentBg;
private:
    cocos2d::Sprite *_popupBg;
    
    cocos2d::Vector<cocos2d::MenuItem *> *_btns;
    cocos2d::Menu *_btnsHolder;
};

#endif /* defined(__SantaGnomes__PopupRenderer__) */
