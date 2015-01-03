
#include "BonusSlidePanelItems.h"
USING_NS_CC;

BonusSlidePanelItems::BonusSlidePanelItems() {}
BonusSlidePanelItems::~BonusSlidePanelItems() {}

BonusSlidePanelItems *BonusSlidePanelItems::create(BonusPanelCallback *callback) {
    BonusSlidePanelItems* pRet = new BonusSlidePanelItems();
    
    if (!pRet->init(callback))
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

bool BonusSlidePanelItems::init(BonusPanelCallback *callback) {
    if (!SlidePanelItemsController::init()) {
        return false;
    }
    
    _callback = callback;
    
    return true;
}


int createItemFrameNameIndex(int i) {
    if (i < 4) {
        return i + 1;
    } else {
        srand(static_cast<unsigned>(time(0)));
        int val = static_cast<int>(rand()/(static_cast<int>(RAND_MAX/(4-1))));
        return val != 0 ? val : 1;
    }
}

std::string createItemFrameName(int i) {
    int val = createItemFrameNameIndex(i);
    return CCString::createWithFormat("bonus_item_%i.png", val)->getCString();
}

void BonusSlidePanelItems::initItems() {
    for (int i = 0; i < 5; i ++) {
        std::string frameName = createItemFrameName(i);
        Sprite *itemImg = Sprite::createWithSpriteFrameName(frameName);
        
        Sprite *normal = Sprite::createWithSpriteFrameName("bonus_item_bg.png");
        Sprite *selected = Sprite::createWithSpriteFrameName("bonus_item_bg.png");
        MenuItem *item = MenuItemSprite::create(normal, selected, CC_CALLBACK_1(BonusSlidePanelItems::onItemClicked, this));
        item->setTag(i + 1);
        item->setContentSize(Size(item->getContentSize().width, item->getContentSize().height + itemImg->getContentSize().height));
        
        itemImg->setPosition(Vec2(itemImg->getPosition().x + normal->getContentSize().width/2, itemImg->getPosition().y + normal->getContentSize().height/2 + itemImg->getContentSize().height/2));
        item->addChild(itemImg);
        
        this->addItem(item);
    }
}

void BonusSlidePanelItems::onItemClicked(Ref *pSender) {
    MenuItem *item = (MenuItem *) pSender;
    CCLOG("--- bonus item %i clicked. ----", item->getTag());
    
    // if no bonus
    _callback->onShowShopPopup(2, item->getTag()); //TODO: bonusPageType & itemType
    
}
