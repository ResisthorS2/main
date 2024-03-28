#include "./libs/engine.h"

/*---------------------------Definition de fonctions ------------------------*/


Engine::Engine(SerialPort *ardui){
    this->arduino = ardui;
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

json Engine::updateComponents(SerialPort *arduino, json j_msg_rcv1)
{
            std::string raw_msg;
            j_msg_rcv1.clear();
            raw_msg.clear();
            while(raw_msg.back()!='\n')
            {
                if(raw_msg.size()>MSG_MAX_SIZE)
                {
                    break;
                }
                std::string str_buffer;
                char char_buffer[MSG_MAX_SIZE];
                int buffer_size;
                buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
                str_buffer.assign(char_buffer, buffer_size);
                raw_msg.append(str_buffer);
            }
            
            
            // Impression du message de l'Arduino si valide
            if(raw_msg.size()>0){
                //std::cout << "raw_msg: " << raw_msg  << "----------" << std::endl;  // debug
                // Transfert du message en json
                try
                {
                    j_msg_rcv1 = json::parse(raw_msg);
                    //engine->updateComponents(j_msg_rcv1, raw_msg);
                    //std::cout << "parse "<< std::endl;
                } 
                catch (json::exception& e) {}
            }
            this->j_msg_rcv = j_msg_rcv1;
            return j_msg_rcv1;

}

void Engine::addObjects(int key[6], int new_key)
{
    for(int i = 0; i < 6; i++)
    {
        if(key[i] == -1)
        {
            this->output->bargraph = i;
            return;
        }
    }

}
