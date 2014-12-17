#include "ResourcesManager.h"

ResourcesManager* ResourcesManager::_instance = nullptr;
ResourcesManager::ResourcesManager(){}
ResourcesManager::~ResourcesManager() {}

ResourcesManager* ResourcesManager::getInstance()
{
    
    
    if (! _instance)
    {
        _instance = new ResourcesManager();
        if (_instance && _instance->init())
        {
            return _instance;
        }
        else
        {
            delete _instance;
            _instance = NULL;
            return NULL;
        }
        
    }
    
    return _instance;
}

bool ResourcesManager::init()
{
    
    
    
    return true;
}

void ResourcesManager::setScreenSize(cocos2d::Size size) {
    _size = size;
    
    this->initializeData();
}

std::string ResourcesManager::getResourcesPlistFileName() {
    return _plist;
}

std::string ResourcesManager::getResourcesImagesFileName() {
    return _images;
}

float ResourcesManager::getResolutionWidth() {
    return _resolutionWidth;
}

float ResourcesManager::getResolutionHeight() {
    return _resolutionHeight;
}

ResolutionPolicy ResourcesManager::getResolutionPolicy() {
    return _resolutionPolicy;
}

float ResourcesManager::getBottomOffset() {
    return _bottomOffset;
}

void ResourcesManager::initializeData() {
    
    _bottomOffset = 0;
    if (2048 == _size.width || 2048 == _size.height) {
        _resolutionPolicy = ResolutionPolicy::NO_BORDER;
        _resolutionHeight = 1536;
        _resolutionWidth = 2048;
    } else if (1024 == _size.width || 1024 == _size.height) {
        _resolutionPolicy = ResolutionPolicy::NO_BORDER;
        _resolutionHeight = 768;
        _resolutionWidth = 1024;
    } else if (1136 == _size.width || 1136 == _size.height) {
        _resolutionPolicy = ResolutionPolicy::SHOW_ALL;
        _resolutionHeight = 640;
        _resolutionWidth = 1136;
        
        _bottomOffset = 176;
        
    } else if (960 == _size.width || 960 == _size.height) {
        _resolutionPolicy = ResolutionPolicy::NO_BORDER;
        _resolutionHeight = 640;
        _resolutionWidth = 960;
    } else if (480 == _size.width || 480 == _size.height) {
        _resolutionPolicy = ResolutionPolicy::SHOW_ALL;
        _resolutionHeight = 320;
        _resolutionWidth = 480;
    }
    
    _images = CCString::createWithFormat("level_%ix%i.png", (int)_resolutionWidth, (int)_resolutionHeight)->getCString();
    _plist = CCString::createWithFormat("level_%ix%i.plist", (int)_resolutionWidth, (int)_resolutionHeight)->getCString();
}