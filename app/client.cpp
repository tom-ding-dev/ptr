#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::req);
    socket.connect("tcp://localhost:5555");

    std::string msg = "Hello";
    socket.send(zmq::buffer(msg), zmq::send_flags::none);

    zmq::message_t reply;
    socket.recv(reply, zmq::recv_flags::none);
    std::cout << "Received: " << reply.to_string() << std::endl;
}
