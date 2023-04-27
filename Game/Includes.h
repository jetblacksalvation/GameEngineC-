#pragma once

#include "ISystem.h"

#include<iostream>

#include"GameObject.h"
#include "SceneTree.h"
#include "CountingSystem.h"
#include "SystemHandler.h"
#include "IComponent.h"
#include <queue>

#define root (*SceneTree::SceneRoot.get())
#define deref(arg) (*arg.get())