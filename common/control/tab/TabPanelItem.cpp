
#include "TabPanelItem.h"

TabPanelItem::TabPanelItem() {}
TabPanelItem::~TabPanelItem() {}

TabPanelItem *TabPanelItem::create(cocos2d::MenuItem *tabBtn, cocos2d::Layer *layer) {
    TabPanelItem* pRet = new TabPanelItem();
    
    if (!pRet->init(tabBtn, layer))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

bool TabPanelItem::init(cocos2d::MenuItem *tabBtn, cocos2d::Layer *layer) {
    
    _tabBtn = tabBtn;
    _tabLayer = layer;
    
    return true;
}

cocos2d::MenuItem *TabPanelItem::getTabBtn() {
    return _tabBtn;
}

cocos2d::Layer *TabPanelItem::getTabLayer() {
    return _tabLayer;
}