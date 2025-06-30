This project is a minimalistic, stack-based virtual machine implemented in C. It demonstrates fundamental concepts of low-level computation, including instruction handling, stack operations, and control flow through an instruction pointer.
📦 Features
- Stack memory operations (PUSH, POP)
- Arithmetic operation: ADD
- Program control using HLT (halt)
- Custom instruction evaluation through an enum-based instruction set
🚀 Program Flow
The VM executes a hardcoded set of bytecode-like instructions defined in the program array:
const int program[] = {
    PSH, 5,     // Push 5 onto the stack
    PSH, 6,     // Push 6 onto the stack
    ADD,        // Add the top two stack values
    POP,        // Pop and print the result
    HLT         // Halt execution
};


🧱 Instruction Set
| Instruction | Description | 
| PSH | Push the next value onto the stack | 
| POP | Pop and print the top value from the stack | 
| ADD | Pop two values, add them, and push result | 
| HLT | Halt program execution | 


🛠 How It Works
- fetch(): Retrieves the next instruction based on the instruction pointer (ip)
- eval(int instr): Evaluates and executes the instruction logic
- The VM loop in main() repeatedly fetches and evaluates instructions until halted.
🗂 Memory Layout
- Stack: Fixed size of 256 integers
- Instruction Pointer (ip): Tracks the current instruction in program[]
- Stack Pointer (sp): Tracks the top of the stack
📚 Sample Output
Popped 11


This output results from pushing 5 and 6 onto the stack, adding them (producing 11), and then popping and printing the result.
✨ Potential Extensions
- Add more instructions like SUB, MUL, DIV
- Implement control flow: JMP, IF, CALL
- Support input and memory access


