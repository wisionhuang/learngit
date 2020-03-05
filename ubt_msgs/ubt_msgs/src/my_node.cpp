#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include "my_package/srv/mul_two_ints.hpp"

#include <memory>

void mul(const std::shared_ptr<my_package::srv::MulTwoInts::Request> request,
          std::shared_ptr<my_package::srv::MulTwoInts::Response>      response)
{
  response->mul = request->a * request->b;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
                request->a, request->b);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->mul);
}

int main(int argc, char ** argv)
{
  (void) argc;
  (void) argv;

  rclcpp::init(argc, argv);
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("mul_two_ints_server");

  rclcpp::Service<my_package::srv::MulTwoInts>::SharedPtr service =
    node->create_service<my_package::srv::MulTwoInts>("mul_two_ints", &mul);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to do test okok.");

  rclcpp::spin(node);
  rclcpp::shutdown();

  printf("hello ok package\n");
  return 0;
}
