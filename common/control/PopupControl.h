

#ifndef __SantaGnomes__PopupControl__
#define __SantaGnomes__PopupControl__

#include "PopupRenderer.h"
#include "PopupCallback.h"

class PopupControl {
    
public:
    static PopupControl *create();
    
    void showPopup(PopupRenderer *pRenderer, cocos2d::Layer *pTarget, PopupCallback *callback);
    void hidePopup();
    void removePopup();
    
    
protected:
    bool init();
    PopupControl();
    ~PopupControl();
private:
    PopupRenderer *_renderer;
    cocos2d::Layer *_target;
};

#endif /* defined(__SantaGnomes__PopupControl__) */
