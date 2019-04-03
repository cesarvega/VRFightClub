// Copyright Low Entry. All Rights Reserved.

#include "LowEntryFileManagerDirectory.h"
#include "LowEntryFileManagerLibrary.h"
#include "LowEntryFileManagerFile.h"

#include "GenericPlatform/GenericPlatformFile.h"


// init >>
	ULowEntryFileManagerDirectory::ULowEntryFileManagerDirectory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}

	ULowEntryFileManagerDirectory* ULowEntryFileManagerDirectory::CreateRoot()
	{
		ULowEntryFileManagerDirectory* Instance = NewObject<ULowEntryFileManagerDirectory>();
		Instance->Directory = TEXT("");
		Instance->Name = TEXT("");
		Instance->Path = TEXT("");
		Instance->bIsRoot = true;
		return Instance;
	}

	ULowEntryFileManagerDirectory* ULowEntryFileManagerDirectory::CreateAbsoluteRoot()
	{
		ULowEntryFileManagerDirectory* Instance = NewObject<ULowEntryFileManagerDirectory>();
		Instance->Directory = TEXT("");
		if(ULowEntryFileManagerLibrary::HasDiskPathsBool())
		{
			Instance->Name = TEXT("Computer:/");
			Instance->Path = TEXT("Computer:/");
		}
		else
		{
			Instance->Name = TEXT("/");
			Instance->Path = TEXT("/");
		}
		Instance->bIsRoot = true;
		return Instance;
	}

	ULowEntryFileManagerDirectory* ULowEntryFileManagerDirectory::Create(const FString& Directory, const FString& Name)
	{
		ULowEntryFileManagerDirectory* Instance = NewObject<ULowEntryFileManagerDirectory>();
		Instance->Directory = Directory;
		Instance->Name = Name;
		Instance->Path = Directory + Name;
		if(!Instance->Path.EndsWith(TEXT("/")))
		{
			Instance->Path += TEXT("/");
		}
		Instance->bIsRoot = false;
		return Instance;
	}

	ULowEntryFileManagerDirectory* ULowEntryFileManagerDirectory::Create(const FString& Path)
	{
		FString PathPart;
		FString NamePart;
		ULowEntryFileManagerLibrary::SplitPath(Path, PathPart, NamePart);
		if((PathPart.Len() <= 0) && (NamePart.Len() <= 0))
		{
			return ULowEntryFileManagerDirectory::CreateRoot();
		}
		return ULowEntryFileManagerDirectory::Create(PathPart, NamePart);
	}
// init <<


FString ULowEntryFileManagerDirectory::GetPath() const
{
	return Path;
}

FString ULowEntryFileManagerDirectory::GetAbsolutePath() const
{
	return ULowEntryFileManagerLibrary::RelativeToAbsolutePath(Path);
}

FString ULowEntryFileManagerDirectory::GetName() const
{
	return Name;
}

bool ULowEntryFileManagerDirectory::IsRootBool()
{
	return bIsRoot;
}

void ULowEntryFileManagerDirectory::IsRoot(ELowEntryFileManagerYesNo& Branch)
{
	Branch = ELowEntryFileManagerYesNoByBoolean(bIsRoot);
}


TArray<ULowEntryFileManagerFile*> ULowEntryFileManagerDirectory::GetFiles()
{
	FString Path = GetPath();
	if(Path.StartsWith(TEXT("Computer:")))
	{
		Path = TEXT("");
	}
	TArray<FString> FileNames = ULowEntryFileManagerLibrary::GetFileNames(GetPath());
	TArray<ULowEntryFileManagerFile*> Files;
	for(FString FileName : FileNames)
	{
		Files.Add(ULowEntryFileManagerFile::Create(Path, FileName));
	}
	return Files;
}

TArray<ULowEntryFileManagerDirectory*> ULowEntryFileManagerDirectory::GetDirectories()
{
	FString Path = GetPath();
	if(Path.StartsWith(TEXT("Computer:")))
	{
		Path = TEXT("");
	}
	TArray<FString> DirectoryNames = ULowEntryFileManagerLibrary::GetDirectoryNames(GetPath());
	TArray<ULowEntryFileManagerDirectory*> Directories;
	for(FString DirectoryName : DirectoryNames)
	{
		Directories.Add(ULowEntryFileManagerDirectory::Create(Path, DirectoryName));
	}
	return Directories;
}


ULowEntryFileManagerFile* ULowEntryFileManagerDirectory::GetFile(const FString& File)
{
	if(File.Len() <= 0)
	{
		return nullptr;
	}
	FString Path = GetPath();
	if(Path.StartsWith(TEXT("Computer:")))
	{
		Path = TEXT("");
	}
	return ULowEntryFileManagerFile::Create(Path, File);
}

ULowEntryFileManagerDirectory* ULowEntryFileManagerDirectory::GetDirectory(const FString& Directory_)
{
	if(Directory_.Len() <= 0)
	{
		return nullptr;
	}
	FString Path = GetPath();
	if(Path.StartsWith(TEXT("Computer:")))
	{
		Path = TEXT("");
	}
	return ULowEntryFileManagerDirectory::Create(Path, Directory_);
}


ULowEntryFileManagerDirectory* ULowEntryFileManagerDirectory::GetParentDirectory()
{
	if(bIsRoot)
	{
		return nullptr;
	}
	if(ULowEntryFileManagerLibrary::IsDiskPath(GetPath()))
	{
		return ULowEntryFileManagerLibrary::GetAbsoluteRoot();
	}
	return ULowEntryFileManagerLibrary::GetDirectory(Directory);
}


bool ULowEntryFileManagerDirectory::ExistsBool()
{
	return ULowEntryFileManagerLibrary::DirectoryExistsBool(GetPath());
}

void ULowEntryFileManagerDirectory::Exists(ELowEntryFileManagerYesNo& Branch)
{
	ULowEntryFileManagerLibrary::DirectoryExists(GetPath(), Branch);
}

void ULowEntryFileManagerDirectory::Create()
{
	if(!bIsRoot)
	{
		ULowEntryFileManagerLibrary::CreateNewDirectory(GetPath());
	}
}

void ULowEntryFileManagerDirectory::Delete()
{
	if(!bIsRoot)
	{
		ULowEntryFileManagerLibrary::DeleteDirectory(GetPath());
	}
}


bool ULowEntryFileManagerDirectory::IsEmptyBool()
{
	return ULowEntryFileManagerLibrary::IsDirectoryEmptyBool(GetPath());
}

void ULowEntryFileManagerDirectory::IsEmpty(ELowEntryFileManagerYesNo& Branch)
{
	ULowEntryFileManagerLibrary::IsDirectoryEmpty(GetPath(), Branch);
}

void ULowEntryFileManagerDirectory::Clear()
{
	if(!bIsRoot)
	{
		ULowEntryFileManagerLibrary::ClearDirectory(GetPath());
	}
}


void ULowEntryFileManagerDirectory::CopyTo(ULowEntryFileManagerDirectory* NewDirectory, const bool OverrideExistingFiles)
{
	if(!bIsRoot && (NewDirectory != nullptr))
	{
		ULowEntryFileManagerLibrary::CopyDirectory(GetPath(), NewDirectory->GetPath(), OverrideExistingFiles);
	}
}

void ULowEntryFileManagerDirectory::MoveTo(ULowEntryFileManagerDirectory* NewDirectory, const bool OverrideExistingFiles)
{
	if(!bIsRoot && (NewDirectory != nullptr))
	{
		ULowEntryFileManagerLibrary::MoveDirectory(GetPath(), NewDirectory->GetPath(), OverrideExistingFiles);
	}
}
