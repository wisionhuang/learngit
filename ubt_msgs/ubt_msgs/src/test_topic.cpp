#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/string.hpp"
#include "ubt_msgs/msg/Test.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("test");

rclcpp::Publisher<msg::test>::SharedPtr publisher_=node->create_publisher<msg::test>("topic", 10);


	 auto message = msg::test();
	    message.my_string = "Hello, world! ";
	    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Publishing: '%s'", message.my_string.c_str());
	    publisher_->publish(message);

  //rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
