
#include "MainMenuScene.h"
#include "MainMenu.h"

USING_NS_CC;

MainMenuScene::MainMenuScene(){}

MainMenuScene::~MainMenuScene() {}

Scene* MainMenuScene::createScene() {
    
    // 'scene' is an autorelease object
    auto mainMenuScene = Scene::create();
    
    // return the scene
    return mainMenuScene;
}

bool MainMenuScene::init()
{
    Menu* pMenu = MainMenu::create();
    pMenu->setPosition(Point::ZERO);
    this->addChild(pMenu, 1);

   return true;
}



