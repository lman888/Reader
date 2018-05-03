#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <windows.h>

///-----------------------------------------------------------------------------------------------------------///

///This method also returns a HANDLE to a mapped virtual value file, or nullptr it if
///fails to map.

///The first parameter is the access level we want which, like CreateFileMapping, can be various
///Options that include read-only write-only, or in this example we have gone with 
///All access using FILE_MAP_ALL_ACCESS

///The next parameter is if we want to allow processes that the current one creates to be able
/// to access the file mapping, which we can just leave as FALSE as processes creating processes
///Is a topic that is well beyond this session.

///The last parameter is the name of the virtual file mapping that we used in CreateFileMapping
///In our first application. Note that OpenFileMapping() does not know how much memory was mapped!

///Much like when we open a file on disk we will eventually need to close the file. In both applications
///Regardless of if the application Created or Opened the virtue file, we need to close it with a call 
///To CloseHandle() once we are done with it.

///-----------------------------------------------------------------------------------------------------------///


struct MyData
{
	///In all applications, the memory that was allocated by the CreateFileMapping()
	///application is hidden away within a virtual file system. To access it we need to get
	///a temporary pointer to it

	///We set up a pointer by "mapping" it to where the data is stored on the file system.
	///In our example, we had a struct MyData, which may look something like:

	float posX;
	float posY;
	float width;
	float height;
	float rotation;
};

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	MyData* data;

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	float m_timer;
};