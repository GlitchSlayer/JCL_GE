#include "stdafx.h"

CannonBase obj::cBase({ 683, 384 }, { 64, 64 });
Cannon obj::superCannon({}, { 64, 32 });
Player obj::player(cBase, superCannon);
Reaper obj::reaper({ 500, 500 }, { 64, 64 });
Room obj::theRoom;