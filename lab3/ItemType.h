#ifndef LAB3_ITEMTYPE_H
#define LAB3_ITEMTYPE_H
#include <string>

enum class ItemType { TNone, TItem, TCabinet, TAppliance };

std::string GetItemTypeString(ItemType itemType);

#endif