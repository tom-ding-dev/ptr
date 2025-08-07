#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::rep);
    socket.bind("tcp://*:5555");

    while (true) {
        zmq::message_t request;
        socket.recv(request, zmq::recv_flags::none);
        std::cout << "Received: " << request.to_string() << std::endl;

        std::string reply = "World";
        socket.send(zmq::buffer(reply), zmq::send_flags::none);
    }
}
