
#ifndef __SantaGnomes__ShopTabPanelConfig__
#define __SantaGnomes__ShopTabPanelConfig__

#include "TabPanelConfig.h"
#include "ShopPopupCallback.h"
#include "ShopTabPanelPage.h"

class ShopTabPanelConfig : public TabPanelConfig {
public:
    static ShopTabPanelConfig *create(ShopPopupCallback *callback, ShopTabPanelPage *page);
    
    virtual void changeBtnState(cocos2d::MenuItem *tabBtn, bool isVisible);
    virtual void initTabItems();
    virtual cocos2d::Vec2 getTabsStartPos();
    virtual cocos2d::Vec2 getTabsLayerPos();
protected:
    bool init(ShopPopupCallback *callback, ShopTabPanelPage *page);
    ShopTabPanelConfig();
    ~ShopTabPanelConfig();
    
    ShopPopupCallback *_callback;
    ShopTabPanelPage *_pageInfo;
};

#endif /* defined(__SantaGnomes__ShopTabPanelConfig__) */
