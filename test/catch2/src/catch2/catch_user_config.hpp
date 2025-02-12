// catch_user_config.hpp

// Define the console width for Catch2 output formatting
#define CATCH_CONFIG_CONSOLE_WIDTH 80

// Customize the main() function
#define CATCH_CONFIG_MAIN  // Provide a default main() function
// #define CATCH_CONFIG_RUNNER  // Use a custom main() function

// Enable additional reporters or features
#define CATCH_CONFIG_ENABLE_ALL_STRINGMAKERS  // Enable stringification for all types
#define CATCH_CONFIG_ENABLE_PAIR_STRINGMAKER  // Enable stringification for std::pair
#define CATCH_CONFIG_ENABLE_TUPLE_STRINGMAKER  // Enable stringification for std::tuple

// Disable specific warnings
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif