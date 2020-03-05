cmake_minimum_required(VERSION 3.5)
project(ubt_msgs)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

rosidl_generate_interfaces(ubt_msgs
  "msg/JointState.msg"
  "msg/JointCommand.msg"
  "msg/RttestResults.msg"
  "msg/Test.msg"
  DEPENDENCIES builtin_interfaces std_msgs
)


ament_export_dependencies(rosidl_default_runtime)

add_executable(my_node src/my_node.cpp)
ament_target_dependencies(my_node
  rclcpp std_srvs)
install(TARGETS
  my_node
  DESTINATION lib/${PROJECT_NAME})

#add_executable(test_topic src/test_topic.cpp)
#ament_target_dependencies(test_topic
#  rclcpp std_msgs)
#rosidl_target_interfaces(test_topic ${PROJECT_NAME} "rosidl_typesupport_cpp")

#install(TARGETS
#test_topic
#  DESTINATION lib/${PROJECT_NAME})


#if(BUILD_TESTING)
  #find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
 # ament_lint_auto_find_test_dependencies()
#endif()

ament_package()
