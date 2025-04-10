const app = require('express')();
const server = require('http').createServer(app);
const io = require('socket.io')(server);

app.get('/', (_, res) => res.sendFile(__dirname + '/index.html'));

io.on('connection', s => s.on('chat', msg => io.emit('chat', msg)));

server.listen(3000);




<!DOCTYPE html>
<html>
  <body>
    <input id="msg" /><button onclick="send()">Send</button>
    <ul id="chat"></ul>

    <script src="/socket.io/socket.io.js"></script>
    <script>
      const s = io(), c = document.getElementById('chat'), i = msg;
      function send() { s.emit('chat', i.value); i.value = ''; }
      s.on('chat', m => c.innerHTML += `<li>${m}</li>`);
    </script>
  </body>
</html>