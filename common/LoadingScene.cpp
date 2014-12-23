
#include "LoadingScene.h"
#include "ResourcesManager.h"
#include "MainMenuScene.h"

USING_NS_CC;

LoadingScene::LoadingScene(){}

LoadingScene::~LoadingScene() {}

Scene* LoadingScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LoadingScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

LoadingScene* LoadingScene::create() {
    
    LoadingScene *pRet = new LoadingScene();
    
    if (pRet && pRet->init()) {
        return pRet;
    }
    else{
        
        delete pRet;
        pRet = nullptr;
        return pRet;
    }
}

bool LoadingScene::init()
{
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite *bg = Sprite::create("loading_bg.png");
    bg->setAnchorPoint(Vec2(0,0));
    bg->setPosition(Vec2(0,0));
    this->addChild(bg, -1001);
    numberOfLoadedRes = 0;
    
    spin = Sprite::create("CloseNormal.png");
    spin->setPosition(Vec2(winSize.width/2, winSize.height/2));
    this->addChild(spin, 1001);
    spin->runAction(RepeatForever::create(RotateBy::create(1.0f, 20)));
    
    return true;
}

void LoadingScene::preloadData() {
   // SimpleAudioEngine::getInstance()->preloadBackgroundMusic(FileUtils::getInstance()->fullPathForFilename("sound/music.mp3").c_str() );
   // numberOfLoadedRes++;
   // SimpleAudioEngine::getInstance()->preloadEffect(FileUtils::getInstance()->fullPathForFilename("sound/dead.wav" ).c_str());
   // numberOfLoadedRes++;
    std::string pszPlist = ResourcesManager::getInstance()->getResourcesPlistFileName();
    std::string fileImage = ResourcesManager::getInstance()->getResourcesImagesFileName();
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(pszPlist);
    numberOfLoadedRes++;
    
    Director::getInstance()->getTextureCache()->addImageAsync(fileImage, CC_CALLBACK_1(LoadingScene::loadingCallBack, this));
}

void LoadingScene::onEnter() {
    super::onEnter();
    
    this->preloadData();
}

void LoadingScene::loadingCallBack(cocos2d::Texture2D *texture)
{
    numberOfLoadedRes++;
    if (numberOfLoadedRes == 2)
    {
        spin->stopAllActions();
        spin->removeFromParentAndCleanup(true);

        Director::getInstance()->replaceScene(MainMenuScene::createScene());
    }
}