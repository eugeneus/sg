
#include "MainMenuScene.h"
#include "MainMenu.h"

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
//    Menu* pMenu = MainMenu::create();
//    pMenu->setPosition(Point::ZERO);
//    this->addChild(pMenu, 1);

   return true;
}



