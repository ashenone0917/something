#pragma once

#include "VolumeTable.h"

class GlobalData : public GlobalDataV0 {
public:
	static CVolumeTable m_volumeTable;

public:
	static bool read();
	static void create();
	static void save();
	static void updata();
	static void search(QUERY* pQuery);
};