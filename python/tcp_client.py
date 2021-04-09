import socket
socketObject = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socketObject.connect(("localhost", 8888))
print("Connected to localhost")
HTTPMessage = "Hi its me client !!!"
bytes       = str.encode(HTTPMessage)
socketObject.sendall(bytes)
while(True):
    data = socketObject.recv(1024)
    print(data)
    if(data==b''):
        print("Connection closed")
        break
socketObject.close()
