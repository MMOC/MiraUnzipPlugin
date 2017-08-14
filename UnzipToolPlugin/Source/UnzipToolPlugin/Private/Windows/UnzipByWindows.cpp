#include "UnzipToolPlugin.h"

#include"Runtime/Core/Public/Misc/Paths.h"

void FUnzipToolPluginModule::UnzipByWindows(const FString InputParam, FString OutputParam)
{
	FPlatformProcess::CreateProc(*InputParam, *OutputParam, true, false, false, nullptr, 0, nullptr, nullptr);
	UE_LOG(LogClass, Log, TEXT("AHGameUserPlayerController::OnEnterScene step8"));

	/*HGameEvent*Event;
	SuccessDelegate.Execute(Event);*/
}