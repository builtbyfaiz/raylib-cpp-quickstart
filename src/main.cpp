/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

Modified by @builtbyfaiz, to add raylib-cpp & clangd
*/

// Note: IWYU Comment is for clangd as raylib-cpp is an umbrella header & clang marks it as unused directly.
#include "raylib-cpp.hpp" // IWYU pragma: keep 
#include "resource_dir.h"	

int main ()
{
	
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(800, 600, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	raylib::Texture wabbit("wabbit_alpha.png");
	
	// Game loop
	while (!WindowShouldClose())// Run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// Drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// Draw some text using the default font
		DrawText("Hello Raylib", 200,200,20,WHITE);
		
		// Draw our texture to the screen
		wabbit.Draw(400, 200);
		
		// End the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// Resource cleanup not needed, as raylib-cpp does it automatically
	
	return 0;
}