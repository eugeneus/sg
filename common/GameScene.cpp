
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

GameScene* GameScene::create() {

   return nullptr;
}

bool GameScene::init()
{
   return false;
}



