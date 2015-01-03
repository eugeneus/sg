
#ifndef __SantaGnomes__ShopPopup__
#define __SantaGnomes__ShopPopup__

#include "PopupRenderer.h"
#include "ShopPopupCallback.h"

class ShopPopup : public PopupRenderer {
    
public:
    static ShopPopup *create(int pageType, int bonusType, ShopPopupCallback *callback);
    
    void onPaymentComplete(cocos2d::Ref *pSender);
    void onResumeGame(cocos2d::Ref *pSender);
    
    void initButtons(cocos2d::Layer *pTarget);
protected:
    bool init(int pageType, int bonusType, ShopPopupCallback *callback);
    ShopPopup();
    ~ShopPopup();
    
    cocos2d::Sprite* createPopupBg();
    cocos2d::Sprite* createContentBg();
    
private:
    int _pageType;
    int _bonusType;
    ShopPopupCallback *_callback;
};

#endif /* defined(__SantaGnomes__ShopPopup__) */
