// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "ILowEntryFileManagerModule.h"


class FLowEntryFileManagerModule : public ILowEntryFileManagerModule
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
