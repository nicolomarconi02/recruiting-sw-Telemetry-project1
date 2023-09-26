#pragma once

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl2.h"
#include <GL/glew.h>
#include "dataBase.h"

void app_render(DataBase*);
void car_preview(DataBase*);
void track_session(DataBase*);
void electronic(DataBase*);
void tyre(DataBase*);
void motor(DataBase*);
void errors();
void profile(DataBase*);