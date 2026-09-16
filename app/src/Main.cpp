#include "MyApp.hpp"

#include <memory>
#include <spdlog/spdlog.h>

int main(int argc, char **argv) {
    return std::make_unique<MyApp>()->run(argc, argv);
}
