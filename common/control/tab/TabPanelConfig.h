
#ifndef __SantaGnomes__TabPanelConfig__
#define __SantaGnomes__TabPanelConfig__

#include "TabPanelItem.h"

class TabPanelConfig {
public:
    virtual void changeBtnState(cocos2d::MenuItem *tabBtn, bool isVisible) = 0;
    virtual void initTabItems() = 0;
    virtual cocos2d::Vec2 getTabsStartPos() = 0;
    virtual cocos2d::Vec2 getTabsLayerPos() = 0;
    int getTabsCount();
    
    TabPanelItem *getTabItem(int index);
    
    void createTabItem(cocos2d::MenuItem *tabBtn, cocos2d::Layer *layer);
protected:
    bool init();
    
private:
    std::vector<TabPanelItem *> _tabItems;
};

#endif /* defined(__SantaGnomes__TabPanelConfig__) */
