#include "AssetManager.h"

AssetManager::AssetManager(token) { std::cout << "constructed" << std::endl; }

AssetManager::~AssetManager() {  std::cout << "destructed" << std::endl; }

void AssetManager::use() 
{ 
    someVal++;
    std::cout << someVal << std::endl; 
};