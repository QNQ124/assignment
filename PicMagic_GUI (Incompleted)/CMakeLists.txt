cmake_minimum_required(VERSION 3.16)

project(First_GUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)


qt_standard_project_setup()

qt_add_executable(appFirst_GUI
    main.cpp
)

qt_add_qml_module(appFirst_GUI
    URI First_GUI
    VERSION 1.0
    QML_FILES
        QML_FILES AutoInfoBox.qml Main.qml
        SOURCES Main.cpp ImageProcessing.pro ImageProcessor.cpp
        SOURCES ImageProcessor.h Image_Class.h stb_image.h stb_image_write.h

    RESOURCES
        assets/images/parots.bmp
        assets/images/House.bmp
        assets/images/gamma_adjusted_image.jpg
        assets/images/luffy.jpg
        assets/images/Monument+Grey.jpeg
        assets/images/abstract-bp-initials-monogram-logo-design-icon-business-template-simple-elegant_619996-90.jpg
        build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/temporary_file.jpg
        assets/images/image.png
        assets/images/image1.png
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appFirst_GUI PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appFirst_GUI
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appFirst_GUI
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appFirst_GUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
