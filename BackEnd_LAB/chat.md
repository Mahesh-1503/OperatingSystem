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




Final single file 

const e = require('express')(), s = require('http').createServer(e), io = require('socket.io')(s);

e.get('/', (r, res) => res.send(`<!DOCTYPE html><html><body>
<input id=m><button onclick="s.emit('c',m.value);m.value=''">Send</button>
<ul id=chat></ul><script src="/socket.io/socket.io.js"></script>
<script>let s=io(),m=msg,c=chat;s.on('c',t=>c.innerHTML+=\`<li>\${t}</li>\`)</script>
</body></html>`));

io.on('connection', x => x.on('c', t => io.emit('c', t)));

s.listen(3000);