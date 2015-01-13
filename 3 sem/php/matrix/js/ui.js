function hoverButton(id, status){
	if (id == 1) {
		if (status == true) document.getElementById("ex1-1").src = 'images/b1-pressed.png';
		else document.getElementById("ex1-1").src = 'images/b1.png';
	}
	if (id == 2) {
		if (status == true) document.getElementById("ex1-2").src = 'images/b2-pressed.png';
		else document.getElementById("ex1-2").src = 'images/b2.png';
	}
}

function fadeAnim(){
	document.getElementById("overflow-menu").classList.remove('fadeInDown');
	document.getElementById("overflow-menu").classList.add('fadeOutUp');
	setTimeout(function(){document.getElementById('overflow-menu').style.display = 'none';} ,1500);
	setTimeout(function(){
		document.getElementById('header-button').classList.remove('fadeOutUp');
		document.getElementById('header-button').classList.add('fadeInDown');
		document.getElementById('header-button').style.display = 'block';} ,1500);
}

function showOverflow(){
	console.log("show overflow");
	document.getElementById('header-button').classList.remove('fadeInDown');
	document.getElementById('header-button').classList.add('fadeOutUp');
	setTimeout(function(){document.getElementById('header-button').style.display = 'none';} ,1500);
	document.getElementById("overflow-menu").classList.remove('fadeOutUp');
	document.getElementById("overflow-menu").classList.add('fadeInDown');
	document.getElementById('overflow-menu').style.display = 'block';
}


function addElem(x, y, v, type) {
	var elem = '<div class="menu-value-div" id="id' + x +'-' + y + '-' + v;
	elem +='"><div class="menu-value"><p class="menu-value-text">X:&nbsp</p><p>' + x;
	elem += '</p></div><div class="menu-value"><p class="menu-value-text">Y:&nbsp</p><p>' + y;
	elem += '</p></div><div class="menu-value"><p class="menu-value-text">V:&nbsp</p><p>' + v;
	elem += '</p></div><div class="menu-value-del" onclick="removeValue(' + x + ',' + y + ',' + v + ')"><img src="images/cross.svg"></img></div></div>';
	if (type ==1 ) $('#showValues').append(elem);
	var id = 'id' + x +'-' + y + '-' + v;
	console.log(id+' added');
}

function removeElem(x, y, v){
	var id = 'id' + x +'-' + y + '-' + v;
	$('#'+id).remove();
	console.log(id+' removed');
}

function draw_labelB(x, y, text){
	contextTree.font = "14px bold monospace";
	contextTree.fillStyle = "#FF0000";
	contextTree.fillText (text, x, y);
}

function draw_label(x, y, text){
	contextTree.font = "14px monospace";
	contextTree.fillText (text, x, y);
}

function printAnswer(x, y, v){
	var elem = "<div class=\"ex1-answer\"><p><span>&nbspX:</span>" + x + "<span>&nbspY:</span>" + y + "<span>&nbspValue:</span>" + v + "</p></div>";
	$('#display').append(elem);
}

function delAnswers(){
	$('.ex1-answer').remove();
}

function clearFields(id){
	$('#display').empty();
	$('#showValues').empty();
	$('#ex1form').trigger('reset');
	console.log("fields cleared");
	if (id == 1) $('#ex2form').remove();
}