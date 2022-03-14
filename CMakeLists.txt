cmake_minimum_required(VERSION 3.15)
project(TRACEY_EDITOR VERSION 0.0.1)
add_subdirectory(deps/JUCE)
add_subdirectory(deps/IXWebSocket)
option(JSON_BuildTests OFF)
option(JSON_Install OFF)
add_subdirectory(deps/json)
add_subdirectory(deps/graphql_ws)

juce_add_gui_app(TraceyEditor
    # VERSION ...                       # Set this if the app version is different to the project version
    # ICON_BIG ...                      # ICON_* arguments specify a path to an image file to use as an icon
    # ICON_SMALL ...
    # DOCUMENT_EXTENSIONS ...           # Specify file extensions that should be associated with this app
    # COMPANY_NAME ...                  # Specify the name of the app's author
    PRODUCT_NAME "Tracey Editor")     # The name of the final executable, which can differ from the target name

set_property(TARGET TraceyEditor PROPERTY CXX_STANDARD 20)

juce_generate_juce_header(TraceyEditor)

set(SOURCES
	source/main.cpp
	source/actions/action.h
	source/actions/action.cpp
	source/actions/load_scene_action.h
	source/actions/load_scene_action.cpp
	source/actions/project_query_action.hpp
	source/actions/project_query_action.cpp
	source/controller/application_controller.h
	source/controller/application_controller.cpp
	source/model/menu.hpp
	source/model/menu.cpp
	source/model/scene_graph.h
	source/model/scene_graph.cpp
	source/model/track.hpp
	source/model/track.cpp
	source/ui/animation_panel.hpp
	source/ui/animation_panel.cpp
	source/ui/scene_graph_view.hpp
	source/ui/scene_graph_view.cpp
	source/ui/main_component.hpp
	source/ui/main_component.cpp
	source/ui/track_panel.hpp
	source/ui/track_panel.cpp
	source/ui/track_view.hpp
	source/ui/track_view.cpp
	source/ui/view_port.hpp
	source/ui/view_port.cpp
)

target_sources(TraceyEditor
    PRIVATE
        ${SOURCES})

target_compile_definitions(TraceyEditor
    PRIVATE
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_gui_app` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_gui_app` call
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:TraceyEditor,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:TraceyEditor,JUCE_VERSION>")

target_link_libraries(TraceyEditor
    PRIVATE
        # GuiAppData            # If we'd created a binary data target, we'd link to it here
        juce::juce_gui_extra
		graphql_ws
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)