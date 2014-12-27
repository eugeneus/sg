
#ifndef __SantaGnomes__BonusSlidePanelItems__
#define __SantaGnomes__BonusSlidePanelItems__

#include "SlidePanelItemsController.h"

class BonusSlidePanelItems : public SlidePanelItemsController {
public:
    static BonusSlidePanelItems *create();
    
    void onItemClicked(cocos2d::Ref *pSender);
protected:
    bool init();
    BonusSlidePanelItems();
    ~BonusSlidePanelItems();
    virtual void initItems();
    
    
};

#endif /* defined(__SantaGnomes__BonusSlidePanelItems__) */
