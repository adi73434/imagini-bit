#pragma once

#include <string>
#include <vector>
#include "sciter-x.h"
#include "sciter-x-window.hpp"

class TestEventHandler : public sciter::event_handler
{
	HWND hwnd;
	HELEMENT self; // note: weak ref (not addrefed)

	TestEventHandler() : event_handler(), hwnd(0), self(0)
	{
	}

	virtual void attached(HELEMENT he)
	{
		self = he;
		sciter::dom::element el = he;
		hwnd = ::CreateWindow(TEXT("Scintilla"), TEXT(""),
							  WS_CHILD | WS_VSCROLL | WS_HSCROLL | WS_CLIPCHILDREN | WS_VISIBLE, 0, 0, 0, 0,
							  el.get_element_hwnd(true), // get element's host window
							  0, 0, 0);
		el.attach_hwnd(hwnd); // attach the window handler to the DOM element.
							  // after that the engine will manage window position and dimension
							  // by CSS rules
	}

	virtual void detached(HELEMENT he)
	{
		if (hwnd && ::IsWindow(hwnd))
			::DestroyWindow(hwnd);
		hwnd = 0;
		self = 0;
		sciter::dom::element el = he;
		el.attach_hwnd(0);
		delete this; // we delete the handler here as no one is using it anymore.
	}

	BEGIN_FUNCTION_MAP
		FUNCTION_0("getText", get_text) // getText()
		FUNCTION_1("setText", set_text) // setText(text:string)
	END_FUNCTION_MAP

	sciter::value get_text()
	{
		std::wstring text = WSTR("lol");
		// GetWindowText(hwnd) & friends here
		return sciter::value(text);
	}

	sciter::value set_text(const sciter::value &text_val)
	{
		std::wstring text = text_val.get(L"");
		// SetWindowText(hwnd) & friends here
		return sciter::value(); // returns undefined value, a.k.a. void
	}

};
