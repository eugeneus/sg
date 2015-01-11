
#ifndef __SantaGnomes__ShopBonusLayer__
#define __SantaGnomes__ShopBonusLayer__

#include "cocos2d.h"
#include "ShopPopupCallback.h"
#include "ShopBonusSelectorCallback.h"

class ShopBonusLayer : public cocos2d::Layer , public ShopBonusSelectorCallback {
public:
    //CREATE_FUNC(ShopBonusLayer);
    static ShopBonusLayer *create(int selected, ShopPopupCallback *callback);
    void onCancelClicked(cocos2d::Ref *pSender);
    void onBuyClicked(cocos2d::Ref *pSender);
    
    virtual void onBonusSelected(int bonusType);
protected:
    bool init(int selected, ShopPopupCallback *callback);
private:
    ShopPopupCallback *_callback;
    cocos2d::Sprite *_bonusThumb;
    cocos2d::Label *_bonusName;
    cocos2d::Label *_bonusDescr;
};

#endif /* defined(__SantaGnomes__ShopBonusLayer__) */
