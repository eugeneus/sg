
#include "GameScene.h"
#include "MainMenuScene.h"
#include "PopupControl.h"
#include "PausePopup.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;

GameScene::GameScene(){}

GameScene::~GameScene() {}

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

GameScene* GameScene::create()
{
    GameScene *pRet = new GameScene();
    
    if (pRet && pRet->init()) {
        return pRet;
    }
    else{
        
        delete pRet;
        pRet = nullptr;
        return pRet;
    }
}

bool GameScene::init()
{
    _theGameController = GameController::create(this);
    _popupController = PopupControl::create();
    _btnsHolder = Menu::create();
    this->addChild(_btnsHolder, 100);
   return true;
}

void GameScene::pauseGame() {}
void GameScene::resumeGame() {}

void GameScene::onPauseCliked(cocos2d::Ref *pSender) {
    CCLOG("pause");
    
    pauseGame();
    _popupController->showPopup(PausePopup::create(), this, this);
}

#pragma mark - Pause popup callback

void GameScene::pauseCallbackResume() {
    _popupController->hidePopup();
    
    this->resumeGame();
}

void GameScene::pauseCallbackReplay() {
    _popupController->hidePopup();
    
    Director::getInstance()->replaceScene(GameScene::createScene());
}

void GameScene::pauseCallbackSound(bool isOff) {
    _popupController->hidePopup();
    
    float bgVolume = isOff ? 0.0 : 1.0; //UserData getBgVolume
    float effectVolume = isOff ? 0.0 : 1.0; //UserData getEffectVolume
    
    //UserData isSoundOff
    
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(bgVolume);
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(effectVolume);
}

void GameScene::pauseCallbackMainMenu() {
    _popupController->hidePopup();
    
    Director::getInstance()->replaceScene(MainMenuScene::createScene());
}
