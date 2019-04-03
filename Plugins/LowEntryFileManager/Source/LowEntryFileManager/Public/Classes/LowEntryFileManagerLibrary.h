// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"

#include "ELowEntryFileManagerYesNo.h"

#include "LowEntryFileManagerLibrary.generated.h"


class ULowEntryFileManagerDirectory;
class ULowEntryFileManagerFile;


UCLASS()
class LOWENTRYFILEMANAGER_API ULowEntryFileManagerLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()



public:
	/**
	* Returns the directory pointing to the root of UE4's file system.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Static", Meta = (DisplayName = "Get Root"))
		static ULowEntryFileManagerDirectory* GetRoot();

	/**
	* Returns the directory pointing to the root of systems file system (so "/" for Unix and Mac and such, and "Computer:/" for Windows).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Static", Meta = (DisplayName = "Get Absolute Root"))
		static ULowEntryFileManagerDirectory* GetAbsoluteRoot();

	/**
	* Returns the directory pointing to the given Path, the given Path can be relative, it will be relative to the root of UE4's file system then.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Static", Meta = (DisplayName = "Get Directory"))
		static ULowEntryFileManagerDirectory* GetDirectory(const FString& Path);

	/**
	* Returns the disks of the filesystem (like "C:/", "D:/", etc) (only works for systems that have disks like that, such as Windows devices)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Static", Meta = (DisplayName = "Get Disks", Keywords = "harddrives"))
		static TArray<ULowEntryFileManagerDirectory*> GetDisks();



public:
	/**
	* Returns a path of a certain file or directory (internal UE4 function).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Get Project Dir Path"))
		static FString GetGameDirPath();

	/**
	* Returns a path of a certain file or directory (internal UE4 function).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Get Engine Dir Path"))
		static FString GetEngineDirPath();

	/**
	* Returns a path of a certain file or directory (internal UE4 function).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Get Root Dir Path"))
		static FString GetRootDirPath();
	
	/**
	* Returns a path of a certain file or directory (internal UE4 function).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Get Cloud Dir Path"))
		static FString GetCloudDirPath();
	
	/**
	* Returns a path of a certain file or directory (internal UE4 function).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Get Project Persistant Download Dir Path"))
		static FString GetGamePersistentDownloadDirPath();
	
	/**
	* Returns a path of a certain file or directory (internal UE4 function).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Get Project Saved Dir Path"))
		static FString GetGameSavedDirPath();
	
	/**
	* Returns a path of a certain file or directory (internal UE4 function).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Get Engine Saved Dir Path"))
		static FString GetEngineSavedDirPath();
	
	/**
	* Returns a path of a certain file or directory (internal UE4 function).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Get Project User Dir Path"))
		static FString GetGameUserDirPath();
	
	/**
	* Returns a path of a certain file or directory (internal UE4 function).
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Get Project File Path"))
		static FString GetProjectFilePath();



	/**
	* Returns the disk paths of the filesystem (like "C:/", "D:/", etc) (only works for systems that have disks like that, such as Windows devices)
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Get Disk Paths", Keywords = "harddrives"))
		static TArray<FString> GetDiskPaths();

	/**
	* Returns true if a disk path of the filesystem (like "C:/", "D:/", etc) exists, will only return true for systems that have disks like that, such as Windows devices.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Has Disk Paths (Boolean)", Keywords = "harddrives"))
		static bool HasDiskPathsBool();

	/**
	* Returns true if a file exists on the given path.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Utilities|Paths", Meta = (DisplayName = "Has Disk Paths", ExpandEnumAsExecs = "Branch"))
		static void HasDiskPaths(ELowEntryFileManagerYesNo& Branch);

	static bool IsDiskPath(const FString& Path);
	static bool StartsWithDiskPath(const FString& Path);



public:
	static FString RemoveCharactersExcept(const FString& String, const bool KeepLowercaseAZ, const bool KeepUppercaseAZ, const bool KeepNumbers, const FString& OtherCharactersToKeep);
	static FString ReplaceCharactersExcept(const FString& String, const FString& ReplacementCharacter, const bool KeepLowercaseAZ, const bool KeepUppercaseAZ, const bool KeepNumbers, const FString& OtherCharactersToKeep);

	/**
	* Removes all characters except a-z, A-Z, 0-9, ".", "-", "_", " "
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Purge", Meta = (DisplayName = "Remove invalid filename characters"))
		static FString RemoveInvalidFilenameCharacters(const FString& String);

	/**
	* Replaces all characters except a-z, A-Z, 0-9, ".", "-", "_", " "
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Purge", Meta = (DisplayName = "Replace invalid filename characters"))
		static FString ReplaceInvalidFilenameCharacters(const FString& String, const FString& ReplacementCharacter = TEXT("-"));

	/**
	* Removes all characters except a-z, A-Z, 0-9, ".", "-", "_", " ", "/", "\"
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Purge", Meta = (DisplayName = "Remove invalid path characters"))
		static FString RemoveInvalidPathCharacters(const FString& String);

	/**
	* Replaces all characters except a-z, A-Z, 0-9, ".", "-", "_", " ", "/", "\"
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Purge", Meta = (DisplayName = "Replace invalid path characters"))
		static FString ReplaceInvalidPathCharacters(const FString& String, const FString& ReplacementCharacter = TEXT("-"));

	/**
	* Replaces all "\" by "/"
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Utilities|Purge", Meta = (DisplayName = "Convert backslashes to slashes"))
		static FString ReplaceBackslashesBySlashes(const FString& String);



public:
	/**
	* Splits the path in 2 things: the path of the parent directory, and the name of the file or directory of the path.
	*
	* This blueprint is useful to get the parent path and the name of the given path.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|Other", Meta = (DisplayName = "Split Path"))
		static void SplitPath(const FString& Path, FString& PathPart, FString& NamePart);

	/**
	* Splits the (file)name in 2 things: the actual name, and the extension.
	* 
	* Will return an empty ExtensionPart string if there is no dot (".") in the given Name.
	* Multiple dots in the given Name will result in dots in the NamePart, since the split will only happen at the last dot.
	*
	* This blueprint is useful to get the actual name and the extension of a filename.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|Other", Meta = (DisplayName = "Split Name"))
		static void SplitName(const FString& Name, FString& NamePart, FString& ExtensionPart);

	/**
	* Returns an absolute path created by taking the given RelativePath and adding the root of the UE4's file system to it.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|Other", Meta = (DisplayName = "Relative To Absolute Path"))
		static FString RelativeToAbsolutePath(const FString& RelativePath);



	/**
	* Returns the paths of the files that exist in the given directory path.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Get Files"))
		static TArray<FString> GetFiles(const FString& Directory);

	/**
	* Returns the paths of the directories that exist in the given directory path.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Get Directories"))
		static TArray<FString> GetDirectories(const FString& Directory);



	/**
	* Returns the names of the files that exist in the given directory path.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Get File Names"))
		static TArray<FString> GetFileNames(const FString& Directory);

	/**
	* Returns the names of the directories that exist in the given directory path.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Get Directory Names"))
		static TArray<FString> GetDirectoryNames(const FString& Directory);



	/**
	* Returns true if a file exists on the given path.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Exists (File) (Boolean)"))
		static bool FileExistsBool(const FString& File);

	/**
	* Returns true if a file exists on the given path.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Exists (File)", ExpandEnumAsExecs = "Branch"))
		static void FileExists(const FString& File, ELowEntryFileManagerYesNo& Branch);

	/**
	* Returns true if a directory exists on the given path.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Exists (Directory) (Boolean)"))
		static bool DirectoryExistsBool(const FString& Directory);

	/**
	* Returns true if a directory exists on the given path.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Exists (Directory)", ExpandEnumAsExecs = "Branch"))
		static void DirectoryExists(const FString& Directory, ELowEntryFileManagerYesNo& Branch);



	/**
	* Creates a file if it doesn't exist yet.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Create (File)"))
		static void CreateNewFile(const FString& File);

	/**
	* Creates a directory if it doesn't exist yet.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Create (Directory)"))
		static void CreateNewDirectory(const FString& Directory);

	/**
	* Creates the parent directory of the given Path if it doesn't exist yet.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|Other", Meta = (DisplayName = "Create Parent Directory"))
		static void CreateParentDirectory(const FString& Path);



	/**
	* Deletes a file if it exists.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Delete (File)"))
		static void DeleteFile(const FString& File);

	/**
	* Deletes a directory if it exists.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Delete (Directory)"))
		static void DeleteDirectory(const FString& Directory);



	/**
	* Returns true if the file is empty or doesn't exist.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Is Empty (File) (Boolean)"))
		static bool IsFileEmptyBool(const FString& File);

	/**
	* Returns true if the file is empty or doesn't exist.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Is Empty (File)", ExpandEnumAsExecs = "Branch"))
		static void IsFileEmpty(const FString& File, ELowEntryFileManagerYesNo& Branch);

	/**
	* Returns true if the directory is empty or doesn't exist.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Is Empty (Directory) (Boolean)"))
		static bool IsDirectoryEmptyBool(const FString& Directory);

	/**
	* Returns true if the directory is empty or doesn't exist.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Is Empty (Directory)", ExpandEnumAsExecs = "Branch"))
		static void IsDirectoryEmpty(const FString& Directory, ELowEntryFileManagerYesNo& Branch);



	/**
	* Sets the data of the file to an empty byte array, which also causes the file to be created if it didn't exist yet, basically causing the file to be existing and empty.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Clear (File)"))
		static void ClearFile(const FString& File);

	/**
	* Removes the directory (and anything that is inside of it) and creates a new directory with the same name on the same location, basically causing the directory to be existing and empty.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Clear (Directory)"))
		static void ClearDirectory(const FString& Directory);



	/**
	* Copies the file, won't do anything if the given NewFile already exists.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Copy (File)", Keywords = "clone duplicate"))
		static void CopyFile(const FString& File, const FString& To);

	/**
	* Copies the directory, if the given NewDirectory already exists, the directory will merge with the existing directory.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Copy (Directory)", Keywords = "clone duplicate"))
		static void CopyDirectory(const FString& Directory, const FString& To, bool OverrideExistingFiles);



	/**
	* Moves/renames the file, won't do anything if the given NewFile already exists.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Move (File)", Keywords = "rename"))
		static void MoveFile(const FString& File, const FString& To);

	/**
	* Moves/renames the directory, if the given NewDirectory already exists, the directory will merge with the existing directory.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|Directory", Meta = (DisplayName = "Move (Directory)", Keywords = "rename"))
		static void MoveDirectory(const FString& Directory, const FString& To, bool OverrideExistingFiles);



	/**
	* Returns true if the file is read only.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Is Read Only (File) (Boolean)"))
		static bool IsFileReadOnlyBool(const FString& File);

	/**
	* Returns true if the file is read only.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Is Read Only (File)", ExpandEnumAsExecs = "Branch"))
		static void IsFileReadOnly(const FString& File, ELowEntryFileManagerYesNo& Branch);

	/**
	* Sets the file read only.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Set Read Only (File)"))
		static void SetFileReadOnly(const FString& File, const bool ReadOnly);



	/**
	* Executes the file and waits for it to fininsh, returns the output.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Execute (File)"))
		static void ExecuteFile(const FString& File, const FString& Parameters, bool& Success, int32& ReturnCode, FString& StdOut, FString& StdErr);

	/**
	* Executes the file as a separate process.
	* 
	* Hidden will cause the new process to not have a window or show up in the task bar.
	* Priority can be: -2 idle, -1 low, 0 normal, 1 high, 2 higher.
	* OptionalWorkingDirectory can be left empty to use the current work directory, otherwise an absolute path has to be given.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Execute Async (File)", AdvancedDisplay = "5"))
		static void ExecuteFileAsync(const FString& File, const FString& Parameters, bool& Success, int32& ProcessID, const bool Hidden = true, const int32 Priority = 0, const FString& OptionalWorkingDirectory = TEXT(""));



	/**
	* Returns the data of the file, returns an empty byte array if the file doesn't exist.
	*
	* Note: Can only open files of 2GB and smaller, will return an empty byte array if it is bigger than 2GB.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Get Data (File)"))
		static TArray<uint8> GetFileData(const FString& File);

	/**
	* Sets the data of the file, creates the file if it doesn't exist yet.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Set Data (File)"))
		static void SetFileData(const FString& File, const TArray<uint8>& Data);

	/**
	* Appends data to the end of the file, creates the file if it doesn't exist yet.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Append Data (File)"))
		static void AppendFileData(const FString& File, const TArray<uint8>& Data);

	/**
	* Returns the number of bytes the file has, returns 0 if the file does not exist.
	*
	* Note: Can only return sizes of 2GB and smaller, will return 0 if it is bigger than 2GB.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Get Size (File)"))
		static int32 GetFileSize(const FString& File);



	/**
	* Returns the timestamp of the last edit of the file.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Get Timestamp (File)"))
		static FDateTime GetFileTimestamp(const FString& File);

	/**
	* Sets the timestamp of the last edit of the file.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Set Timestamp (File)"))
		static void SetFileTimestamp(const FString& File, const FDateTime& Timestamp);



	/**
	* Returns the timestamp of the last access of the file.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|Low Level|File", Meta = (DisplayName = "Get Access Timestamp (File)"))
		static FDateTime GetFileAccessTimestamp(const FString& File);
};
