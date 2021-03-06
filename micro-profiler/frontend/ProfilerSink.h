//	Copyright (c) 2011-2015 by Artem A. Gevorkyan (gevorkyan.org)
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.

#pragma once

#include "../resources/resource.h"

#include <atlbase.h>
#include <atlcom.h>
#include <memory>
#include <ObjIdl.h>
#include <wpl/base/signals.h>

namespace std { namespace tr1 { } using namespace tr1; }

namespace micro_profiler
{
	class ProfilerMainDialog;
	class functions_list;
	struct symbol_resolver;

	class __declspec(uuid("0ED7654C-DE8A-4964-9661-0B0C391BE15E")) ATL_NO_VTABLE ProfilerFrontend
		: public ISequentialStream, public CComObjectRootEx<CComSingleThreadModel>,
			public CComCoClass<ProfilerFrontend, &__uuidof(ProfilerFrontend)>
	{
		std::shared_ptr<symbol_resolver> _symbols;
		std::shared_ptr<functions_list> _statistics;
		std::shared_ptr<ProfilerMainDialog> _dialog;
		wpl::slot_connection _closed_connected;

	public:
		ProfilerFrontend();
		~ProfilerFrontend();

		DECLARE_REGISTRY_RESOURCEID(IDR_PROFILERSINK)

		BEGIN_COM_MAP(ProfilerFrontend)
			COM_INTERFACE_ENTRY(ISequentialStream)
		END_COM_MAP()

		void FinalRelease();

		STDMETHODIMP Read(void *data, ULONG size, ULONG *read);
		STDMETHODIMP Write(const void *message, ULONG size, ULONG *written);
	};
}
