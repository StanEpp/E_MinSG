/*
	This file is part of the MinSG library extension ThesisStanislaw.
	Copyright (C) 2016 Stanislaw Eppinger

	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifdef MINSG_EXT_THESISSTANISLAW

#ifndef MINSG_EXT_E_THESISSTANISLAW_LIGHTPATCHRENDERER_H
#define MINSG_EXT_E_THESISSTANISLAW_LIGHTPATCHRENDERER_H

#include <MinSG/Ext/ThesisStanislaw/LightPatchRenderer.h>
#include "../../Core/States/E_State.h"

namespace EScript {
class Namespace;
class Runtime;
class Type;
}

namespace MinSG {
namespace ThesisStanislaw {
class LightPatchRenderer;
}
}

namespace E_MinSG {
namespace ThesisStanislaw{
/***
 **   E_LightPatchRenderer ---|> E_State ---|> Object
 **/
class E_LightPatchRenderer : public E_State {
		ES_PROVIDES_TYPE_NAME(LightPatchRenderer)
	public:
		template<class, class, class> friend class Util::PolymorphicWrapperCreator;

		static EScript::Type* getTypeObject();
		static void init(EScript::Namespace & lib);

		virtual ~E_LightPatchRenderer();

		const MinSG::ThesisStanislaw::LightPatchRenderer * operator*()const	{	return static_cast<const MinSG::ThesisStanislaw::LightPatchRenderer*>(ref().get());	}
		MinSG::ThesisStanislaw::LightPatchRenderer * operator*()	{	return static_cast<MinSG::ThesisStanislaw::LightPatchRenderer*>(ref().get());	}

	protected:
		E_LightPatchRenderer(MinSG::ThesisStanislaw::LightPatchRenderer * obj, EScript::Type * type=nullptr);
};

}
}

ES_CONV_EOBJ_TO_OBJ(E_MinSG::ThesisStanislaw::E_LightPatchRenderer, MinSG::ThesisStanislaw::LightPatchRenderer*, **eObj)

#endif // E_LIGHTPATCHRENDERER_H_INCLUDED
#endif // MINSG_EXT_THESISSTANISLAW
