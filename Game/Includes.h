#pragma once
#include<iostream>
#include"GameObject.h"
#include "SceneTree.h"
#include "CountingSystem.h"
#include "IComponent.h"
#include <queue>
#define root (*SceneTree::SceneRoot.get())
#define deref(arg) (*arg.get())