
#include "BonusPanelConfig.h"

USING_NS_CC;

BonusPanelConfig::BonusPanelConfig() {}
BonusPanelConfig::~BonusPanelConfig() {}

BonusPanelConfig *BonusPanelConfig::create() {
    BonusPanelConfig* pRet = new BonusPanelConfig();
    
    if (!pRet->init())
    {
        delete pRet;
        pRet = nullptr;
    }
    
    return pRet;
}

bool BonusPanelConfig::init() {
    
    return true;
}

int BonusPanelConfig::getPanelWidth() {
    return 300;
}

bool BonusPanelConfig::isLeft() {
    return false;
}

float BonusPanelConfig::getYPos() {
    return -100;
}

std::string BonusPanelConfig::getButtonMaskNormal() {
    return "btn_show_bonus_wait_0%i.png";
}

int BonusPanelConfig::getButtonFrameCountNormal() {
    return 2;
}

std::string BonusPanelConfig::getButtonMaskShow() {
    return "btn_show_bonus_0%i.png";
}

int BonusPanelConfig::getButtonFrameCountShow() {
    return 2;
}

std::string BonusPanelConfig::getButtonMaskHide() {
    return "btn_show_bonus_0%i.png";
}

int BonusPanelConfig::getButtonFrameCountHide() {
    return 2;
}

std::string BonusPanelConfig::getButtonMaskWait() {
    return "btn_show_bonus_wait_0%i.png";
}

int BonusPanelConfig::getButtonFrameCountWait() {
    return 2;
}
