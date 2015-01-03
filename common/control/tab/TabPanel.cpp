
#include "TabPanel.h"

USING_NS_CC;

TabPanel::TabPanel(){}

TabPanel::~TabPanel() {}

TabPanel* TabPanel::create(TabPanelConfig *config) {
    
    TabPanel* pRet = new TabPanel();
    
    if (!pRet->init(config))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

bool TabPanel::init(TabPanelConfig *config) {
    
    if (!Layer::init()) {
        
        return false;
    }
    
    _config = config;

    _tabsBtnHolder = Menu::create();
    _tabsBtnHolder->setPosition(Vec2(0, 0));
    _tabsBtnHolder->setAnchorPoint(Vec2(0, 0));
    this->addChild(_tabsBtnHolder);
    
    _tabsLayerHolder = Node::create();
    _tabsLayerHolder->setPosition(Vec2(0, 0));
    _tabsLayerHolder->setAnchorPoint(Vec2(0, 0));
    this->addChild(_tabsLayerHolder);
    
    Vec2 startPos = _config->getTabsStartPos();
    float xBtnPos = startPos.x;
    
    for (int i=0; i < _config->getTabsCount(); i++) {
        TabPanelItem *item = _config->getTabItem(i);
        Vec2 btnPos = Vec2(xBtnPos, startPos.y);
        Vec2 layerPos = _config->getTabsLayerPos();
        
        this->addTab(item->getTabBtn(), item->getTabLayer(), btnPos, layerPos);
        
        xBtnPos += item->getTabBtn()->getContentSize().width;
    }
    
    _currentTab = -1;
    
    return true;
}

void TabPanel::addTab(MenuItem* tabBtn, Layer *tabLayer, Vec2 tabPos, Vec2 tabLayerPos) {
    int tag = _tabsBtnHolder->getChildrenCount();
    tabBtn->setCallback(CC_CALLBACK_1(TabPanel::onTabClicked, this));
    tabBtn->setTag(tag);
    tabBtn->setPosition(tabPos);
    
    _tabsBtnHolder->addChild(tabBtn);
    
    tabLayer->setTag(tag);
    tabLayer->setVisible(false);
    tabLayer->setPosition(tabLayerPos);
    
    _tabsLayerHolder->addChild(tabLayer);
    
}

void TabPanel::onTabClicked(cocos2d::Ref *pSender) {
    MenuItem *item = (MenuItem *) pSender;
    int tag = item->getTag();
    
    this->openTabByTag(tag);
}

void TabPanel::openTabByTag(int tag) {
    if (tag != _currentTab) {
        resetTab(_currentTab, false);
        resetTab(tag, true);
        
        _currentTab = tag;
    }
}

void TabPanel::resetTab(int tag, bool isVisible) {
    if (tag != -1) {
        Node *layer = _tabsLayerHolder->getChildByTag(tag);
        MenuItemSprite *btn = (MenuItemSprite *) _tabsBtnHolder->getChildByTag(tag);
    
        layer->setVisible(isVisible);
        _config->changeBtnState(btn, isVisible);
    }
}
