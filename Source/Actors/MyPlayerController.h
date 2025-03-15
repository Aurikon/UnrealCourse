#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MyPlayerController.generated.h"


UCLASS()
class ACTORS_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UInputAction* ForwardAction;

	UPROPERTY(EditAnywhere)
	UInputMappingContext* MappingContext;


	void MoveForward(const FInputActionInstance& Instance);
	
protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltraTime) override;
	virtual void SetupInputComponent() override;
};
