#include "GuiController.hpp"
#include "MainController.hpp"

#include <engine/graphics/GraphicsController.hpp>
#include <imgui.h>

void GuiController::draw() {
    auto graphics = engine::core::Controller::get<engine::graphics::GraphicsController>();
    auto main_controller = engine::core::Controller::get<MainController>();
    float intensity = main_controller->point_intensity();
    graphics->begin_gui();
    ImGui::Begin("Osvetljenje");
    if (ImGui::SliderFloat("Point jacina", &intensity, 0.0f, 2.0f)) {
        main_controller->set_point_intensity(intensity);
    }
    ImGui::End();
    graphics->end_gui();
}