// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();

	TCHAR LogCharArray[] = TEXT("hello Unreal");
	UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArray);

	FString LogCharString = LogCharArray;
	UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString);

	//1. fstring을 tchar로 끄집어 내기 위해 포인터를 사용하여 참조
	const TCHAR* LongCharPtr = *LogCharString;

	//2. 포인터를 받아서 const가 아닌 이를 포인터를 받아서 뭔가 고치고 싶을때
	// (fstring이 가지고 있는TArray의 첫번째 포인터를 가져와야함)
	TCHAR* LogCharDataPtr = LogCharString.GetCharArray().GetData();

	//3. 만약에 다시 배열로 가져오고 싶을때
	TCHAR LogCharArrayWithSize[100];
	//이 경우 저수준의 스트링 복사를 해주는편이 좋다. (버퍼 지정할 것)
	FCString::Strcpy(LogCharArrayWithSize, LogCharString.Len(), *LogCharString);
	//어떤 텍스트가 있는지 검사하는데 이때 대소문자를 구분가능(대 IgnoreCase,소 CaseSensitive)
	if (LogCharString.Contains(TEXT("unreal"),ESearchCase::IgnoreCase))
	{
		int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
		FString EndString = LogCharString.Mid(Index);
		UE_LOG(LogTemp, Log, TEXT("FindText : %s"), *EndString);
	}
	//split
	FString Left, Right;
	if (LogCharString.Split(TEXT(" "),&Left,&Right))
	{
		UE_LOG(LogTemp,Log,TEXT("Split Text: %s 와 %s"), *Left, *Right)
	}

	int32 IntVal = 32;
	float FloatVal = 3.141592;

	FString FloatIntString = FString::Printf(TEXT("Int : %d Float : %f"), IntVal, FloatVal);
	FString FloatString = FString::SanitizeFloat(FloatVal);
	FString IntString = FString::FromInt(IntVal);

	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);
	UE_LOG(LogTemp, Log, TEXT("Int : %s , Float : %s"), *IntString, *FloatString);


	int32 IntValueFromString = FCString::Atoi(*IntString);
	float FloatValueFromString = FCString::Atof(*FloatString);

	FString FloatIntToString = FString::Printf(TEXT("StringInt : %d StringFloat : %f"), 
		IntValueFromString, FloatValueFromString);
	UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntToString);


	FName key1(TEXT("PELVIS"));
	FName key2(TEXT("pelvis"));
	UE_LOG(LogTemp, Log, TEXT("FName 비교 결과 : %s"), 
		key1 == key2 ? TEXT("같음") : TEXT("다름"));

	for (int i = 0; i < 10000; i++)
	{
		//생성자에 문자열을 넣으면 fname은 문자열을 키로 변환하고 
		//키가 전역 풀에 있는지 조사하게 된다. 
		//고로 빈번한 작업에는 오버헤드가 발생할 수 있다.
		FName SearchInNamePool = FName(TEXT("pelvis"));

		//아래와 같이 사용하는것이 바람직하다
		const static FName StaticOnlyOne(TEXT("pelvis"));
	}
}