#pragma once

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl2.h"
#include <GL/glew.h>
#include "telemetry.h"
#include "voltage.h"

void app_render(TelemetryData, VoltageData);
void car_preview();
void track_session(TelemetryData);
void electronic(VoltageData);
void tyre();
void errors();
void profile();