import sys

import example_pb2
import my_extension as m


def main():
  print('python is', sys.version_info)  
  print(sys.executable)

  
  # Create a message via python (?)
  print('Creating a message via python')  
  my_message = example_pb2.TestMessage(string_value = "hello")
  print(my_message)
  
  print('Creating a message via pybind11')  
  my_msg = m.create_message("Hello World")
  # Try and print message from pybind11
  m.print_message(my_msg)




if __name__ == "__main__":
  main()