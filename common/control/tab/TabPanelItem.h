#ifndef __SantaGnomes__TabPanelItem__
#define __SantaGnomes__TabPanelItem__

class TabPanelItem {
public:
    static TabPanelItem *create(cocos2d::MenuItem *tabBtn, cocos2d::Layer *layer);
    
    cocos2d::MenuItem *getTabBtn();
    cocos2d::Layer *getTabLayer();
protected:
    bool init(cocos2d::MenuItem *tabBtn, cocos2d::Layer *layer);
    TabPanelItem();
    ~TabPanelItem();
private:
    cocos2d::Layer *_tabLayer;
    cocos2d::MenuItem *_tabBtn;
};

#endif /* defined(__SantaGnomes__TabPanelItem__) */
