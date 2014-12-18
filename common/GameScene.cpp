
#include "GameScene.h"


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
   return true;
}



