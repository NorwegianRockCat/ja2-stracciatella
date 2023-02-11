#pragma once

#include "Item_Types.h"
#include "ItemStrings.h"
#include "InventoryGraphicsModel.h"
#include "Json.h"
#include "TilesetTileIndexModel.h"

#include <string_theory/string>

class JsonObject;
class JsonObject;
struct MagazineModel;
struct WeaponModel;

struct ItemModel
{
	ItemModel(
		uint16_t itemIndex,
		ST::string internalName,
		uint32_t usItemClass,
		uint8_t classIndex=0,
		ItemCursor cursor=INVALIDCURS);

	ItemModel(
		uint16_t   itemIndex,
		ST::string internalName,
		ST::string shortName,
		ST::string name,
		ST::string description,
		uint32_t   usItemClass,
		uint8_t    ubClassIndex,
		ItemCursor ubCursor,
		InventoryGraphicsModel inventoryGraphics,
		TilesetTileIndexModel tileGraphic,
		uint8_t    ubWeight,
		uint8_t    ubPerPocket,
		uint16_t   usPrice,
		uint8_t    ubCoolness,
		int8_t     bReliability,
		int8_t     bRepairEase,
		uint16_t   fFlags);

	// This could be default in C++11
	virtual ~ItemModel();

	const virtual ST::string& getInternalName() const;
	const virtual ST::string& getShortName() const;
	const virtual ST::string& getName() const;
	const virtual ST::string& getDescription() const;

	virtual uint16_t        getItemIndex() const;
	virtual uint32_t        getItemClass() const;
	virtual uint8_t         getClassIndex() const;
	virtual ItemCursor      getCursor() const;
	virtual const GraphicModel& getInventoryGraphicSmall() const;
	virtual const GraphicModel& getInventoryGraphicBig() const;
	virtual const TilesetTileIndexModel& getTileGraphic() const;
	virtual uint8_t         getWeight() const;
	virtual uint8_t         getPerPocket() const;
	virtual uint16_t        getPrice() const;
	virtual uint8_t         getCoolness() const;
	virtual int8_t          getReliability() const;
	virtual int8_t          getRepairEase() const;
	virtual uint16_t        getFlags() const;

	virtual bool isAmmo() const;
	virtual bool isArmour() const;
	virtual bool isBlade() const;
	virtual bool isBomb() const;
	virtual bool isExplosive() const;
	virtual bool isFace() const;
	virtual bool isGrenade() const;
	virtual bool isGun() const;
	virtual bool isKey() const;
	virtual bool isKit() const;
	virtual bool isLauncher() const;
	virtual bool isMedkit() const;
	virtual bool isMisc() const;
	virtual bool isMoney() const;
	virtual bool isPunch() const;
	virtual bool isTentacles() const;
	virtual bool isThrowingKnife() const;
	virtual bool isThrown() const;
	virtual bool isWeapon() const;

	virtual bool isTwoHanded() const;
	virtual bool isInBigGunList() const;

	virtual const WeaponModel* asWeapon() const   { return NULL; }
	virtual const MagazineModel* asAmmo() const   { return NULL; }

	/** Check if the given attachment can be attached to the item. */
	virtual bool canBeAttached(uint16_t attachment) const;

	virtual JsonValue serialize() const;

	static ST::string deserializeShortName(const JsonObject &obj, const VanillaItemStrings& vanillaItemStrings);
	static ST::string deserializeName(const JsonObject &obj, const VanillaItemStrings& vanillaItemStrings);
	static ST::string deserializeDescription(const JsonObject &obj, const VanillaItemStrings& vanillaItemStrings);
	static const ItemModel* deserialize(const JsonValue &json, const VanillaItemStrings& vanillaItemStrings);
protected:
	uint16_t   itemIndex;
	ST::string internalName;
	ST::string shortName;
	ST::string name;
	ST::string description;
	uint32_t   usItemClass;
	uint8_t    ubClassIndex;
	ItemCursor ubCursor;
	InventoryGraphicsModel inventoryGraphics;
	TilesetTileIndexModel tileGraphic;
	uint8_t    ubWeight; //2 units per kilogram; roughly 1 unit per pound
	uint8_t    ubPerPocket;
	uint16_t   usPrice;
	uint8_t    ubCoolness;
	int8_t     bReliability;
	int8_t     bRepairEase;
	uint16_t   fFlags;

	void serializeFlags(JsonObject &obj) const;
	uint32_t deserializeFlags(JsonObject &obj) const;
};
