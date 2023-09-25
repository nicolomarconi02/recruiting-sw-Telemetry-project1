#pragma once

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl2.h"
#include <GL/glew.h>
#include "telemetry.h"
#include "bms.h"
#include "tyre.h"
#include "motor.h"
#include "dataBase.h"

void app_render(TelemetryData, BMSData, TyreData, MotorData, DataBase*);
void car_preview(BMSData, TyreData, MotorData);
void track_session(TelemetryData);
void electronic(BMSData);
void tyre(TyreData);
void motor(MotorData);
void errors();
void profile(DataBase*);