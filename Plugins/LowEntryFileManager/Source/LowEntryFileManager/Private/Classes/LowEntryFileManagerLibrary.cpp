// Copyright Low Entry. All Rights Reserved.

#include "LowEntryFileManagerLibrary.h"
#include "LowEntryFileManagerDirectory.h"
#include "LowEntryFileManagerFile.h"

#include "Misc/Paths.h"
#include "GenericPlatform/GenericPlatformFile.h"



// init >>
	ULowEntryFileManagerLibrary::ULowEntryFileManagerLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
	}
// init <<



ULowEntryFileManagerDirectory* ULowEntryFileManagerLibrary::GetRoot()
{
	return ULowEntryFileManagerDirectory::CreateRoot();
}

ULowEntryFileManagerDirectory* ULowEntryFileManagerLibrary::GetAbsoluteRoot()
{
	return ULowEntryFileManagerDirectory::CreateAbsoluteRoot();
}

ULowEntryFileManagerDirectory* ULowEntryFileManagerLibrary::GetDirectory(const FString& Path)
{
	return ULowEntryFileManagerDirectory::Create(Path);
}

TArray<ULowEntryFileManagerDirectory*> ULowEntryFileManagerLibrary::GetDisks()
{
	TArray<ULowEntryFileManagerDirectory*> Disks;
	TArray<FString> DiskPaths = ULowEntryFileManagerLibrary::GetDiskPaths();
	for(FString DiskPath : DiskPaths)
	{
		Disks.Add(ULowEntryFileManagerDirectory::Create(DiskPath));
	}
	return Disks;
}



FString ULowEntryFileManagerLibrary::GetGameDirPath()
{
	return FPaths::ProjectDir();
}

FString ULowEntryFileManagerLibrary::GetRootDirPath()
{
	return FPaths::RootDir();
}

FString ULowEntryFileManagerLibrary::GetCloudDirPath()
{
	return FPaths::CloudDir();
}

FString ULowEntryFileManagerLibrary::GetGamePersistentDownloadDirPath()
{
	return FPaths::ProjectPersistentDownloadDir();
}

FString ULowEntryFileManagerLibrary::GetGameSavedDirPath()
{
	return FPaths::ProjectSavedDir();
}

FString ULowEntryFileManagerLibrary::GetEngineSavedDirPath()
{
	return FPaths::EngineSavedDir();
}

FString ULowEntryFileManagerLibrary::GetEngineDirPath()
{
	return FPaths::EngineDir();
}

FString ULowEntryFileManagerLibrary::GetGameUserDirPath()
{
	return FPaths::ProjectUserDir();
}

FString ULowEntryFileManagerLibrary::GetProjectFilePath()
{
	return FPaths::GetProjectFilePath();
}



TArray<FString> ULowEntryFileManagerLibrary::GetDiskPaths()
{
	TArray<FString> Result;
	FString DriveLetters = TEXT("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	FString Drive = TEXT("A:/");
	for(int32 i = 0; i < DriveLetters.Len(); i++)
	{
		Drive[0] = DriveLetters[i];
		if(ULowEntryFileManagerLibrary::DirectoryExistsBool(Drive))
		{
			Result.Add(Drive);
		}
	}
	return Result;
}

bool ULowEntryFileManagerLibrary::HasDiskPathsBool()
{
	FString DriveLetters = TEXT("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	FString Drive = TEXT("A:/");
	for(int32 i = 0; i < DriveLetters.Len(); i++)
	{
		Drive[0] = DriveLetters[i];
		if(ULowEntryFileManagerLibrary::DirectoryExistsBool(Drive))
		{
			return true;
		}
	}
	return false;
}

void ULowEntryFileManagerLibrary::HasDiskPaths(ELowEntryFileManagerYesNo& Branch)
{
	Branch = ELowEntryFileManagerYesNoByBoolean(ULowEntryFileManagerLibrary::HasDiskPathsBool());
}

bool ULowEntryFileManagerLibrary::IsDiskPath(const FString& Path)
{
	FString DriveLetters = TEXT("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	FString Drive1 = TEXT("A:");
	FString Drive2 = TEXT("A:/");
	for(int32 i = 0; i < DriveLetters.Len(); i++)
	{
		Drive1[0] = DriveLetters[i];
		Drive2[0] = DriveLetters[i];
		if((Path == Drive1) || (Path == Drive2))
		{
			return true;
		}
	}
	return false;
}

bool ULowEntryFileManagerLibrary::StartsWithDiskPath(const FString& Path)
{
	FString DriveLetters = TEXT("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	FString Drive = TEXT("A:");
	for(int32 i = 0; i < DriveLetters.Len(); i++)
	{
		Drive[0] = DriveLetters[i];
		if(Path.StartsWith(Drive))
		{
			return true;
		}
	}
	return false;
}



FString ULowEntryFileManagerLibrary::RemoveCharactersExcept(const FString& String, const bool KeepLowercaseAZ, const bool KeepUppercaseAZ, const bool KeepNumbers, const FString& OtherCharactersToKeep)
{
	if(String.Len() <= 0)
	{
		return String;
	}

	FString NewString;
	NewString.Reserve(String.Len());

	for(TCHAR Char : String)
	{
		if(KeepLowercaseAZ && (Char >= 'a') && (Char <= 'z'))
		{
			NewString.AppendChar(Char);
			continue;
		}
		if(KeepUppercaseAZ && (Char >= 'A') && (Char <= 'Z'))
		{
			NewString.AppendChar(Char);
			continue;
		}
		if(KeepNumbers && (Char >= '0') && (Char <= '9'))
		{
			NewString.AppendChar(Char);
			continue;
		}

		for(TCHAR KeepChar : OtherCharactersToKeep)
		{
			if(Char == KeepChar)
			{
				NewString.AppendChar(Char);
				break;
			}
		}
	}

	return NewString;
}

FString ULowEntryFileManagerLibrary::ReplaceCharactersExcept(const FString& String, const FString& ReplacementCharacter, const bool KeepLowercaseAZ, const bool KeepUppercaseAZ, const bool KeepNumbers, const FString& OtherCharactersToKeep)
{
	if(String.Len() <= 0)
	{
		return String;
	}

	FString NewString;
	NewString.Reserve(FMath::Max(String.Len(), (ReplacementCharacter.Len() * String.Len())));

	for(TCHAR Char : String)
	{
		if(KeepLowercaseAZ && (Char >= 'a') && (Char <= 'z'))
		{
			NewString.AppendChar(Char);
			continue;
		}
		if(KeepUppercaseAZ && (Char >= 'A') && (Char <= 'Z'))
		{
			NewString.AppendChar(Char);
			continue;
		}
		if(KeepNumbers && (Char >= '0') && (Char <= '9'))
		{
			NewString.AppendChar(Char);
			continue;
		}

		bool Keep = false;
		for(TCHAR KeepChar : OtherCharactersToKeep)
		{
			if(Char == KeepChar)
			{
				NewString.AppendChar(Char);
				Keep = true;
				break;
			}
		}
		if(Keep)
		{
			continue;
		}

		NewString.Append(ReplacementCharacter);
	}

	return NewString;
}

FString ULowEntryFileManagerLibrary::RemoveInvalidFilenameCharacters(const FString& String)
{
	return ULowEntryFileManagerLibrary::RemoveCharactersExcept(String, true, true, true, TEXT(".-_ "));
}

FString ULowEntryFileManagerLibrary::ReplaceInvalidFilenameCharacters(const FString& String, const FString& ReplacementCharacter)
{
	return ULowEntryFileManagerLibrary::ReplaceCharactersExcept(String, ReplacementCharacter, true, true, true, TEXT(".-_ "));
}

FString ULowEntryFileManagerLibrary::RemoveInvalidPathCharacters(const FString& String)
{
	return ULowEntryFileManagerLibrary::RemoveCharactersExcept(String, true, true, true, TEXT(".-_ /\\"));
}

FString ULowEntryFileManagerLibrary::ReplaceInvalidPathCharacters(const FString& String, const FString& ReplacementCharacter)
{
	return ULowEntryFileManagerLibrary::ReplaceCharactersExcept(String, ReplacementCharacter, true, true, true, TEXT(".-_ /\\"));
}

FString ULowEntryFileManagerLibrary::ReplaceBackslashesBySlashes(const FString& String)
{
	return String.Replace(TEXT("\\"), TEXT("/"));
}



void ULowEntryFileManagerLibrary::SplitPath(const FString& Path, FString& PathPart, FString& NamePart)
{
	FString LocalPath = Path;
	FPaths::NormalizeDirectoryName(LocalPath);
	if(LocalPath.Len() <= 0)
	{
		PathPart = TEXT("");
		NamePart = TEXT("");
	}
	bool Split = LocalPath.Split(TEXT("/"), &PathPart, &NamePart, ESearchCase::CaseSensitive, ESearchDir::Type::FromEnd);
	if(!Split)
	{
		PathPart = TEXT("");
		NamePart = LocalPath;
	}
	if(Path.Len() > 0)
	{
		PathPart += TEXT("/");
	}
}

void ULowEntryFileManagerLibrary::SplitName(const FString& Name, FString& NamePart, FString& ExtensionPart)
{
	if(Name.Len() <= 0)
	{
		NamePart = TEXT("");
		ExtensionPart = TEXT("");
	}
	bool Split = Name.Split(TEXT("."), &NamePart, &ExtensionPart, ESearchCase::CaseSensitive, ESearchDir::Type::FromEnd);
	if(!Split)
	{
		NamePart = Name;
		ExtensionPart = TEXT("");
	}
}

FString ULowEntryFileManagerLibrary::RelativeToAbsolutePath(const FString& RelativePath)
{
	if(RelativePath.StartsWith(TEXT("/")) || RelativePath.StartsWith(TEXT("Computer:")) || ULowEntryFileManagerLibrary::StartsWithDiskPath(RelativePath))
	{
		return RelativePath;
	}
	return FPlatformFileManager::Get().GetPlatformFile().ConvertToAbsolutePathForExternalAppForWrite(*RelativePath);
}



TArray<FString> ULowEntryFileManagerLibrary::GetFiles(const FString& Directory)
{
	if((Directory == TEXT("Computer:/")) || (Directory == TEXT("Computer:")))
	{
		return TArray<FString>();
	}
	class FLowEntryFileManagerGetFilesVisitor : public IPlatformFile::FDirectoryVisitor
	{
	public:
		TArray<FString> Files;
		FLowEntryFileManagerGetFilesVisitor()
		{
		}
		virtual bool Visit(const TCHAR* FileName, bool bIsDirectory)
		{
			if(!bIsDirectory)
			{
				Files.Add(FileName);
			}
			return true;
		}
	};
	FLowEntryFileManagerGetFilesVisitor GetFilesVisitor;
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*Directory, GetFilesVisitor);
	return GetFilesVisitor.Files;
}

TArray<FString> ULowEntryFileManagerLibrary::GetDirectories(const FString& Directory)
{
	if((Directory == TEXT("Computer:/")) || (Directory == TEXT("Computer:")))
	{
		return ULowEntryFileManagerLibrary::GetDiskPaths();
	}
	class FLowEntryFileManagerGetDirectoriesVisitor : public IPlatformFile::FDirectoryVisitor
	{
	public:
		TArray<FString> Directories;
		FLowEntryFileManagerGetDirectoriesVisitor()
		{
		}
		virtual bool Visit(const TCHAR* FileName, bool bIsDirectory)
		{
			if(bIsDirectory)
			{
				Directories.Add(FileName);
			}
			return true;
		}
	};
	FLowEntryFileManagerGetDirectoriesVisitor GetFoldersVisitor;
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*Directory, GetFoldersVisitor);
	return GetFoldersVisitor.Directories;
}



TArray<FString> ULowEntryFileManagerLibrary::GetFileNames(const FString& Directory)
{
	if((Directory == TEXT("Computer:/")) || (Directory == TEXT("Computer:")))
	{
		return TArray<FString>();
	}
	class FLowEntryFileManagerGetFilesVisitor : public IPlatformFile::FDirectoryVisitor
	{
	public:
		TArray<FString> Files;
		FLowEntryFileManagerGetFilesVisitor()
		{
		}
		virtual bool Visit(const TCHAR* FileName, bool bIsDirectory)
		{
			if(!bIsDirectory)
			{
				FString Path;
				FString Name;
				ULowEntryFileManagerLibrary::SplitPath(FileName, Path, Name);
				Files.Add(Name);
			}
			return true;
		}
	};
	FLowEntryFileManagerGetFilesVisitor GetFilesVisitor;
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*Directory, GetFilesVisitor);
	return GetFilesVisitor.Files;
}

TArray<FString> ULowEntryFileManagerLibrary::GetDirectoryNames(const FString& Directory)
{
	if((Directory == TEXT("Computer:/")) || (Directory == TEXT("Computer:")))
	{
		return ULowEntryFileManagerLibrary::GetDiskPaths();
	}
	class FLowEntryFileManagerGetDirectoriesVisitor : public IPlatformFile::FDirectoryVisitor
	{
	public:
		TArray<FString> Directories;
		FLowEntryFileManagerGetDirectoriesVisitor()
		{
		}
		virtual bool Visit(const TCHAR* FileName, bool bIsDirectory)
		{
			if(bIsDirectory)
			{
				FString Path;
				FString Name;
				ULowEntryFileManagerLibrary::SplitPath(FileName, Path, Name);
				Directories.Add(Name);
			}
			return true;
		}
	};
	FLowEntryFileManagerGetDirectoriesVisitor GetFoldersVisitor;
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*Directory, GetFoldersVisitor);
	return GetFoldersVisitor.Directories;
}



bool ULowEntryFileManagerLibrary::FileExistsBool(const FString& File)
{
	return FPlatformFileManager::Get().GetPlatformFile().FileExists(*File);
}

void ULowEntryFileManagerLibrary::FileExists(const FString& File, ELowEntryFileManagerYesNo& Branch)
{
	Branch = ELowEntryFileManagerYesNoByBoolean(ULowEntryFileManagerLibrary::FileExistsBool(File));
}

bool ULowEntryFileManagerLibrary::DirectoryExistsBool(const FString& Directory)
{
	if(Directory.StartsWith(TEXT("Computer:")))
	{
		return true;
	}
	return FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*Directory);
}

void ULowEntryFileManagerLibrary::DirectoryExists(const FString& Directory, ELowEntryFileManagerYesNo& Branch)
{
	Branch = ELowEntryFileManagerYesNoByBoolean(ULowEntryFileManagerLibrary::DirectoryExistsBool(Directory));
}



void ULowEntryFileManagerLibrary::CreateNewFile(const FString& File)
{
	if(FPlatformFileManager::Get().GetPlatformFile().FileExists(*File))
	{
		return;
	}
	ULowEntryFileManagerLibrary::CreateParentDirectory(File);
	IFileHandle* FileHandle = FPlatformFileManager::Get().GetPlatformFile().OpenWrite(*File);
	if(FileHandle != nullptr)
	{
		delete FileHandle;
	}
}

void ULowEntryFileManagerLibrary::CreateNewDirectory(const FString& Directory)
{
	FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*Directory);
}

void ULowEntryFileManagerLibrary::CreateParentDirectory(const FString& Path)
{
	if(FPlatformFileManager::Get().GetPlatformFile().FileExists(*Path) || FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*Path))
	{
		return;
	}
	FString PathPart;
	FString NamePart;
	ULowEntryFileManagerLibrary::SplitPath(Path, PathPart, NamePart);
	if(FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*PathPart))
	{
		return;
	}
	FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*PathPart);
}



void ULowEntryFileManagerLibrary::DeleteFile(const FString& File)
{
	FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*File);
}

void ULowEntryFileManagerLibrary::DeleteDirectory(const FString& Directory)
{
	FPlatformFileManager::Get().GetPlatformFile().DeleteDirectoryRecursively(*Directory);
}



bool ULowEntryFileManagerLibrary::IsFileEmptyBool(const FString& File)
{
	return (FPlatformFileManager::Get().GetPlatformFile().FileSize(*File) <= 0);
}

void ULowEntryFileManagerLibrary::IsFileEmpty(const FString& File, ELowEntryFileManagerYesNo& Branch)
{
	Branch = ELowEntryFileManagerYesNoByBoolean(ULowEntryFileManagerLibrary::IsFileEmptyBool(File));
}

bool ULowEntryFileManagerLibrary::IsDirectoryEmptyBool(const FString& Directory)
{
	if(Directory.StartsWith(TEXT("Computer:")))
	{
		return ULowEntryFileManagerLibrary::HasDiskPathsBool();
	}
	class FLowEntryFileManagerCheckDirectoryContentVisitor : public IPlatformFile::FDirectoryVisitor
	{
	public:
		bool FoundAnything = false;
		FLowEntryFileManagerCheckDirectoryContentVisitor()
		{
		}
		virtual bool Visit(const TCHAR* FileName, bool bIsDirectory)
		{
			FoundAnything = true;
			return false;
		}
	};
	FLowEntryFileManagerCheckDirectoryContentVisitor CheckDirectoryContentVisitor;
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*Directory, CheckDirectoryContentVisitor);
	return CheckDirectoryContentVisitor.FoundAnything;
}

void ULowEntryFileManagerLibrary::IsDirectoryEmpty(const FString& Directory, ELowEntryFileManagerYesNo& Branch)
{
	Branch = ELowEntryFileManagerYesNoByBoolean(ULowEntryFileManagerLibrary::IsDirectoryEmptyBool(Directory));
}



void ULowEntryFileManagerLibrary::ClearFile(const FString& File)
{
	ULowEntryFileManagerLibrary::CreateParentDirectory(File);
	IFileHandle* FileHandle = FPlatformFileManager::Get().GetPlatformFile().OpenWrite(*File);
	if(FileHandle != nullptr)
	{
		delete FileHandle;
	}
}

void ULowEntryFileManagerLibrary::ClearDirectory(const FString& Directory)
{
	ULowEntryFileManagerLibrary::DeleteDirectory(Directory);
	ULowEntryFileManagerLibrary::CreateNewDirectory(Directory);
}



void ULowEntryFileManagerLibrary::CopyFile(const FString& File, const FString& To)
{
	ULowEntryFileManagerLibrary::CreateParentDirectory(To);
	FPlatformFileManager::Get().GetPlatformFile().CopyFile(*To, *File);
}

void ULowEntryFileManagerLibrary::CopyDirectory(const FString& Directory, const FString& To, bool OverrideExistingFiles)
{
	ULowEntryFileManagerLibrary::CreateParentDirectory(To);
	FPlatformFileManager::Get().GetPlatformFile().CopyDirectoryTree(*To, *Directory, OverrideExistingFiles);
}



void ULowEntryFileManagerLibrary::MoveFile(const FString& File, const FString& To)
{
	ULowEntryFileManagerLibrary::CreateParentDirectory(To);
	FPlatformFileManager::Get().GetPlatformFile().MoveFile(*To, *File);
}

void ULowEntryFileManagerLibrary::MoveDirectory(const FString& Directory, const FString& To, bool OverrideExistingFiles)
{
	ULowEntryFileManagerLibrary::CopyDirectory(Directory, To, OverrideExistingFiles);
	ULowEntryFileManagerLibrary::DeleteDirectory(Directory);
}



bool ULowEntryFileManagerLibrary::IsFileReadOnlyBool(const FString& File)
{
	return FPlatformFileManager::Get().GetPlatformFile().IsReadOnly(*File);
}

void ULowEntryFileManagerLibrary::IsFileReadOnly(const FString& File, ELowEntryFileManagerYesNo& Branch)
{
	Branch = ELowEntryFileManagerYesNoByBoolean(ULowEntryFileManagerLibrary::IsFileReadOnlyBool(File));
}

void ULowEntryFileManagerLibrary::SetFileReadOnly(const FString& File, const bool ReadOnly)
{
	FPlatformFileManager::Get().GetPlatformFile().SetReadOnly(*File, ReadOnly);
}



void ULowEntryFileManagerLibrary::ExecuteFile(const FString& File, const FString& Parameters, bool& Success, int32& ReturnCode, FString& StdOut, FString& StdErr)
{
	Success = false;
	ReturnCode = 0;
	StdOut = TEXT("");
	StdErr = TEXT("");
	Success = FPlatformProcess::ExecProcess(*File, *Parameters, &ReturnCode, &StdOut, &StdErr);
}

void ULowEntryFileManagerLibrary::ExecuteFileAsync(const FString& File, const FString& Parameters, bool& Success, int32& ProcessID, const bool Hidden, const int32 Priority, const FString& OptionalWorkingDirectory)
{
	Success = false;
	ProcessID = 0;
	Success = FPlatformProcess::CreateProc(*File, *Parameters, !Hidden, false, Hidden, (uint32_t*)&ProcessID, Priority, (OptionalWorkingDirectory.TrimStartAndEnd().IsEmpty() ? nullptr : *OptionalWorkingDirectory), nullptr, nullptr).IsValid();
}



TArray<uint8> ULowEntryFileManagerLibrary::GetFileData(const FString& File)
{
	TArray<uint8> Data;
	IFileHandle* FileHandle = FPlatformFileManager::Get().GetPlatformFile().OpenRead(*File);
	if(FileHandle != nullptr)
	{
		int64 FileSize = FileHandle->Size();
		if((FileSize > 0) && (FileSize <= 0x7FFFFFFF))
		{
			int32 ByteSize = FileSize;
			uint8* Bytes = new uint8[ByteSize];
			FileHandle->Read(Bytes, ByteSize);
			Data.Append(Bytes, ByteSize);
			delete [] Bytes;
		}
		delete FileHandle;
	}
	return Data;
}

void ULowEntryFileManagerLibrary::SetFileData(const FString& File, const TArray<uint8>& Data)
{
	ULowEntryFileManagerLibrary::CreateParentDirectory(File);
	IFileHandle* FileHandle = FPlatformFileManager::Get().GetPlatformFile().OpenWrite(*File);
	if(FileHandle != nullptr)
	{
		if(Data.Num() > 0)
		{
			FileHandle->Write(Data.GetData(), Data.Num());
		}
		delete FileHandle;
	}
}

void ULowEntryFileManagerLibrary::AppendFileData(const FString& File, const TArray<uint8>& Data)
{
	ULowEntryFileManagerLibrary::CreateParentDirectory(File);
	IFileHandle* FileHandle = FPlatformFileManager::Get().GetPlatformFile().OpenWrite(*File, true);
	if(FileHandle != nullptr)
	{
		if(Data.Num() > 0)
		{
			FileHandle->SeekFromEnd();
			FileHandle->Write(Data.GetData(), Data.Num());
		}
		delete FileHandle;
	}
}

int32 ULowEntryFileManagerLibrary::GetFileSize(const FString& File)
{
	int32 Size = FPlatformFileManager::Get().GetPlatformFile().FileSize(*File);
	if(Size < 0)
	{
		Size = 0;
	}
	return Size;
}



FDateTime ULowEntryFileManagerLibrary::GetFileTimestamp(const FString& File)
{
	return FPlatformFileManager::Get().GetPlatformFile().GetTimeStamp(*File);
}

void ULowEntryFileManagerLibrary::SetFileTimestamp(const FString& File, const FDateTime& Timestamp)
{
	FPlatformFileManager::Get().GetPlatformFile().SetTimeStamp(*File, Timestamp);
}



FDateTime ULowEntryFileManagerLibrary::GetFileAccessTimestamp(const FString& File)
{
	return FPlatformFileManager::Get().GetPlatformFile().GetAccessTimeStamp(*File);
}
