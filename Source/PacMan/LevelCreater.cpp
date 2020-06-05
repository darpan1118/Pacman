// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelCreater.h"
#include "Engine/Texture2D.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

// Sets default values
ALevelCreater::ALevelCreater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ALevelCreater::ReadPixelValues(UTexture2D* MyTexture2D)
{
	/*TextureCompressionSettings OldCompressionSettings = MyTexture2D->CompressionSettings; 
	TextureMipGenSettings OldMipGenSettings = MyTexture2D->MipGenSettings; 
	bool OldSRGB = MyTexture2D->SRGB;

	/*int TextureInFileSize = MyTexture2D->GetSizeX(); //the width of the texture
	TextureInFileData.Init(FColor(0, 0, 0, 255), TextureInFileSize * TextureInFileSize);/*

	MyTexture2D->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	MyTexture2D->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	MyTexture2D->SRGB = false;
	MyTexture2D->UpdateResource();

	const FColor* FormatedImageData = static_cast<const FColor*>(MyTexture2D->PlatformData->Mips[0].BulkData.LockReadOnly());
	for (int32 X = 0; X < MyTexture2D->GetSizeX(); X++)
	{
		for (int32 Y = 0; Y < MyTexture2D->GetSizeY(); Y++)
		{
			FColor PixelColor = FormatedImageData[Y * MyTexture2D->GetSizeX() + X];
			if (PixelColor == FColor::Black)
			{
				UE_LOG(LogTemp, Warning, TEXT("Black color found in image"));
			}
		}
	}

	MyTexture2D->PlatformData->Mips[0].BulkData.Unlock();

	MyTexture2D->CompressionSettings = OldCompressionSettings;
	MyTexture2D->MipGenSettings = OldMipGenSettings;
	MyTexture2D->SRGB = OldSRGB;
	MyTexture2D->UpdateResource();*/
}



void ALevelCreater::CopyTextureToArray(UTexture2D *TextureInFile, TArray<FColor> &TextureInFileData) 
{
	int TextureInFileSize = TextureInFile->GetSizeX(); //the width of the texture
	TextureInFileData.Init(FColor(0, 0, 0, 255), TextureInFileSize * TextureInFileSize);//making sure it has something, and sizing the array n*n
	//init TArray
	//What i want to do is take all the values from Texture File ->to-> TArray of FColors
	if (!TextureInFile) {
		//Many times i forgot to load the texture in the editor so every time i hit play the editor crashed
		UE_LOG(LogTemp, Error, TEXT("Missing texture in LevelInfo, please load the mask!"));
		return; //<---if textureInFile is missing stop execution of the code
	}
	if (TextureInFile != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Texture in file is :  %d  pixels wide"), TextureInFileSize);

		FTexture2DMipMap& Mip = TextureInFile->PlatformData->Mips[0];//A reference 
		void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
		uint8* raw = NULL;
		raw = (uint8*)Data;

		FColor pixel = FColor(0, 0, 0, 255);//used for spliting the data stored in raw form

		//the usual nested loop for reading the pixels
		for (int y = 0; y < TextureInFileSize; y++) {

			for (int x = 0; x < TextureInFileSize; x++) {
				//data in the raw var is serialized i think ;)
				//so a pixel is four consecutive numbers e.g 0,0,0,255
				//and the following code split the values in single components and store them in a FColor
				pixel.B = raw[4 * (TextureInFileSize * y + x) + 0];
				pixel.G = raw[4 * (TextureInFileSize * y + x) + 1];
				pixel.R = raw[4 * (TextureInFileSize * y + x) + 2];
				//And then this code iterates over the TArray of FColors and stores them
				TextureInFileData[x + y * TextureInFileSize] = FColor((uint8)pixel.R, (uint8)pixel.G, (uint8)pixel.B, 255);
			}
		}
		Mip.BulkData.Unlock();
		TextureInFile->UpdateResource();
	}
}

// Called when the game starts or when spawned
void ALevelCreater::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelCreater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

