var array = [];
var checkMass = [];
var count = 0;
var ex2form = "<form id=\"ex2form\" method=\"post\"><div class=\"topFormDiv\"><div class=\"divInp\"><p class=\"textM\">";
ex2form += "Размеры матриц А и В</p></div><div class=\"divInp\"><input type\"button\" value=\"Согласовать\" class=\"inputBtn\"";
ex2form += " id=\"conform\"></div></div><div class=\"topFormDiv\"><div class=\"divInp\"><input type=\"text\"";
ex2form += " class=\"inputForm\" name=\"\" id=\"Ai\"><p>Ai:</p></div><div class=\"divInp\"><input type=\"text\" class=\"";
ex2form += "inputForm\" name=\"\" id=\"Aj\"><p>Aj:</p></div></div><div class=\"bottomFormDiv\"><div class=\"divInp\"><input";
ex2form += " type=\"text\" class=\"inputForm\" name=\"\" id=\"Bi\"><p>Bi:</p></div><div class=\"divInp\"><input type=\"text";
ex2form += "\" class=\"inputForm\" name=\"\" id=\"Bj\"><p>Bj:</p></div></div>";

nowId = 0;
function userChoice(id){
	if (nowId != id) {
		nowId = id;
		clearFields(id);
		array = [];
		checkMass = [];
		count = 0;
		if (id == 1){
			$('#display').append("<h3>&nbspСписок седловых точек</h3>");
		}
		else if (id == 2){
			$('.menu-addValue').append(ex2form);
		}
		else console.log("oops, something is wrong at id change");
	}
	fadeAnim();
}

function addValue(id){
	switch(id){
		case 1:{
			var x = document.forms["ex1form"].elements["X"].value;
			var y = document.forms["ex1form"].elements["Y"].value;
			var v = document.forms["ex1form"].elements["Value"].value;
			if (x == '' || y == '' || v == '') alert("Необходимо заполнить все поля!");
			else if (x < 0 || y < 0) alert('X и Y не могут быть отрицательными:D');
			else if (!isNaN(x) && !isNaN(y) && !isNaN(v)) {
				if (check(x, y)){
					var mem = new Object();
					mem.x = x;
					mem.y = y;
					mem.v = v;
					array[count++] = mem;
					addElem(x, y, v, 1);
					testList();
					reCalculate1();
				}
				else alert("На данной позиции уже есть элемент.");
			}
			else alert("Значениями X, Y, Value могут быть только числа!");
			break;
		}
		case 2:{

		}
	}
}

function removeValue(x, y, v){
	for (var i = 0; i < array.length; i++){
		if (array[i].x == x && array[i].y == y) {
			array.splice(i ,1);
			count--;
			break;
		}
	}
	var str = x + "-" + y;
	for (var i = 0; i < checkMass.length; i++) if (checkMass[i] == str){ checkMass.splice(i, 1); break;}
	removeElem(x, y, v);
	reCalculate1();
	testList();
}

function reCalculate1(){
	delAnswers();
	for (var i = 0; i < array.length; i++){
		var cache = [];
		var count = 0;
		var countX = 0;
		var countY = 0;
		for (var j = 0; j < array.length; j++){
			if (i != j && (array[i].x == array[j].x)) {
				cache[count++] = array[j];
				countX++;
			}
			if (i != j && (array[i].y == array[j].y)){
				cache[count++] = array[j];
				countY++;
			}
		}
		if (countX != 0 && countY != 0) {
			var maxX, minX, maxY, minY;
			maxX = minX = maxY = minY = array[i];
			for (var k = 0; k < count; k++){
				if (cache[k].x == array[i].x){
					if (cache[k].v > maxX.v) maxX = cache[k];
					if (cache[k].v < minX.v) minX = cache[k];
				}
				if (cache[k].y == array[i].y){
					if (cache[k].v > maxY.v) maxY = cache[k];
					if (cache[k].v < minY.v) minY = cache[k];
				}
			}
			// console.log(maxX);
			// console.log(minX);
			// console.log(maxY);
			// console.log(minY);
			// console.log(array[i] + "\n");
			if (maxX.x == minY.x && maxX.x == array[i].x && maxX.y == minY.y && maxX.y == array[i].y && maxX.v == minY.v && maxX.v == array[i].v) printAnswer(array[i].x, array[i].y, array[i].v);
			if (minX.x == maxY.x && minX.x == array[i].x && minX.y == maxY.y && minX.y == array[i].y && minX.v == maxY.v && minX.v == array[i].v) printAnswer(array[i].x, array[i].y, array[i].v);
		}
	}
}

function check(x, y){
	var str = x + "-" + y;
	var cc = 0;
	if (checkMass.length != 0) {
		for (; cc < checkMass.length; cc++){
			if (checkMass[cc] == str) return false;
		}
	}
	checkMass[cc] = str;
	return true;
}

function testList(){
	//for (var i = 0; i < checkMass.length; i++) console.log(checkMass[i]);
	//console.log("\n" + array.length); 
	for (var i = 0; i < array.length; i++) console.log(i + ": " + array[i].x + "-" + array[i].y + " - " + array[i].v);
}
