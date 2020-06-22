#include "main.hpp"
using namespace std;

const char * prompt();
int jump( const char * );


int fa() {

    try {
        boost::asio::io_context io;

        boost::asio::serial_port serial(io, "COM3");

        serial.set_option(boost::asio::serial_port_base::baud_rate(9600));
        serial.set_option(boost::asio::serial_port_base::character_size(8));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

        std::string data{ "Half_Clockwise\r\n" };

        boost::asio::write(serial, boost::asio::buffer(data, data.size()));

        serial.close();
    }
    catch (std::exception& e) {

        std::cout << e.what() << std::endl;

        return 1;
    }
    return 0;
}

int fb() {

    try {
        boost::asio::io_context io;

        boost::asio::serial_port serial(io, "COM3");

        serial.set_option(boost::asio::serial_port_base::baud_rate(9600));
        serial.set_option(boost::asio::serial_port_base::character_size(8));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

        std::string data{ "Full_Clockwise\r\n" };

        boost::asio::write(serial, boost::asio::buffer(data, data.size()));

        serial.close();
    }
    catch (std::exception& e) {

        std::cout << e.what() << std::endl;

        return 1;
    }
    return 0;
}

int fc() {

    try {
        boost::asio::io_context io;

        boost::asio::serial_port serial(io, "COM3");

        serial.set_option(boost::asio::serial_port_base::baud_rate(9600));
        serial.set_option(boost::asio::serial_port_base::character_size(8));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

        std::string data{ "Half_Counterclockwise\r\n" };

        boost::asio::write(serial, boost::asio::buffer(data, data.size()));

        serial.close();
    }
    catch (std::exception& e) {

        std::cout << e.what() << std::endl;

        return 1;
    }
    return 0;
}

int fd() {

    try {
        boost::asio::io_context io;

        boost::asio::serial_port serial(io, "COM3");

        serial.set_option(boost::asio::serial_port_base::baud_rate(9600));
        serial.set_option(boost::asio::serial_port_base::character_size(8));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

        std::string data{ "Full_Counterclockwise\r\n" };

        boost::asio::write(serial, boost::asio::buffer(data, data.size()));

        serial.close();
    }
    catch (std::exception& e) {

        std::cout << e.what() << std::endl;

        return 1;
    }
    return 0;
}

int fe() {

    try {
        boost::asio::io_context io;

        boost::asio::serial_port serial(io, "COM3");

        serial.set_option(boost::asio::serial_port_base::baud_rate(9600));
        serial.set_option(boost::asio::serial_port_base::character_size(8));
        serial.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
        serial.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

        std::string data{ "Full_Clockwise_Counterclockwise\r\n" };

        boost::asio::write(serial, boost::asio::buffer(data, data.size()));

        serial.close();
    }
    catch (std::exception& e) {

        std::cout << e.what() << std::endl;

        return 1;
    }
    return 0;
}

int (*funcs[])() = { fa, fb, fc, fd, fe };

int main() {
    while(jump(prompt())) ;
    puts("\nDone.");
    return 0;
}

const char * prompt() {
    puts("Choose an option:");
    puts("1. Travel Half distance Clockwise");
    puts("2. Travel Full distance Clockwise");
    puts("3. Travel Half distance Counterclockwise");
    puts("4. Travel Full distance Counterclockwise");
    puts("5. Travel Full distance Clockwise and back");
    puts("Q. Quit.");
    printf(">> ");
    fflush(stdout);                 // flush after prompt
    
    const int buffsz = 16;          // constant for buffer size
    static char response[buffsz];   // static storage for response buffer
    fgets(response, buffsz, stdin); // get response from console
    
    return response;
}

int jump( const char * rs ) {
    char code = rs[0];
    if(code == 'q' || code == 'Q') return 0;
    
    // get the length of the funcs array
    int func_length = sizeof(funcs) / sizeof(funcs[0]);
    
    int i = (int) code - '0';   // convert ASCII numeral to int
    if( i < 1 || i > func_length ) {
        puts("invalid choice");
        return 1;
    } else {
        funcs[i - 1]();         // array is zero-based
        return 1;
    } 
}