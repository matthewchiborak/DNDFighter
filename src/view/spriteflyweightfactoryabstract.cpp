#include "spriteflyweightfactoryabstract.h"

#include "../filemanagment/fileReader.h"

SpriteFlyweightFactoryAbstract::SpriteFlyweightFactoryAbstract(std::string spriteListFilepath)
{
    this->spriteListFilepath = spriteListFilepath;
}

SpriteFlyweight *SpriteFlyweightFactoryAbstract::getFlyweight(std::string key)
{
    return nullptr;
}

SpriteFlyweight *SpriteFlyweightFactoryAbstract::createFlyweight(std::string key)
{
    return nullptr;
}
