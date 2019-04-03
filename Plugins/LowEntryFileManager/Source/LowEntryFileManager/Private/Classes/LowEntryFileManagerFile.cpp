// Copyright Low Entry. All Rights Reserved.

#include "LowEntryFileManagerFile.h"
#include "LowEntryFileManagerLibrary.h"
#include "LowEntryFileManagerDirectory.h"

#include "GenericPlatform/GenericPlatformFile.h"


// init >>
	ULowEntryFileManagerFile::ULowEntryFileManagerFile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryFileManagerFile* ULowEntryFileManagerFile::Create(const FString& Directory, const FString& Name)
	{
		ULowEntryFileManagerFile* Instance = NewObject<ULowEntryFileManagerFile>();
		Instance->Directory = Directory;
		Instance->Name = Name;
		Instance->Path = Directory + Name;
		return Instance;
	}
// init <<


FString ULowEntryFileManagerFile::GetPath() const
{
	return Path;
}

FString ULowEntryFileManagerFile::GetAbsolutePath() const
{
	return ULowEntryFileManagerLibrary::RelativeToAbsolutePath(Path);
}

FString ULowEntryFileManagerFile::GetName() const
{
	return Name;
}

FString ULowEntryFileManagerFile::GetNameWithoutExtension() const
{
	FString NamePart;
	FString ExtensionPart;
	ULowEntryFileManagerLibrary::SplitName(Name, NamePart, ExtensionPart);
	return NamePart;
}

FString ULowEntryFileManagerFile::GetExtension() const
{
	FString NamePart;
	FString ExtensionPart;
	ULowEntryFileManagerLibrary::SplitName(Name, NamePart, ExtensionPart);
	return ExtensionPart;
}


ULowEntryFileManagerDirectory* ULowEntryFileManagerFile::GetParentDirectory()
{
	return ULowEntryFileManagerLibrary::GetDirectory(Directory);
}


bool ULowEntryFileManagerFile::ExistsBool()
{
	return ULowEntryFileManagerLibrary::FileExistsBool(GetPath());
}

void ULowEntryFileManagerFile::Exists(ELowEntryFileManagerYesNo& Branch)
{
	ULowEntryFileManagerLibrary::FileExists(GetPath(), Branch);
}

void ULowEntryFileManagerFile::Create()
{
	ULowEntryFileManagerLibrary::CreateNewFile(GetPath());
}

void ULowEntryFileManagerFile::Delete()
{
	ULowEntryFileManagerLibrary::DeleteFile(GetPath());
}


bool ULowEntryFileManagerFile::IsEmptyBool()
{
	return ULowEntryFileManagerLibrary::IsFileEmptyBool(GetPath());
}

void ULowEntryFileManagerFile::IsEmpty(ELowEntryFileManagerYesNo& Branch)
{
	ULowEntryFileManagerLibrary::IsFileEmpty(GetPath(), Branch);
}

void ULowEntryFileManagerFile::Clear()
{
	ULowEntryFileManagerLibrary::ClearFile(GetPath());
}


bool ULowEntryFileManagerFile::IsReadOnlyBool()
{
	return ULowEntryFileManagerLibrary::IsFileReadOnlyBool(GetPath());
}

void ULowEntryFileManagerFile::IsReadOnly(ELowEntryFileManagerYesNo& Branch)
{
	ULowEntryFileManagerLibrary::IsFileReadOnly(GetPath(), Branch);
}

void ULowEntryFileManagerFile::SetReadOnly(const bool ReadOnly)
{
	ULowEntryFileManagerLibrary::SetFileReadOnly(GetPath(), ReadOnly);
}


void ULowEntryFileManagerFile::Execute(const FString& Parameters, bool& Success, int32& ReturnCode, FString& StdOut, FString& StdErr)
{
	return ULowEntryFileManagerLibrary::ExecuteFile(GetAbsolutePath(), Parameters, Success, ReturnCode, StdOut, StdErr);
}

void ULowEntryFileManagerFile::ExecuteAsync(const FString& Parameters, bool& Success, int32& ProcessID, const bool Hidden, const int32 Priority, ULowEntryFileManagerDirectory* OptionalWorkingDirectory)
{
	return ULowEntryFileManagerLibrary::ExecuteFileAsync(GetAbsolutePath(), Parameters, Success, ProcessID, Hidden, Priority, (OptionalWorkingDirectory != nullptr) ? OptionalWorkingDirectory->GetAbsolutePath() : TEXT(""));
}


TArray<uint8> ULowEntryFileManagerFile::GetData()
{
	return ULowEntryFileManagerLibrary::GetFileData(GetPath());
}

void ULowEntryFileManagerFile::SetData(const TArray<uint8>& Data)
{
	ULowEntryFileManagerLibrary::SetFileData(GetPath(), Data);
}

void ULowEntryFileManagerFile::AppendData(const TArray<uint8>& Data)
{
	ULowEntryFileManagerLibrary::AppendFileData(GetPath(), Data);
}

int32 ULowEntryFileManagerFile::Size()
{
	return ULowEntryFileManagerLibrary::GetFileSize(GetPath());
}


FDateTime ULowEntryFileManagerFile::GetTimestamp()
{
	return ULowEntryFileManagerLibrary::GetFileTimestamp(GetPath());
}

void ULowEntryFileManagerFile::SetTimestamp(const FDateTime& Timestamp)
{
	ULowEntryFileManagerLibrary::SetFileTimestamp(GetPath(), Timestamp);
}


FDateTime ULowEntryFileManagerFile::GetAccessTimestamp()
{
	return ULowEntryFileManagerLibrary::GetFileAccessTimestamp(GetPath());
}


void ULowEntryFileManagerFile::CopyTo(ULowEntryFileManagerFile* NewFile)
{
	if(NewFile != nullptr)
	{
		ULowEntryFileManagerLibrary::CopyFile(GetPath(), NewFile->GetPath());
	}
}

void ULowEntryFileManagerFile::MoveTo(ULowEntryFileManagerFile* NewFile)
{
	if(NewFile != nullptr)
	{
		ULowEntryFileManagerLibrary::MoveFile(GetPath(), NewFile->GetPath());
	}
}
