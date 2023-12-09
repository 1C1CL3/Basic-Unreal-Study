// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * UNREALOBJECT_API는UNREALOBJECT라고 하는 프로젝트 이름이며 
 * MyObject가 다른 Unreal 라이브러리에서 MyObject를 사용할수 있게 하는 것
 */
UCLASS()//UnrealObject선언임을 명시하기 위해서 UCLASS매크로를 선언
class UNREALOBJECT_API UMyObject : public UObject
{
	GENERATED_BODY()
	
};
