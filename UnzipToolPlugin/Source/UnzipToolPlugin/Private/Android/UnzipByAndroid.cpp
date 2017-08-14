#include "UnzipToolPlugin.h"

#include"XmlParser.h"
#if PLATFORM_ANDROID
#include "Runtime/Launch/Public/Android/AndroidJNI.h"
#include "Runtime/Core/Public/Android/AndroidApplication.h"
#include "AndroidJava.h"
#include"AndroidFile.h"
#include"Runtime/Core/Public/Misc/Paths.h"
#endif

void AndroidThunkJava_UnzipDPLibiary(FString PocketCode, FString SceneInfo, FString outDirecty, FString XMLPath,bool isWrite);

#define LOCTEXT_NAMESPACE "FUnzipToolPluginModule"

void FUnzipToolPluginModule::UnzipByAndroid(const FString &InputParam, FString &OutputParam)
{

#if PLATFORM_ANDROID
	UE_LOG(LogClass, Log, TEXT("FAndroidUnzipModule::UnzipWebAche()"));

	FString AssetParam = "";
	FString XMLParam = "";

	return AndroidThunkJava_UnzipDPLibiary(InputParam, AssetParam, OutputParam, XMLParam, true);

#endif
}

#if PLATFORM_ANDROID

//Generate Temporary TXT file

/*extern "C" void Java_com_epicgames_ue4_GameActivity_nativeOnAndroidThunkJavaUpZip(JNIEnv *env, jobject obj)
{
	UE_LOG(LogClass, Log, TEXT("----------APP-----------:Java_com_epicgames_ue4_GameActivity_nativeOnAndroidThunkJava_unZip"));

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Java_com_epicgames_ue4_GameActivity_nativeOnAndroidThunkJava_unZip"));

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString SceneConfigPath = FPaths::GameContentDir() + "WebCache/Sys/Cmd/CmdCallBack.txt";
	FString InputTxtValue = "<Root><Cmd>UnZipFile</Cmd><Result>EnterScene</Result></Root>123";

	if (!PlatformFile.FileExists(*SceneConfigPath))
	{
		FFileHelper::SaveStringToFile(InputTxtValue, *SceneConfigPath);
	}

}*/


void AndroidThunkJava_UnzipDPLibiary(FString &InputParam, FString AssetParam, FString &OutputParam, FString XMLParam,bool isWrite)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
	char* UpZipPathTemp = TCHAR_TO_ANSI(*OutputParam);
	char* ZipPathTemp = TCHAR_TO_ANSI(*InputParam);

	FString XmLPath = FPaths::GameContentDir() + "DESINGER.xml";//XML¡¡DocumentBuilder
	FString XmLPathByAndroid = IAndroidPlatformFile::GetPlatformPhysical().FileRootPath(*XmLPath);
	char* XmLPathTemp = TCHAR_TO_ANSI(*XmLPathByAndroid);

	FString SYSPath = FPaths::GameContentDir() + "WebCache/Sys/Cmd/";
	FString SYSPathByAndroid = IAndroidPlatformFile::GetPlatformPhysical().FileRootPath(*SYSPath);
	char* SYSPathTemp = TCHAR_TO_ANSI(*SYSPathByAndroid);

	if (!IAndroidPlatformFile::GetPlatformPhysical().DirectoryExists(*SYSPath))
	{
		UE_LOG(LogClass, Log, TEXT("----------APP-----------:Android CreateDirectoryTree"));
		IAndroidPlatformFile::GetPlatformPhysical().CreateDirectoryTree(*SYSPath);
	}
	if (IAndroidPlatformFile::GetPlatformPhysical().DirectoryExists(*SYSPath))
	{
		UE_LOG(LogClass, Log, TEXT("----------APP-----------:Android CreateDirectoryTree2"));

	FString InputTxtValue= "<Root><Cmd>UnZipFile</Cmd><Result>EnterScene</Result></Root>";
	char* InputTxtValueTemp = TCHAR_TO_ANSI(*InputTxtValue);

	jstring ZipPathTempStr = Env->NewStringUTF(ZipPathTemp);
	jstring UpZipPathTempStr = Env->NewStringUTF(UpZipPathTemp);
	jstring assetStr = NULL;
	jstring XmLPathStr = Env->NewStringUTF(XmLPathTemp);
	jstring SYSPathStr= Env->NewStringUTF(SYSPathTemp);
	jstring InputTxtValueStr= Env->NewStringUTF(InputTxtValueTemp);

	UE_LOG(LogClass, Log, TEXT("Can run"));

	jmethodID UnzipDPLibiary = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_UnzipDPLibiary", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", false);

	FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, UnzipDPLibiary, ZipPathTempStr, assetStr, UpZipPathTempStr, XmLPathStr, SYSPathStr, InputTxtValueStr);

	Env->DeleteLocalRef(ZipPathTempStr);
	Env->DeleteLocalRef(UpZipPathTempStr);
	Env->DeleteLocalRef(assetStr);
	Env->DeleteLocalRef(XmLPathStr);
	Env->DeleteLocalRef(SYSPathStr);
	Env->DeleteLocalRef(InputTxtValueStr);
	}
	}

}
#endif

#undef LOCTEXT_NAMESPACE