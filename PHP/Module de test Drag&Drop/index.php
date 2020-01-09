<!DOCTYPE HTML>
<html>
<head>
<style>
#div1, #div2 {
  float: left;
  width: 200px;
  height: 58px;
  margin: 10px;
  padding: 10px;
  border: 1px solid black;
}
</style>
<script>
function allowDrop(ev) {
  ev.preventDefault();
}

function drag(ev) {
  ev.dataTransfer.setData("text", ev.target.id);
}

function drop(ev) {
  ev.preventDefault();
  var data = ev.dataTransfer.getData("text");
  ev.target.appendChild(document.getElementById(data));
}
</script>
</head>
<body>

<h2>Drag and Drop</h2>
<p>Faites glisser l'image dans le cadre suivant.</p>

<div id="div1" ondrop="drop(event)" ondragover="allowDrop(event)">
  <img src="https://media.giphy.com/media/7GHRDluBmx9O8/giphy.gif" draggable="true" ondragstart="drag(event)" id="drag1" width="200" height="58">
</div>

<div id="div2" ondrop="drop(event)" ondragover="allowDrop(event)"></div>

</body>
</html>