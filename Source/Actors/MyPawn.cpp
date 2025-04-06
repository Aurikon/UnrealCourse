#include "MyPawn.h"

AMyPawn::AMyPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Palka"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	SetRootComponent(Mesh);
	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);
}

void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

	MyController = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
}


void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyController->GetShouldMove())
	{
		SetActorLocation(GetActorLocation() + DeltaTime * Speed * GetActorForwardVector());
	}

	FRotator CurrentRotation = SpringArm->GetComponentRotation();
	FRotator DeltaRotation(MyController->GetMouseY(), MyController->GetMouseX(), 0.0f);
	SpringArm->SetWorldRotation(CurrentRotation + DeltaRotation * DeltaTime * Sensitivity);
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

