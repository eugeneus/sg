#ifndef __SantaGnomes__SlidePanelConfig__
#define __SantaGnomes__SlidePanelConfig__

class SlidePanelConfig {
    
public:
    virtual int getPanelWidth() = 0;
    virtual bool isLeft() = 0;
    virtual float getYPos() = 0;
    
    virtual std::string getButtonMaskNormal() = 0;
    virtual int getButtonFrameCountNormal() = 0;
    
    virtual std::string getButtonMaskShow() = 0;
    virtual int getButtonFrameCountShow() = 0;
    
    virtual std::string getButtonMaskHide() = 0;
    virtual int getButtonFrameCountHide() = 0;
    
    virtual std::string getButtonMaskWait() = 0;
    virtual int getButtonFrameCountWait() = 0;
};

#endif /* defined(__SantaGnomes__SlidePanelConfig__) */
