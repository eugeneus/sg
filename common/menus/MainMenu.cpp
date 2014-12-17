
#include "MainMenu.h"
#include "GameScene.h"

USING_NS_CC;

MainMenu::MainMenu(){}

MainMenu::~MainMenu() {}

MainMenu* MainMenu::create() {

    MainMenu *ret = new MainMenu();
    if (ret && ret->init())
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    MainMenu* pRet = new MainMenu();
    pRet->init();
    return pRet;
    
}

bool MainMenu::init()
{
   if ( !Menu::init() )
    {
        return false;
    }
	
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();	
	
	Point beginPos = Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 250);
    float step = 100.0f;

/*	
	cocos2d::MenuItem* pMenuItem = cocos2d::MenuItemImage::create(
                                            "CloseNormal.png",
                                            "CloseSelected.png",
                                            this,
                                            menu_selector(MainMenu::menuCallback));
 
*/
    int i =0;
    
    MenuItemFont *pItem = MenuItemFont::create("Continue", CC_CALLBACK_1(MainMenu::menuCallback,this));
    pItem->setTag(0);
    pItem->setPosition(Point(beginPos.x, beginPos.y - i++ * step));
    this->addChild(pItem);


    pItem = MenuItemFont::create("Select", CC_CALLBACK_1(MainMenu::menuCallback,this));
    pItem->setTag(2);
    pItem->setPosition(Point(beginPos.x, beginPos.y - i++ * step));
    this->addChild(pItem);
    
    pItem = MenuItemFont::create("Close", CC_CALLBACK_1(MainMenu::menuCallback, this));
    pItem->setTag(1);
    pItem->setPosition(Point(beginPos.x, beginPos.y - i++ * step));
    this->addChild(pItem);

    return true;
}


void MainMenu::menuCallback(Ref* pSender)
{
    MenuItemFont *pItem = (MenuItemFont*) pSender;
    Scene* newScene = NULL;
    switch (pItem->getTag()) {
    case 0:
            newScene = GameScene::createScene();
            break;
    case 1:
        Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
#endif
        break;
    default:
        break;
    }

    if (newScene) {
        Director::getInstance()->replaceScene(newScene);
    }
}



