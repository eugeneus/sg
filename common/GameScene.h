#ifndef __SantaGnomes__GameScene__
#define __SantaGnomes__GameScene__

#include "cocos2d.h"

#include "GameController.h"
#include "PausePopupCallback.h"
#include "PopupControl.h"
#include "ShopPopupCallback.h"
#include "SlidePanel.h"
#include "BonusPanelCallback.h"

class GameScene : public cocos2d::Layer, public PausePopupCallback, public ShopPopupCallback, public BonusPanelCallback {

public:
    GameScene();
    
    ~GameScene();
    
    static cocos2d::Scene* createScene();
    
    static GameScene* create();
    
    bool init();
    
    void onPauseCliked(cocos2d::Ref *pSender);
    
    void pauseGame();
    void resumeGame();
    
    virtual void onEnterTransitionDidFinish();
    
#pragma mark - Pause popup callback
    
    virtual void pauseCallbackResume();
    virtual void pauseCallbackReplay();
    virtual void pauseCallbackSound(bool isOff);
    virtual void pauseCallbackMainMenu();
    
#pragma mark - Pause popup callback
    
    virtual void shopCallbackPaymentComplete();
    virtual void shopCallbackResume();
    virtual void shopCallbackCancel();

#pragma mark - Bonus slide panel callback
    
    virtual void onShowShopPopup(int pageType, int bonusType);
    
protected:
    
    virtual void update(float delta);

    
    GameController* _theGameController;
    cocos2d::Menu* _btnsHolder;
    PopupControl* _popupController;
    
    SlidePanel* _bonusPanel;

private:
    
};

#endif /* defined(__SantaGnomes__GameScene__) */
