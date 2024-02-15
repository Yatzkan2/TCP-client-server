# TCP Client-Server Example

This is a simple TCP client-server example in C.

## Instructions

1. Compile `client.c` and `server.c` separately.
2. Start the server by running `./server`.
3. Start the client by running `./client`.
4. Enter a message in the client terminal, and it will be sent to the server.
5. The server will display the received message along with client information.

## Requirements

- GCC compiler
- Linux environment (for socket programming)

## Usage

- Modify the IP address in `client.c` to match your server's IP address.
- Port number is set to 9090 by default. Change it if needed.
- Compile `client.c` and `server.c` using `gcc -o client client.c` and `gcc -o server server.c`.
- Run the server first, then run the client.
- Use Ctrl+C to stop the server or client.


