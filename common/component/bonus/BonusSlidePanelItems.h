
#ifndef __SantaGnomes__BonusSlidePanelItems__
#define __SantaGnomes__BonusSlidePanelItems__

#include "SlidePanelItemsController.h"
#include "BonusPanelCallback.h"

class BonusSlidePanelItems : public SlidePanelItemsController {
public:
    static BonusSlidePanelItems *create(BonusPanelCallback *callback);
    
    void onItemClicked(cocos2d::Ref *pSender);
protected:
    bool init(BonusPanelCallback *callback);
    BonusSlidePanelItems();
    ~BonusSlidePanelItems();
    virtual void initItems();
private:
    BonusPanelCallback *_callback;
    
};

#endif /* defined(__SantaGnomes__BonusSlidePanelItems__) */
