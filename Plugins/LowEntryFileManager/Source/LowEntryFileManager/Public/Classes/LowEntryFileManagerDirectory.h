// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "ELowEntryFileManagerYesNo.h"

#include "LowEntryFileManagerDirectory.generated.h"


class ULowEntryFileManagerDirectory;
class ULowEntryFileManagerFile;


UCLASS(BlueprintType)
class LOWENTRYFILEMANAGER_API ULowEntryFileManagerDirectory : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryFileManagerDirectory* CreateRoot();
	static ULowEntryFileManagerDirectory* CreateAbsoluteRoot();
	static ULowEntryFileManagerDirectory* Create(const FString& Directory, const FString& Name);
	static ULowEntryFileManagerDirectory* Create(const FString& Path);


public:
	UPROPERTY()
	FString Directory;
	UPROPERTY()
	FString Name;
	UPROPERTY()
	FString Path;
	UPROPERTY()
	bool bIsRoot = false;


	/**
	* Returns the path of this directory.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Get Path (Directory)"))
		FString GetPath() const;

	/**
	* Returns the absolute path of this directory.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Get Absolute Path (Directory)"))
		FString GetAbsolutePath() const;

	/**
	* Returns the name of this directory.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Get Name (Directory)"))
		FString GetName() const;

	/**
	* Returns true if this directory is the root of UE4's file system.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Is Root (Directory) (Boolean)"))
		bool IsRootBool();

	/**
	* Returns true if this directory is the root of UE4's file system.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Is Root (Directory)", ExpandEnumAsExecs = "Branch"))
		void IsRoot(ELowEntryFileManagerYesNo& Branch);


	/**
	* Returns an array of files that exist in this directory.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Get Files"))
		TArray<ULowEntryFileManagerFile*> GetFiles();
	
	/**
	* Returns an array of directories that exist in this directory.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Get Directories"))
		TArray<ULowEntryFileManagerDirectory*> GetDirectories();


	/**
	* Returns a file in this directory, the file may or may not exist.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Get File"))
		ULowEntryFileManagerFile* GetFile(const FString& File);

	/**
	* Returns a directory in this directory, the directory may or may not exist.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Get Directory"))
		ULowEntryFileManagerDirectory* GetDirectory(const FString& Directory_);


	/**
	* Returns the directory this directory is inside in.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Get Parent Directory (Directory)"))
		ULowEntryFileManagerDirectory* GetParentDirectory();


	/**
	* Returns true if this directory exists.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Exists (Directory) (Boolean)"))
		bool ExistsBool();

	/**
	* Returns true if this directory exists.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Exists (Directory)", ExpandEnumAsExecs = "Branch"))
		void Exists(ELowEntryFileManagerYesNo& Branch);

	/**
	* Creates this directory (and any parent directories) if it doesn't exist yet.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Create (Directory)"))
		void Create();

	/**
	* Deletes this directory if it exists.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Delete (Directory)"))
		void Delete();


	/**
	* Returns true if this directory is empty or if it does not exist.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Is Empty (Directory) (Boolean)"))
		bool IsEmptyBool();

	/**
	* Returns true if this directory is empty or if it does not exist.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Is Empty (Directory)", ExpandEnumAsExecs = "Branch"))
		void IsEmpty(ELowEntryFileManagerYesNo& Branch);

	/**
	* Removes this directory (and anything that is inside of it) and creates a new directory with the same name on the same location, basically causing this directory to be existing and empty.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Clear (Directory)"))
		void Clear();


	/**
	* Copies this directory, if the given NewDirectory already exists, this directory will merge with the existing directory.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Copy (Directory)", Keywords = "clone duplicate"))
		void CopyTo(ULowEntryFileManagerDirectory* NewDirectory, const bool OverrideExistingFiles);

	/**
	* Moves/renames this directory, if the given NewDirectory already exists, this directory will merge with the existing directory.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|Directory", Meta = (DisplayName = "Move (Directory)", Keywords = "rename"))
		void MoveTo(ULowEntryFileManagerDirectory* NewDirectory, const bool OverrideExistingFiles);
};
