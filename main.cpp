#include <iostream>

int main() {
    
    std::string code = "";
    int tape[256] = {0,0};
    int ptr = 0, inputVal = 0, trackLoop = 0;
    std::string outAscii = "", outNum = "";
    int tapeSize = sizeof(tape) / sizeof(tape[0]);

    std::cout << "Welcome to Austin's Brainfuck Interpretor\n\nEnter your Brainfuck code: " << std::endl;
    getline(std::cin, code);
    
    for(int i = 0; i < code.size(); i++) {
        switch(code[i]) {
            case '+':
                tape[ptr]++;
                if(tape[ptr] > 255) {
                    tape[ptr] = 0;
                }
                break;
            case '-':
                tape[ptr]--;
                if(tape[ptr] < 0) {
                    tape[ptr] = 255;
                }
                break;
            case '<':
                ptr--;
                if(ptr < 0) {
                    ptr = tapeSize - 1;
                }
                break;
            case '>':
                ptr++;
                if(ptr == tapeSize) {
                    ptr = 0;
                }
                break;
            case ',':
                do {
                    if(!std::cin || inputVal < 0 || inputVal > 255) {
                        std::cout << "Error: Invalid input. Please try again" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(256, '\n');
                    }
                    std::cout << "Enter a number between 0-255 inclusive: ";
                    std::cin >> inputVal;
                    std::cout << std::endl;
                }
                while(!std::cin || inputVal < 0 || inputVal > 255);
                tape[ptr] = inputVal;
                break;
            case '.':
                outAscii += static_cast<char>(tape[ptr]);
                outNum += std::to_string(tape[ptr]) + " ";
                break;
            case '[':
                if(tape[ptr] == 0) {
                    trackLoop = 1;
                    while(trackLoop > 0) {
                        i++;
                        if(code[i] == '[') {
                            trackLoop++;
                        }
                        if(code[i] == ']') {
                            trackLoop--;
                        }
                    }
                }
                break;
            case ']':
                trackLoop = 1;
                while(trackLoop > 0) {
                    i--;
                    if(code[i] == ']') {
                        trackLoop++;
                    }
                    if(code[i] == '[') {
                        trackLoop--;
                    }
                }
                i--;
                break;
        }
    }

    std::cout << std::endl <<
        "Ascii: " << outAscii << std::endl <<
        "Numeric: " << outNum << std::endl;
}
