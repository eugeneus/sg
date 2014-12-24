
#ifndef __SantaGnomes__PausePopupCallback__
#define __SantaGnomes__PausePopupCallback__

class PausePopupCallback {
    
public:
    virtual void pauseCallbackResume() = 0;
    virtual void pauseCallbackReplay() = 0;
    virtual void pauseCallbackSound(bool isOff) = 0;
    virtual void pauseCallbackMainMenu() = 0;
};

#endif /* defined(__SantaGnomes__PausePopupCallback__) */
