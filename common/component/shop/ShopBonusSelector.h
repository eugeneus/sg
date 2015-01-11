
#ifndef __SantaGnomes__ShopBonusSelector__
#define __SantaGnomes__ShopBonusSelector__

#include "ShopBonusSelectorCallback.h"

class ShopBonusSelector : public cocos2d::Layer {
private:
    ShopBonusSelectorCallback *_callback;
protected:
    bool init(ShopBonusSelectorCallback *callback, int bonusType);
public:
    static ShopBonusSelector *create(ShopBonusSelectorCallback *callback, int bonusType);
    void onItemSelected(cocos2d::Ref *pSender);
};

#endif /* defined(__SantaGnomes__ShopBonusSelector__) */
