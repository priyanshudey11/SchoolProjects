
        switch (operationCode) {
            case READ:
                cout << "Enter an integer: ";
                cin >> memory[operand];
                break;
            case WRITE:
                cout << memory[operand] << endl;
                break;
            case LOAD:
                accumulator = memory[operand];
                break;
            case STORE:
                memory[operand] = accumulator;
                break;
            case ADD:
                accumulator += memory[operand];
                break;
            case SUBTRACT:
                accumulator -= memory[operand];
                break;
            case DIVIDE:
                accumulator /= memory[operand];
                break;
            case MULTIPLY:
                accumulator *= memory[operand];
                break;
            case BRANCH:
                instructionCounter = operand;
                continue;
            case BRANCHNEG:
                if (accumulator < 0) {
                    instructionCounter = operand;
                    continue;
                }
                break;
            case BRANCHZERO:
                if (accumulator == 0) {
                    instructionCounter = operand;
                    continue;
                }
            default:
                
                break;
            case HALT:
                cout << "*** Simpletron execution terminated ***" << endl;
                cout << "REGISTERS:" << endl;
                cout << "accumulator" << setw(20) << setfill(' ') << showpos << setw(4) << internal << accumulator << endl;
                cout << "instructionCounter" << setw(12) <<
        }
    }
}