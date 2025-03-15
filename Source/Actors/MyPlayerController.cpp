#include "MyPlayerController.h"


void AMyPlayerController::MoveForward(const FInputActionInstance& Instance)
{
	UE_LOG(LogTemp, Log, TEXT("move forward called"));
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	SetupInputComponent();
}


void AMyPlayerController::Tick(float DeltaTime)
{
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputLocalPlayerSubsystem* InputSystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
	{
		UE_LOG(LogTemp, Log, TEXT("Mapping"));
		InputSystem->AddMappingContext(MappingContext, 0);
	}
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		UE_LOG(LogTemp, Log, TEXT("Binding"));
		EnhancedInput->BindAction(ForwardAction, ETriggerEvent::Triggered, this, AMyPlayerController::MoveForward);
	}
}
