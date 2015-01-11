
#include "TabPanelConfig.h"

bool TabPanelConfig::init() {
    
    this->initTabItems();
    
    return true;
}

int TabPanelConfig::getTabsCount() {
    return _tabItems.size();
}

TabPanelItem *TabPanelConfig::getTabItem(int index) {
    if (index < _tabItems.size()) {
        return _tabItems.at(index);
    }
    
    return nullptr;
}

void TabPanelConfig::createTabItem(cocos2d::MenuItem *tabBtn, cocos2d::Layer *layer) {
    TabPanelItem *item = TabPanelItem::create(tabBtn, layer);
    _tabItems.push_back(item);
}