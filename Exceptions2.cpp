// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// CustomException class
struct CustomException : public std::exception
{
  virtual const char *what() const throw()
  {
    return "Testing, one, two!";
  }
};

bool do_even_more_custom_application_logic()
{
  // TODO: Throw any standard exception
  throw std::bad_exception();

  std::cout << "Running Even More Custom Application Logic." << std::endl;

  return true;
}

void do_custom_application_logic()
{
  std::cout << "Running Custom Application Logic." << std::endl;

  try
  {
    if (do_even_more_custom_application_logic())
    {
      std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
    }
  }
  catch (const std::exception &exception)
  {
    std::cerr << "Exception message: " << exception.what() << std::endl;
  }

  // TODO: Throw a custom exception derived from std::exception
  //  and catch it explicitly in main
  throw CustomException();

  std::cout << "Leaving Custom Application Logic." << std::endl;
}

float divide(float num, float den)
{
  // TODO: Throw an exception to deal with divide by zero errors using
  //  a standard C++ defined exception
  if (den == 0)
  {
    throw std::runtime_error("Divide by zero error.");
  }
  return (num / den);
}

void do_division() noexcept
{
  //  TODO: create an exception handler to capture ONLY the exception thrown
  //  by divide.

  float numerator = 10.0f;
  float denominator = 0;

  try
  {
    auto result = divide(numerator, denominator);
    std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
  }
  catch (const std::exception &exception)
  {
    std::cerr << "Exception message: " << exception.what() << std::endl;
  }

  auto result = divide(numerator, denominator);
  std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
}

int main()
{
  try
  {
    std::cout << "Exceptions Tests" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    // your custom exception
    // std::exception
    // uncaught exception
    // that wraps the whole main function, and displays a message to the console.
    do_division();
    do_custom_application_logic();
  }
  catch (const CustomException &exception)
  {
    std::cerr << "Exception message: " << exception.what() << std::endl;
  }
  catch (const std::exception &exception)
  {
    std::cerr << "Exception message: " << exception.what() << std::endl;
  }
  catch (...)
  {
  }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
