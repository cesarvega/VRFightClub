// Copyright Low Entry. All Rights Reserved.

#pragma once


#include "CoreMinimal.h"
#include "CoreUObject.h"

#include "ELowEntryFileManagerYesNo.h"

#include "LowEntryFileManagerFile.generated.h"


class ULowEntryFileManagerDirectory;
class ULowEntryFileManagerFile;


UCLASS(BlueprintType)
class LOWENTRYFILEMANAGER_API ULowEntryFileManagerFile : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	static ULowEntryFileManagerFile* Create(const FString& Directory, const FString& Name);


public:
	UPROPERTY()
	FString Directory;
	UPROPERTY()
	FString Name;
	UPROPERTY()
	FString Path;


	/**
	* Returns the path of this file.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Get Path (File)"))
		FString GetPath() const;
	
	/**
	* Returns the absolute path of this file.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Get Absolute Path (File)"))
		FString GetAbsolutePath() const;

	/**
	* Returns the name (including the extension) of this file.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Get Name (File)"))
		FString GetName() const;

	/**
	* Returns the name (excluding the extension) of this file.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Get Name Without Extension (File)"))
		FString GetNameWithoutExtension() const;

	/**
	* Returns the extension of this file.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Get Extension (File)"))
		FString GetExtension() const;


	/**
	* Returns the directory this file is inside in.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Get Parent Directory (File)"))
		ULowEntryFileManagerDirectory* GetParentDirectory();


	/**
	* Returns true if this file exists.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Exists (File) (Boolean)"))
		bool ExistsBool();

	/**
	* Returns true if this file exists.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Exists (File)", ExpandEnumAsExecs = "Branch"))
		void Exists(ELowEntryFileManagerYesNo& Branch);

	/**
	* Creates this file (and any parent directories) if it doesn't exist yet.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Create (File)"))
		void Create();

	/**
	* Deletes this file if it exists.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Delete (File)"))
		void Delete();


	/**
	* Returns true if this file is empty or if it does not exist.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Is Empty (File) (Boolean)"))
		bool IsEmptyBool();

	/**
	* Returns true if this file is empty or if it does not exist.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Is Empty (File)", ExpandEnumAsExecs = "Branch"))
		void IsEmpty(ELowEntryFileManagerYesNo& Branch);

	/**
	* Sets the data of this file to an empty byte array, which also causes this file to be created if it didnt't exist yet, basically causing this file to be existing and empty.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Clear (File)"))
		void Clear();


	/**
	* Returns true if this file is read only.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Is Read Only (File) (Boolean)"))
		bool IsReadOnlyBool();

	/**
	* Returns true if this file is read only.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Is Read Only (File)", ExpandEnumAsExecs = "Branch"))
		void IsReadOnly(ELowEntryFileManagerYesNo& Branch);

	/**
	* Sets this file read only.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Set Read Only (File)"))
		void SetReadOnly(const bool ReadOnly);


	/**
	* Executes this file and waits for it to fininsh, returns the output.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Execute (File)"))
		void Execute(const FString& Parameters, bool& Success, int32& ReturnCode, FString& StdOut, FString& StdErr);

	/**
	* Executes this file as a separate process.
	*
	* Hidden will cause the new process to not have a window or show up in the task bar.
	* Priority can be: -2 idle, -1 low, 0 normal, 1 high, 2 higher.
	* OptionalWorkingDirectory can be left empty to use the current work directory.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Execute Async (File)", AdvancedDisplay = "4"))
		void ExecuteAsync(const FString& Parameters, bool& Success, int32& ProcessID, const bool Hidden = true, const int32 Priority = 0, ULowEntryFileManagerDirectory* OptionalWorkingDirectory = NULL);


	/**
	* Returns the data of this file, returns an empty byte array if this file doesn't exist.
	* 
	* Note: Can only open files of 2GB and smaller, will return an empty byte array if it is bigger than 2GB.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Get Data (File)"))
		TArray<uint8> GetData();

	/**
	* Sets the data of this file, creates this file if it doesn't exist yet.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Set Data (File)"))
		void SetData(const TArray<uint8>& Data);

	/**
	* Appends data to the end of this file, creates this file if it doesn't exist yet.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Append Data (File)"))
		void AppendData(const TArray<uint8>& Data);

	/**
	* Returns the number of bytes this file has, returns 0 if this file does not exist.
	* 
	* Note: Can only return sizes of 2GB and smaller, will return 0 if it is bigger than 2GB.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Get Size (File)"))
		int32 Size();


	/**
	* Returns the timestamp of the last edit of this file.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Get Timestamp (File)"))
		FDateTime GetTimestamp();

	/**
	* Sets the timestamp of the last edit of this file.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Set Timestamp (File)"))
		void SetTimestamp(const FDateTime& Timestamp);


	/**
	* Returns the timestamp of the last access of this file.
	*/
	UFUNCTION(BlueprintPure, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Get Access Timestamp (File)"))
		FDateTime GetAccessTimestamp();


	/**
	* Copies this file, won't do anything if the given NewFile already exists.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Copy (File)", Keywords = "clone duplicate"))
		void CopyTo(ULowEntryFileManagerFile* NewFile);

	/**
	* Moves/renames this file, won't do anything if the given NewFile already exists.
	*/
	UFUNCTION(BlueprintCallable, Category = "Low Entry|File Manager|High Level|File", Meta = (DisplayName = "Move (File)", Keywords = "rename"))
		void MoveTo(ULowEntryFileManagerFile* NewFile);
};
