#pragma once

#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl2.h"
#include <GL/glew.h>
#include "telemetry.h"

void app_render(TelemetryData);
void car_preview();
void track_session(TelemetryData);
void electronic();
void tyre();
void errors();
void profile();