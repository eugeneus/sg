
#include "SlidePanelItemsController.h"
USING_NS_CC;

bool SlidePanelItemsController::init() {
    this->initItems();
    //_items = new Vector<MenuItem *>();
    return true;
}

void SlidePanelItemsController::addItem(cocos2d::MenuItem *pItem) {
    _items.push_back(pItem);
}

int SlidePanelItemsController::getItemsCount() {
    return _items.size();
}

cocos2d::Node *SlidePanelItemsController::getItemAtIndex(int index) {
    return _items.at(index);
}
