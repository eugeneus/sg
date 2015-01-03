
#ifndef __SantaGnomes__ShopTabPanelPage__
#define __SantaGnomes__ShopTabPanelPage__

#include "cocos2d.h"

class ShopTabPanelPage {
public:
    static ShopTabPanelPage *create(int page, int pageItem);
    
    int getPage();
    int getPageItem();
protected:
    bool init(int page, int pageItem);
private:
    int _page;
    int _pageItem;
};

#endif /* defined(__SantaGnomes__ShopTabPanelPage__) */
