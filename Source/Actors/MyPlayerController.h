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

	bool bShouldMove = false;
	float MouseX;
	float MouseY;

	UPROPERTY(EditAnywhere)
	UInputAction* ForwardAction;

	UPROPERTY(EditAnywhere)
	UInputAction* MouseXAction;

	UPROPERTY(EditAnywhere)
	UInputAction* MouseYAction;

	UPROPERTY(EditAnywhere)
	UInputMappingContext* MappingContext;


	void MoveForward(const FInputActionInstance& Instance);
	void StopForward(const FInputActionInstance& Instance);

	void TriggerMouseX(const FInputActionInstance& Instance);
	void TriggerMouseY(const FInputActionInstance& Instance);

protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltraTime) override;
	virtual void SetupInputComponent() override;

	bool GetShouldMove() const { return bShouldMove; }
	float GetMouseX() const { return MouseX; }
	float GetMouseY() const { return MouseY; }
};
