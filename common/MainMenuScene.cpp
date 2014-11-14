
#include "MainMenuScene.h"
#include "MainMenu.h"

USING_NS_CC;

MainMenuScene::MainMenuScene(){}

MainMenuScene::~MainMenuScene() {}

Scene* MainMenuScene::createScene() {
    
    // 'scene' is an autorelease object
    auto mainMenuScene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();
    
    // add layer as a child to scene
    mainMenuScene->addChild(layer);
    
    // return the scene
    return mainMenuScene;
}

bool MainMenuScene::init()
{
   return false;
}



