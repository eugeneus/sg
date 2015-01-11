
#include "ShopTabPanelPage.h"
USING_NS_CC;

ShopTabPanelPage *ShopTabPanelPage::create(int page, int pageItem) {
    ShopTabPanelPage* pRet = new ShopTabPanelPage();
    
    if (!pRet->init(page, pageItem))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
    
}

bool ShopTabPanelPage::init(int page, int pageItem) {
    _page = page;
    _pageItem = pageItem;
    
    return true;
}

int ShopTabPanelPage::getPage() {
    return _page;
}

int ShopTabPanelPage::getPageItem() {
    return _pageItem;
}