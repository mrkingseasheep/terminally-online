#include <cstdlib>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>
#include <functional>
#include <string>
#include <vector>

int main() {
    using namespace ftxui;

    auto mainScr = ScreenInteractive::Fullscreen();

    std::string fName = "John";
    std::string lName = "Doe";
    std::string job = "Disappointment";
    double lvl = 1;
    double strength = 1;
    double intelligence = 1;
    double charm = 1;

    auto getLvl = [&] { return lvl; };
    auto getStr = [&] { return strength; };

    auto r_statsPanel = Container::Vertical({});
    auto r_quickActionPanel = Container::Horizontal({});
    auto r_commandPanel = Container::Vertical({});
    auto r_mainPanel = Container::Vertical({});
    auto r_chatPanel = Container::Vertical({});

    auto statsPanel = Renderer([&] {
        return vbox({
            text(fName + " " + lName) | bold,
            text("job"),
            text("Lvl. " + std::to_string((int)lvl)),
            separator(),
        });
    });

    auto quickActionPanel = Renderer([&] {
        return hbox({
            text("Action box!"),
        });
    });

    auto commandPanel = Renderer([&] {
        return vbox({
            text("Sample text"),
        });
    });

    auto mainPanel = Renderer([&] {
        return vbox({
            text("This is where you fight and do stuff"),
        });
    });

    auto chatPanel = Renderer([&] {
        const std::string chatPanelName = "Chat";
        const std::string chatIntroMsg =
            "This is where you can chat with your non-existent friends!";
        return vbox({
            text(chatIntroMsg),
        });
    });

    int statsPanelSz = 14;
    int chatPanelSz = 30;
    int commandPanelSz = 2;
    auto split = ResizableSplitBottom(commandPanel, mainPanel, &commandPanelSz);
    split = ResizableSplitLeft(statsPanel, mainPanel, &statsPanelSz);
    split = ResizableSplitRight(chatPanel, split, &chatPanelSz);

    mainScr.Loop(split | border);
}
