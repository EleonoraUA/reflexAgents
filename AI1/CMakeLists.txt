cmake_minimum_required(VERSION 3.3)
project(AI1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/GL/gl.h
    include/GL/glu.h
    include/GL/glui.h
    include/GL/openglut.h
    include/GL/openglut_ext.h
    include/GL/openglut_std.h
    include/glui.cpp
    include/glui_bitmap_img_data.cpp
    include/glui_bitmaps.cpp
    include/glui_button.cpp
    include/glui_column.cpp
    include/glui_control.cpp
    include/glui_edittext.cpp
    include/glui_filebrowser.cpp
    include/glui_internal.h
    include/glui_internal_control.h
    include/glui_list.cpp
    include/glui_node.cpp
    include/glui_panel.cpp
    include/glui_radio.cpp
    include/glui_rollout.cpp
    include/glui_scrollbar.cpp
    include/glui_spinner.cpp
    include/glui_statictext.cpp
    include/glui_string.cpp
    include/glui_window.cpp
    include/glut.h
    lib/glui32.lib
    lib/glut32.lib
    lib/OpenGLUT.lib
    map/agent.map
    agent.cpp
    agent.h
    agent.ico
    Agent_private.h
    Agent_private.rc
    Agent_private.res
    environment.cpp
    environment.h
    evaluator.cpp
    evaluator.h
    GUI.cpp
    GUI.h
    main.cpp
    random_num_gen.cpp
    random_num_gen.h)
LINK_DIRECTORIES(lib)

add_executable(AI1 ${SOURCE_FILES})