/*
	This file is part of the MinSG library extension ThesisStanislaw.
	Copyright (C) 2016 Stanislaw Eppinger

	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifdef MINSG_EXT_THESISSTANISLAW

#include <MinSG/Ext/ThesisStanislaw/LightPatchRenderer.h>

#include <E_MinSG/Ext/ThesisStanislaw/E_ApproxSceneDebug.h>

#include <MinSG/Core/NodeRenderer.h>
#include <MinSG/Ext/ThesisStanislaw/ApproxSceneDebug.h>

#include <MinSG/Core/FrameContext.h>
#include <EScript/EScript.h>

#include <E_MinSG/Core/Nodes/E_Node.h>
#include <E_MinSG/Core/States/E_State.h>

using namespace EScript;
using namespace MinSG;

namespace E_MinSG {
namespace ThesisStanislaw{
  
EScript::Type * E_ApproxSceneDebug::getTypeObject() {
	// E_LightPatchRenderer ---|> E_State ---|> Object
	static EScript::ERef<EScript::Type> typeObject = new EScript::Type(E_State::getTypeObject());
	return typeObject.get();
}


/**
 * initMembers
 */
void E_ApproxSceneDebug::init(EScript::Namespace & lib) {
  // E_LightPatchRenderer ---|> E_State ---|> Object
  EScript::Type * typeObject = E_ApproxSceneDebug::getTypeObject();
  declareConstant(&lib,getClassName(),typeObject);
  
  //! [ESMF] new MinSG.ApproxSceneDebug()
  ES_CTOR(typeObject,0,0,EScript::create(new MinSG::ThesisStanislaw::ApproxSceneDebug))
  
  //! [ESMF] self ApproxSceneDebug.setApproximatedScene(Node*)
  ES_MFUN(typeObject,MinSG::ThesisStanislaw::ApproxSceneDebug,"setApproximatedScene",1,1, (thisObj->setApproximatedScene(parameter[0].to<MinSG::Node*>(rt)),thisEObj))
  
  //! [ESMF] self ApproxSceneDebug.setLightPatchRenderer(LightPatchRenderer*)
  ES_MFUN(typeObject,MinSG::ThesisStanislaw::ApproxSceneDebug,"setLightPatchRenderer",1,1, (thisObj->setLightPatchRenderer(dynamic_cast<MinSG::ThesisStanislaw::LightPatchRenderer*>(parameter[0].to<MinSG::State*>(rt))),thisObj))

  addFactory<MinSG::ThesisStanislaw::ApproxSceneDebug,E_ApproxSceneDebug>();
}
//---

E_ApproxSceneDebug::E_ApproxSceneDebug(MinSG::ThesisStanislaw::ApproxSceneDebug * _obj, EScript::Type * type):E_State(_obj,type?type:getTypeObject()){
}

E_ApproxSceneDebug::~E_ApproxSceneDebug() = default;

}
}


#endif // MINSG_EXT_THESISSTANISLAW
