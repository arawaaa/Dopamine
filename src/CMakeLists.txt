qt5_add_resources(dopamine_SRCS resources.qrc)
add_executable(dopamine main.cpp
               accountmanager.cpp
               ${dopamine_SRCS})
target_link_libraries(dopamine Qt5::Qml Qt5::Gui Qt5::Quick Qt5::Core)
target_link_libraries(dopamine KF5::Prison KF5::DBusAddons KF5::Kirigami2)
