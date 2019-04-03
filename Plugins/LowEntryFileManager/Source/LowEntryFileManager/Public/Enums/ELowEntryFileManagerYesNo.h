// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"

#include "ELowEntryFileManagerYesNo.generated.h"


UENUM()
enum class ELowEntryFileManagerYesNo : uint8
{
	Yes = 0,
	No = 1
};

static const ELowEntryFileManagerYesNo ELowEntryFileManagerYesNoByBoolean(bool Boolean)
{
	if(Boolean)
	{
		return ELowEntryFileManagerYesNo::Yes;
	}
	else
	{
		return ELowEntryFileManagerYesNo::No;
	}
}
