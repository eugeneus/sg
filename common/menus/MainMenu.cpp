
#include "MainMenu.h"
#include "GameScene.h"

USING_NS_CC;

MainMenu::MainMenu(){}

MainMenu::~MainMenu() {}

MainMenu* MainMenu::create() {

   return Menu::create();
}

bool MainMenu::init()
{
   if ( !Menu::init() )
    {
        return false;
    }
	
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();	
	
	Point beginPos = Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 50);
	float step = 60.0f;

/*	
	cocos2d::MenuItem* pMenuItem = cocos2d::MenuItemImage::create(
                                            "CloseNormal.png",
                                            "CloseSelected.png",
                                            this,
                                            menu_selector(MainMenu::menuCallback));
*/											
	    MenuItemFont *pItem = MenuItemFont::create("Play", menu_selector(MainMenu::menuCallback, this));
        pItem->setTag(0);
        pItem->setPosition(Point(beginPos.x, beginPos.y - 0 * step));
        pMenu->addChild(pItem);										

	    *pItem = MenuItemFont::create("Close", menu_selector(MainMenu::menuCallback, this));
        pItem->setTag(1);
        pItem->setPosition(Point(beginPos.x, beginPos.y - 1 * step));
        pMenu->addChild(pItem);	

	return true
}


void MainMenu::menuCallback(Ref* pSender)
{
    MenuItemFont *pItem = (MenuItemFont*) pSender;
    Scene* newScene = NULL;
    switch (pItem->getTag()) {
    case 0:
        newScene = GameScene::scene();
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



