#include "MyPlayerController.h"


void AMyPlayerController::MoveForward(const FInputActionInstance& Instance)
{
	bShouldMove = true;
}

void AMyPlayerController::StopForward(const FInputActionInstance& Instance)
{
	bShouldMove = false;
}

void AMyPlayerController::TriggerMouseX(const FInputActionInstance& Instance)
{
	MouseX = Instance.GetValue().Get<float>();
}

void AMyPlayerController::TriggerMouseY(const FInputActionInstance& Instance)
{
	MouseY = Instance.GetValue().Get<float>();
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
		InputSystem->AddMappingContext(MappingContext, 0);
	}
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(ForwardAction, ETriggerEvent::Triggered, this, &AMyPlayerController::MoveForward);
		EnhancedInput->BindAction(ForwardAction, ETriggerEvent::Completed, this, &AMyPlayerController::StopForward);
		
		EnhancedInput->BindAction(MouseXAction, ETriggerEvent::Triggered, this, &AMyPlayerController::TriggerMouseX);
		EnhancedInput->BindAction(MouseYAction, ETriggerEvent::Triggered, this, &AMyPlayerController::TriggerMouseY);

		EnhancedInput->BindAction(MouseXAction, ETriggerEvent::Completed, this, &AMyPlayerController::TriggerMouseX);
		EnhancedInput->BindAction(MouseYAction, ETriggerEvent::Completed, this, &AMyPlayerController::TriggerMouseY);
	}
}
