
#ifndef __SantaGnomes__PausePopup__
#define __SantaGnomes__PausePopup__

#include "PopupRenderer.h"
#include "PausePopupCallback.h"

class PausePopup : public PopupRenderer {
    
public:
    static PausePopup *create();
    
    void onResumeClicked(cocos2d::Ref *pSender);
    void onReplayClicked(cocos2d::Ref *pSender);
    void onSoundClicked(cocos2d::Ref *pSender);
    void onMainMenuClicked(cocos2d::Ref *pSender);
    
    void initButtons(cocos2d::Layer *pTarget, PopupCallback* callback);
protected:
    bool init();
    PausePopup();
    ~PausePopup();
    
    cocos2d::Sprite* createPopupBg();
    cocos2d::Sprite* createContentBg();

private:

};

#endif /* defined(__SantaGnomes__PausePopup__) */
