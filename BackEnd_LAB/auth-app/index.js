const express = require("express");
const bodyParser = require("body-parser");
const app = express();
const port = 3000;

app.use(bodyParser.json());

const users = []; // In-memory user store

// Register
app.post("/register", (req, res) => {
  const { username, password } = req.body;
  const exists = users.find((u) => u.username === username);
  if (exists) return res.status(400).send("User already exists");
  users.push({ username, password });
  res.send("Registration successful");
});

// Login
app.post("/login", (req, res) => {
  const { username, password } = req.body;
  const user = users.find(
    (u) => u.username === username && u.password === password
  );
  if (!user) return res.status(401).send("Invalid credentials");
  res.send(`Welcome, ${username}!`);
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
