
#ifndef __SantaGnomes__SlidePanelItemsController__
#define __SantaGnomes__SlidePanelItemsController__

class SlidePanelItemsController {
    
public:
    int getItemsCount();
    cocos2d::Node *getItemAtIndex(int index);
protected:
    
    bool init();
    virtual void initItems() = 0;
    
    void addItem(cocos2d::MenuItem *pItem);
private:
    std::vector<cocos2d::MenuItem*> _items;
    
};

#endif /* defined(__SantaGnomes__SlidePanelItemsController__) */
