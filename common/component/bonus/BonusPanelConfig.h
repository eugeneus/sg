
#ifndef __SantaGnomes__BonusPanelConfig__
#define __SantaGnomes__BonusPanelConfig__

#include "SlidePanelConfig.h"

class BonusPanelConfig : public SlidePanelConfig {
    
public:
    static BonusPanelConfig *create();
    
    virtual int getPanelWidth();
    virtual bool isLeft();
    virtual float getYPos();
    
    virtual std::string getButtonMaskNormal();
    virtual int getButtonFrameCountNormal();
    
    virtual std::string getButtonMaskShow();
    virtual int getButtonFrameCountShow();
    
    virtual std::string getButtonMaskHide();
    virtual int getButtonFrameCountHide();
    
    virtual std::string getButtonMaskWait();
    virtual int getButtonFrameCountWait();
protected:
    bool init();
    BonusPanelConfig();
    ~BonusPanelConfig();
};

#endif /* defined(__SantaGnomes__BonusPanelConfig__) */
