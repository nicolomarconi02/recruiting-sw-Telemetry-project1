#pragma once

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl2.h"
#include <GL/glew.h>
#include "telemetry.h"
#include "voltage.h"
#include "temperature.h"

void app_render(TelemetryData, VoltageData, TemperatureData);
void car_preview(VoltageData, TemperatureData);
void track_session(TelemetryData);
void electronic(VoltageData);
void tyre(TemperatureData);
void motor(TemperatureData);
void errors();
void profile();