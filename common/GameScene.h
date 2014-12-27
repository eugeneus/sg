#ifndef __SantaGnomes__GameScene__
#define __SantaGnomes__GameScene__

#include "cocos2d.h"

#include "GameController.h"
#include "PausePopupCallback.h"
#include "PopupControl.h"
#include "ShopPopupCallback.h"

class GameScene : public cocos2d::Layer, public PausePopupCallback, public ShopPopupCallback {

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
    
    void pauseCallbackResume();
    void pauseCallbackReplay();
    void pauseCallbackSound(bool isOff);
    void pauseCallbackMainMenu();
    
#pragma mark - Pause popup callback
    
    void shopCallbackPaymentComplete();
    void shopCallbackResume();
    
protected:
    
    virtual void update(float delta);

    
    GameController* _theGameController;
    cocos2d::Menu* _btnsHolder;
    PopupControl* _popupController;

private:
    
};

#endif /* defined(__SantaGnomes__GameScene__) */
