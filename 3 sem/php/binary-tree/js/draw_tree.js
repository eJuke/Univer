//для бинарного дерева
		//для отрисовки связей дерева
		function draw_lineB(x1, y1, x2, y2){
			contextTree.beginPath();
			contextTree.moveTo(x1, y1);
			contextTree.lineTo(x2, y2);
			contextTree.fillStyle="#000";
			contextTree.strokeStyle="#000";
			contextTree.stroke();
		}
		//для отрисовки кружков - узлов дерева
		function draw_circleB(x, y){
			contextTree.beginPath();
			contextTree.arc(x, y, 4, 0, Math.PI*2, false);
			contextTree.stroke();
			contextTree.fillStyle="#000";
			contextTree.fill();

		}
		//для отрисовки подписей
		function draw_labelB(x, y, text){
			contextTree.font = "10px monospace";
			contextTree.fillText (text, x, y);
		}


		//то же самое, но для леса
		//для отрисовки связей дерева
		function draw_lineF(x1, y1, x2, y2){
			contextForest.beginPath();
			contextForest.moveTo(x1, y1);
			contextForest.lineTo(x2, y2);
			contextForest.fillStyle="#000";
			contextForest.strokeStyle="#000";
			contextForest.stroke();
		}
		//для отрисовки кружков - узлов дерева
		function draw_circleF(x, y){
			contextForest.beginPath();
			contextForest.arc(x, y, 4	, 0, Math.PI*2, false);
			contextForest.stroke();
			contextForest.fillStyle="#000";
			contextForest.fill();

		}
		//для отрисовки подписей
		function draw_labelF(x, y, text){
			contextForest.font = "10px monospace";
			contextForest.fillText (text, x, y);
		}

		function showLevels(check){
			var canvas1 = document.getElementById("tree");
			var canvas2 = document.getElementById("forest");
			if (check == 1){
				canvas1.style.backgroundImage = 'url(../img/on.png)';
				canvas2.style.backgroundImage = "url(../img/on.png)";
				check++;
			}
			else {
				canvas1.style.backgroundImage = 'url(../img/off.png)';
				canvas2.style.backgroundImage = "url(../img/off.png)";
				check++;
			}
			
		}