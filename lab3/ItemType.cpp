#include "ItemType.h"
#include <map>
#include <string>

std::string GetItemTypeString(ItemType itemType) {
  std::map<ItemType, std::string> itemTypeStrings{
      {ItemType::TNone, "None"},
      {ItemType::TItem, "Item"},
      {ItemType::TCabinet, "Cabinet"},
      {ItemType::TAppliance, "Appliance"}};

  return itemTypeStrings.at(itemType);
}