#ifndef __SantaGnomes__GameScene__
#define __SantaGnomes__GameScene__

#include "cocos2d.h"

#include "GameController.h"
#include "PausePopupCallback.h"
#include "PopupControl.h"

class GameScene : public cocos2d::Layer, public PausePopupCallback {

public:
    GameScene();
    
    ~GameScene();
    
    static cocos2d::Scene* createScene();
    
    static GameScene* create();
    
    bool init();
    
    void onPauseCliked(cocos2d::Ref *pSender);
    
    void pauseGame();
    void resumeGame();
    
#pragma mark - Pause popup callback
    
    void pauseCallbackResume();
    void pauseCallbackReplay();
    void pauseCallbackSound(bool isOff);
    void pauseCallbackMainMenu();
    
protected:
    
    GameController* _theGameController;
    cocos2d::Menu* _btnsHolder;
    PopupControl* _popupController;

private:
    
};

#endif /* defined(__SantaGnomes__GameScene__) */
