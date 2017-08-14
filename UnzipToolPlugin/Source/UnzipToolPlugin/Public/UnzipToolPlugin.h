// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "ModuleManager.h"
#include "CoreMinimal.h"
#include "Engine.h"


//DECLARE_DELEGATE_OneParam(HGameUnZipSuccessDelegate,FString);
//DECLARE_DELEGATE_OneParam(HGameUnZipFailDelegate, FString);

class FUnzipToolPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual void UnzipWebAche(const FString &InputParam, FString &OutputParam);
	void UnzipByWindows(FString InputParam, FString OutputParam);
	void UnzipByAndroid(FString InputParam, FString OutputParam);
	void UnzipByIOS(FString InputParam, FString OutputParam);

	FString GetAndroidFilePath(FString ParamText);


};