
#include "MainMenuScene.h"
#include "MainMenu.h"
#include "SimpleAudioEngine.h"
#include "ResourcesManager.h"
#include "UIConstants.h"

USING_NS_CC;

MainMenuScene::MainMenuScene(){}

MainMenuScene::~MainMenuScene() {}

Scene* MainMenuScene::createScene() {
    
    // 'scene' is an autorelease object
    auto pMainMenuScene = Scene::create();
    
    auto pLayer = MainMenuScene::create();
    //pMainMenuScene->init();
    // return the scene
    pMainMenuScene->addChild(pLayer);
    return pMainMenuScene;
}

MainMenuScene* MainMenuScene::create()
{
    MainMenuScene *pRet = new MainMenuScene();
    
    if (pRet && pRet->init()) {
        return pRet;
    }
    else{
        
        delete pRet;
        pRet = nullptr;
        return pRet;
    }
    
    
}

bool MainMenuScene::init()
{
    //std::string pszPlist = ResourcesManager::getInstance()->getResourcesPlistFileName();
    //std::string fileImage = ResourcesManager::getInstance()->getResourcesImagesFileName();
    
    //SpriteFrameCache::getInstance()->addSpriteFramesWithFile(pszPlist);
    //SpriteBatchNode *spriteBatch = SpriteBatchNode::create(fileImage);
    //this->addChild(spriteBatch);
    
    
   /* CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SOUND_CLICK);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SOUND_FALL_ITEM);
    
    bool isSoundOn = UserDataProvider::getInstance()->isSoundOn();
    bool isMusicOn = UserDataProvider::getInstance()->isMusicOn();
    
    float soundVolume = isSoundOn ? 1.0 : 0.0;
    float musicVolume = isMusicOn ? 1.0 : 0.0;
    
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(musicVolume);
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(soundVolume);*/
    
    
    Menu* pMenu = MainMenu::create();
    pMenu->setPosition(Point::ZERO);
    this->addChild(pMenu, 1);
    
    Sprite *bg = Sprite::createWithSpriteFrameName(MENU_BG);
    bg->setPosition(Vec2(0,0));
    bg->setAnchorPoint(Vec2(0,0));
    this->addChild(bg, -1001);
    
   return true;
}



