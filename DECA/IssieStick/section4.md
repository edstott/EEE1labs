# State machine

## Designing the state machine

It's not usually possible to stop the snake moving in a snake game.
If the player releases all the keys then the snake should continue moving in the same direction.
Futhermore, it should be impossible to reverse direction 180° on the spot.

To fix this, we'll need a state machine to remember the current direction of the snake.
The state transition diagram will look like this:

- [ ] TODO: State transition diagram

The push button inputs have the same coding as previously, and this coding is also used for the state machine outputs.
| Input | Meaning |
| ------| ------- |
| 0001  | Left    |
| 0010  | Down    |
| 0100  | Right   |
| 1000  | Up      |

The states are coded accordingly
| State | Meaning |
| ----- | ------- |
| 00    | Left    |
| 01    | Down    |
| 10    | Right   |
| 11    | Up      |

There is one state for every direction and transitions are only possible in right-angle turns.
E.g. if the state machine is in the `LEFT` state then transitions are possible to `UP` or `DOWN`, but not `RIGHT`.
The state machine must be in one of the four states, so the snake will always be moving.

The state machine will sit between the push button inputs and the head position counters, so the input and output will both be 4-bit busses.
It will be a Mealy state machine, meaning that the outputs are a function of the current state and the input — this avoids increasing the lag between pressing a button and the counter updating.
If more than one button is pressed then the state will not change.

Complete a state transition table for the state machine, based on this template:

| Current State | Input | Next State | Output |
| ----- | ------------- | ---------- | ------ |
| 00    | 0000          | 00         | 0001   |
| 00    | 0001          | 00         | 0001   |
| 00    | 0010          | 01         | 0010   |
| 00    | 0011          | 00         | 0001   |
| …     | …             | …          | …      |

- [ ] Complete the state transition table

## Implementing the state machine

The state transition table is quite large because there are 6 inputs and 6 outputs.
You can reduce it using Boolean algebra techniques and implement it with basic logic gates.
However, it's easier to implement it using an *asynchronous ROM*, where you can enter the truth table as memory contents.
That will also be easier to modify and debug.
The FPGA synthesis tool will do its own logic minimisation and it can convert a ROM into an efficient implementation in its lookup tables.

- [ ] TODO: diagram of ROM-based Mealy state machine

This next state and output logic block will require a ROM with 64 words (a 6-bit address port) and a word width of 6 bits.
The state register `STATE` will have 2 bits and an enable port so that it only updates once per prescaler tick.
The address input port will be formed by merging the current state (output of `STATE`) with the 4-bit input.
Notice that the rows of the state transition table are ordered by increasing binary count of the two input columns.
To preserve that ordering when you write the ROM contents, you will need to map the state machine input to the LSBs of the address and the current state to the MSBs.

- [ ] TODO: diagram showing mapping of signals to address inputs

| Current State | Input | Next State | Output | ROM Address | ROM Data |
| ----- | ------------- | ---------- | ------ | ----------- | -------- |
| 00    | 0000          | 00         | 0001   | 0x00        | 0x01     |
| 00    | 0001          | 00         | 0001   | 0x01        | 0x01     |
| 00    | 0010          | 01         | 0010   | 0x02        | 0x12     |
| 00    | 0011          | 00         | 0001   | 0x03        | 0x01     |
| …     | …             | …          | …      | …           | …        |

Create the state machine in a new sheet called `DIRSM` with input ports `IN` and `EN` and and output port `OUT`.
Transfer the state transition table to the ROM contents.
Simulate the completed state machine with step simulation.
Exhaustive testing would be laborious so you can ignore the cases where mutliple buttons are pressed:

| Tick | Input | Expected Next State | Expected Output | Comment |
| ---- | ----- | ------------------- | --------------- | ------- |
| 0    | 0000  | 00                  | 0001            | No Input: stay in state 00: |
| 1    | 0001  | 00                  | 0001            | Input Left: stay in state 00 |
| 2    | 0100  | 00                  | 0001            | Input Right: stay in state 00 |
| 3    | 0010  | 01                  | 0010            | Input Down: switch to state 01 |
| …    | …     | …                   | …               | … |

- [ ] Simulate the state machine sheet

The state machine was designed to use push button signals as inputs and generate the same coding on its outputs, so you can almost drop it into your main sheet between the `PB` input port and the head counter `DIR` inputs.
There is just one complication: the `PB` input port on the main sheet has 5 bits because it includes the centre button on bit 0.
Use a bus select to connect just the upper 4 bits of `PB` to the state machine `IN`.
Likewise, you'll need to connect your head counter `DIR` inputs to bits 0–3 of the state machine output, where previously you used bits 1–4.

Build and upload your design. Now the snake should move all the time with the buttons just acting to change the direction.

- [ ] Test the state machine in the snake game on the IssieStick

## Next steps

There are more features you can add to the game but from here on the guidance will be high level, giving you the opportunity to innovate and try out ideas.

### Food

The aim of a snake game is to eat food.
The starter project contains a sheet `RND8` for generating pseudo-random 8-bit numbers, which can be used as random locations for food.
Connect its `TICK` input to the prescaler to continuously generate new random numbers internally.
Use the `LATCH` input to output a new random number on the `OUT` port whenever the head position matches the food position.
Simulate the sheet first to confirm how it works.

Displaying the food will require an extra memory write to the `LEDMATRIX`.
Don't try to do this only when the food moves — it's simpler to write the food every time the snake moves.
That also prevents the food disappearing if it appears on top of the snake and it gets erased by the tail.
You'll need to convert your toggle into a small state machine (it already was the simplest possible state machine) so that you can execute a 3-stage cycle of write head → erase tail → write food.

- [ ]  TODO: state machine diagram

### Expanding snake

Once your snake can eat food it should start to grow longer.
That requires a variable-length shift register, which is known as a *first-in, first-out* (FIFO) buffer.
A FIFO is implemented using a RAM and two counters.
The counters act as pointers for the write address and read address to the RAM.
A new value (e.g. the head position) is written to the address stored in the write pointer and the write pointer is incremented.
Data is read (e.g. the tail position) from the address stored in the read pointer, which is also incremented.

The pointer increment enables, address multiplexer and read/write enables need to be connected to tick signals that activate on appropriate stages of the memory control state machine.
The FIFO can be accessed at the same time as the display RAM because it's a different memory, so you won't need any more states.
The snake grows by disabling the read pointer increment when a food is reached, so tail position doesn't change on that clock cycle.
The FIFO RAM should be sized to accommodate the maximum possible snake length.

- [ ] TODO: FIFO block diagram

### Collisions

The snake game ends when the snake collides with itself.
How do you know when this happens?
- You could check the locations stored in the tail buffer shift register or FIFO, but that would require a complex state machine to iterate over each value and compare it to the head.
- You could check the display memory to see if the LED is already lit with your snake colour before writing the head, but that would mean modifying the `LEDMATRIX` block to fit the reads in with the LED scanning logic.

The simplest option would be to create a new RAM to record whether every display location is occupied by snake, or not.
That memory needs a word size of only 1 bit.
You can write a 1 when the head is written to the display, using the same address. Likewise write the tail as a zero.
On the third cycle, when the food is written to the display, you can read the RAM to check if the next head location is already set to 1.
If it is, a collision has occurred and you can stop the game by disabling any future change to the state machine.

What happens next is more complicated.
You can't simply reset the FPGA because the contents of the memories, which contain all your game state, is only rewritten when the FPGA is configured.
If you want to show a splash screen, or just clear the memory to start again, you'll need a state machine that can iterate over the display and collision memories to set every value.
The FIFO can be reset more simply by setting the read pointer and write pointer to 0.

