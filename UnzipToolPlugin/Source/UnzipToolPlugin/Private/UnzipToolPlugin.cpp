// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "UnzipToolPlugin.h"

#if PLATFORM_ANDROID
#include"AndroidFile.h"
#endif

#define LOCTEXT_NAMESPACE "FUnzipToolPluginModule"

void FUnzipToolPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FUnzipToolPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FUnzipToolPluginModule::UnzipWebAche(const FString &InputParam, FString &OutputParam)
{
	//UCLassFunctionLibrary::UnzipTool(InputParam, OutputParam, ZipExePath, ZipExeParams);

#if PLATFORM_WINDOWS
	FString ZipExePath = "";
	FString ZipExeParams = "";
	    UnzipByWindows(ZipExePath, ZipExeParams);
		UE_LOG(LogClass, Log, TEXT("Windows ZIP"));
#endif

#if PLATFORM_ANDROID

		UnzipByAndroid(this->GetAndroidFilePath(InputParam), this->GetAndroidFilePath(OutputParam));
		FString InputPath = this->GetAndroidFilePath(InputParam);
		UE_LOG(LogClass, Log, TEXT("Android ZIP"));
#endif

#if PLATFORM_IOS

		UnzipByIOS(InputParam, OutputParam);

#endif

}

FString FUnzipToolPluginModule::GetAndroidFilePath(FString ParamText)
{
#if PLATFORM_ANDROID
	return IAndroidPlatformFile::GetPlatformPhysical().FileRootPath(*ParamText);
#else
	return ParamText;
#endif
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUnzipToolPluginModule, UnzipToolPlugin)


