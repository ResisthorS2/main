#include "./libs/engine.h"

/*---------------------------Definition de fonctions ------------------------*/


Engine::Engine(){
    input = new Input;
    input->potentiometer_X = 0;
    input->potentiometer_Y = 0;
    input->motor = 0;
    input->btn_180 = 0;
    input->btn_up = 0;
    input->btn_left = 0;
    input->btn_right = 0;
    input->btn_select = 0;
    input->accelerometer_X = 0;
    input->accelerometer_Y = 0;
    input->accelerometer_Z = 0;
}

Engine::~Engine()
{

    delete input;
}


bool Engine::SendToSerial(SerialPort *arduino, json j_msg)
{
    // Return 0 if error
    std::string msg = j_msg.dump();
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    return ret;
}


bool Engine::RcvFromSerial(SerialPort *arduino, std::string &msg){
    // Return 0 if error
    // Message output in msg
    std::string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear(); // clear std::string
    // Read serialport until '\n' character (Blocking)

    // Version fonctionnel dans VScode, mais non fonctionnel avec Visual Studio
/*  
    while(msg.back()!='\n'){
        if(msg.size()>MSG_MAX_SIZE){
            return false;
        }

        buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
        str_buffer.assign(char_buffer, buffer_size);
        msg.append(str_buffer);
    }
*/

    // Version fonctionnelle dans VScode et Visual Studio
    buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);

    //msg.pop_back(); //remove '/n' from std::string

    return true;
}

void Engine::updateComponents(json j_msg_rcv, std::string raw_msg)
{
    //std::cout << "updateComponents" << std::endl;
    try
    {
        
        if (j_msg_rcv.empty())
        {   
            throw std::runtime_error("Empty message");
        }
    }
    catch(const std::exception& e)
    {
        
        return;
    }
    

    
    // Update components
    input->potentiometer_X = j_msg_rcv["potentiometer_X"];
    input->potentiometer_Y = j_msg_rcv["potentiometer_Y"];
    input->motor = j_msg_rcv["motor"];
    input->btn_180 = j_msg_rcv["btn_180"];
    input->btn_up = j_msg_rcv["btn_up"];
    input->btn_left = j_msg_rcv["btn_left"];
    input->btn_right = j_msg_rcv["btn_right"];
    input->btn_select = j_msg_rcv["btn_select"];
    input->accelerometer_X = j_msg_rcv["accelerometer"]["x"];
    input->accelerometer_Y = j_msg_rcv["accelerometer"]["y"];
    input->accelerometer_Z = j_msg_rcv["accelerometer"]["z"];
}
