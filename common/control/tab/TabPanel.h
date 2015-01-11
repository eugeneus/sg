
#ifndef __SantaGnomes__TabPanel__
#define __SantaGnomes__TabPanel__

#include "TabPanelConfig.h"
#include "TabPanelItem.h"

class TabPanel : public cocos2d::Layer {
public:
    static TabPanel *create(TabPanelConfig *config);
    
    void addTab(cocos2d::MenuItem* tabBtn, cocos2d::Layer *tabLayer, cocos2d::Vec2 tabPos, cocos2d::Vec2 tabLayerPos);
    void onTabClicked(cocos2d::Ref *pSender);
    
    void openTabByTag(int tag);
protected:
    bool init(TabPanelConfig *config);
    TabPanel();
    ~TabPanel();
    
    void resetTab(int tag, bool isVisible);
private:
    TabPanelConfig *_config;
    cocos2d::Menu *_tabsBtnHolder;
    cocos2d::Node *_tabsLayerHolder;
    int _currentTab;
};

#endif /* defined(__SantaGnomes__TabPanel__) */
