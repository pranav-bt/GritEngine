#pragma once
#include<iostream>
#include <cstdio>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <assert.h>
#include <stdint.h>
#include "Application.h"
#include "Vector4.h"
#include "Collision.h"
#include "InputController.h"
using namespace GritEngine;
#if defined _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif // _DEBUG
static _CrtMemState gMemState;

int Game();