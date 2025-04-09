const express = require("express");
const bodyParser = require("body-parser");
const app = express();
const port = 3000;

app.use(bodyParser.json());

let items = []; // in-memory list
let id = 1;

// CREATE
app.post("/items", (req, res) => {
  const item = { id: id++, name: req.body.name };
  items.push(item);
  res.send(item);
});

// READ
app.get("/items", (req, res) => {
  res.send(items);
});

// UPDATE
app.put("/items/:id", (req, res) => {
  const item = items.find((i) => i.id == req.params.id);
  if (!item) return res.status(404).send("Not found");
  item.name = req.body.name;
  res.send(item);
});

// DELETE
app.delete("/items/:id", (req, res) => {
  items = items.filter((i) => i.id != req.params.id);
  res.send({ message: "Deleted" });
});

app.listen(port, () => {
  console.log(`CRUD server at http://localhost:${port}`);
});
