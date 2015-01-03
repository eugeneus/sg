
#ifndef __SantaGnomes__ShopPopupCallback__
#define __SantaGnomes__ShopPopupCallback__

class ShopPopupCallback {
    
public:
    virtual void shopCallbackPaymentComplete() = 0;
    virtual void shopCallbackResume() = 0;
    virtual void shopCallbackCancel() = 0;
};


#endif /* defined(__SantaGnomes__ShopPopupCallback__) */
