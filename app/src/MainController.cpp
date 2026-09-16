#include "MainController.hpp"

#include <cmath>
#include <engine/graphics/GraphicsController.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

float MainController::point_intensity() const {
    return m_point_intensity;
}
void MainController::set_point_intensity(float intensity) {
    m_point_intensity = intensity;
}
void MainController::initialize() {
    engine::graphics::OpenGL::enable_depth_testing();
    auto graphics = engine::core::Controller::get<engine::graphics::GraphicsController>();
    graphics->camera()->Position = glm::vec3(0.0f, 0.0f, 3.0f);
}
void MainController::poll_events() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    if (platform->key(engine::platform::KEY_SPACE).state() == engine::platform::Key::State::JustPressed) {
        m_animation_active = true;
        m_animation_time = 0.0f;
        m_ball_height = 0.0f;
        m_ball_angle = 0.0f;
    }
}
void MainController::update() {
    if (!m_animation_active) {
        return;
    }
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    m_animation_time += platform->dt();
    if (m_animation_time < 1.0f) {
        m_ball_height = 0.0f;
    } else if (m_animation_time < 5.0f) {
        float bounce_time = m_animation_time - 1.0f;
        m_ball_height = 0.4f * std::abs(std::sin(glm::pi<float>() * bounce_time));
    } else {
        m_ball_height = 0.0f;
        m_ball_angle = glm::radians(45.0f) * (m_animation_time - 5.0f);
    }
}
void MainController::begin_draw() {
    engine::graphics::OpenGL::clear_buffers();
}
void MainController::draw() {
    auto resources = engine::core::Controller::get<engine::resources::ResourcesController>();
    auto shader = resources->shader("basketball");
    auto basketball = resources->model("basketball");
    auto floor = resources->model("floor");
    auto graphics = engine::core::Controller::get<engine::graphics::GraphicsController>();
    shader->use();
    shader->set_vec3("point_position", glm::vec3(-1.0f, -0.8f, 1.0f));
    shader->set_vec3("point_color", glm::vec3(m_point_intensity));
    shader->set_vec3("viewPos", graphics->camera()->Position);
    shader->set_mat4("projection", graphics->projection_matrix());
    shader->set_mat4("view", graphics->camera()->view_matrix());

    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, m_ball_height, 0.0f));

    model = glm::rotate(model, m_ball_angle, glm::vec3(0.0f, 1.0f, 0.0f));

    shader->set_mat4("model", model);

    shader->set_int("use_texture", 1);
    basketball->draw(shader);

    glm::mat4 floor_model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.55561f, 0.0f));

    shader->set_mat4("model", floor_model);
    shader->set_int("use_texture", 0);
    shader->set_vec3("object_color", glm::vec3(0.74f, 0.33f, 0.06f));

    floor->draw(shader);
}
void MainController::end_draw() {
    engine::core::Controller::get<engine::platform::PlatformController>()->swap_buffers();
}