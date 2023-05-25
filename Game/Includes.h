#pragma once

#include "ISystem.h"

#include<iostream>
#include "DebuggingStuff.hpp"
#include"GameObject.h"
#include "SceneTree.h"
#include "CountingSystem.h"
#include "SystemHandler.h"
#include "IComponent.h"
#include "DrawRectangleSystem.h"
#include "RectangleComponent.h"
#include "ReflectableComponent.hpp"
#include "ReflectorComponent.hpp"
#include "ReflectSystem.h"
#include "PlayerInputSystem.h"
#include "VelocityComponent.hpp"
#include <queue>

#define root (*SceneTree::SceneRoot.get())
#define deref(arg) (*arg.get())