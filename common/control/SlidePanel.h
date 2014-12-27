
#ifndef __SantaGnomes__SlidePanel__
#define __SantaGnomes__SlidePanel__

#include "SlidePanelItemsController.h"
#include "SlidePanelConfig.h"

class SlidePanel : public cocos2d::Layer {
    
public:
    static SlidePanel *create(SlidePanelItemsController *controller, SlidePanelConfig *config);
    
    void update();
    void toggle();
    
    void waitActions();
    
protected:
    bool init(SlidePanelItemsController *controller, SlidePanelConfig *config);
    SlidePanel();
    ~SlidePanel();
    
    cocos2d::Animation *createFrameAnimation(const std::string frameMask, int frameCount, float delay);
    void toggleShowHide(float toXPos, const std::string toggleAnimFrameMask, int framesCount);
    
    void drawItems();
private:
    cocos2d::Sprite *_btnNormal;
    cocos2d::MenuItem *_btn;
    cocos2d::Menu *_itemsMenu;
    SlidePanelItemsController *_controller;
    SlidePanelConfig *_config;
    
    bool _isOpened;
};


#endif /* defined(__SantaGnomes__SlidePanel__) */
