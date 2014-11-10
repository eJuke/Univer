<html>
<head>
	<meta charset="UTF-8">
	<title>Result</title>
	<link rel="stylesheet" type="text/css" href="css/main.css">
	<meta charset="windows-1251">
</head>	
<body>
	<h1>Построение изображений дерева и леса</h1>
	<?php
//класс, описывающий узел бинарного дерева
		class bNode {
			public $value = 0;
			public $left = NULL;
			public $right = NULL;
			public $countL = 0;
			public $countR = 0;

			public function __construct ($inp){	$this->value = $inp;}

			public function setCounter($left){
				if ($left == true) ++$this->countL;
				if ($left == false) ++$this->countR;
			}
		}

//класс для построения бинарного дерева
		class bTree {
			public $root = NULL;
			public $height = 0;
			public $countH = 0;

			public function insert($value){
				$this->countH = 0;
				$bNode = new bNode($value);
				$this->insertSearch($bNode, $this->root);
			}

			public function insertSearch(bNode $tNode, &$subtree){
				if (is_null($subtree)) $subtree = $tNode;
				else{
					$this->countH++;
					if($tNode->value >= $subtree->value){
						$subtree->setCounter(false);
						$this->insertSearch($tNode, $subtree->right);
					}
					else if($tNode->value < $subtree->value){
						$subtree->setCounter(true);
						$this->insertSearch($tNode, $subtree->left);
					}
				}
				if ($this->countH > $this->height) $this->height = $this->countH;
				return $this;
			}

			public function testIt(){
				var_dump($this->root);
			}
		}

//узел простого дерева леса
		class node{
			public $value;
			public $childs = NULL;
			public $allChildsCount = 0;
			public $heightAtThisLvl = 0;

			public function __construct($inp){	$this->value = $inp;}
			public function addChild($node){	$this->childs[$this->massCount++] = $node;}
		}

//класс для леса 
		class fTree {
			public $bTrees = NULL;
			public $childs = NULL;
			public $maxHeight = 0;

			public function findNextTree(bNode $node, $count){
				if (isset($node)){
					$this->bTrees[$count] = $node;
					if (isset($node->right))$this->findNextTree($node->right, $count+1);
				}
			}

			public function findSubtrees(){
				for ($i = 0; $i < count($this->bTrees); $i++){
					$this->childs[$i] = new node($this->bTrees[$i]->value);
					$this->childs[$i]->allChildsCount = $this->bTrees[$i]->countL;
					if(isset($this->bTrees[$i]->left)){
						$this->walk($this->childs[$i], $this->bTrees[$i]->left, 0);
					}
				}
			}

			public function walk($parent, $node, $count){
				$parent->childs[$count] = new node($node->value);
				$parent->childs[$count]->allChildsCount = $node->countL;
				if (isset($node->right))	$this->walk($parent, $node->right, $count+1);
				if (isset($node->left))		$this->walk($parent->childs[$count], $node->left, 0);
			}

//нахождение высоты обычного дерева для рассчета к-т
			function findHeightOfTree($node){
				$cache;
				for ($i=0; $i < count($node->childs); $i++) { 
					if(isset($node->childs[$i])) $cache[$i] = $this->findHeightOfTree($node->childs[$i]);
					else $cache[$i] = -1;
				}
				$max = -1;
				for ($j=0; $j < count($cache); $j++) { 
					if ($cache[$j] > $max) $max = $cache[$j];
				}
				return $max+1;
			}

			function findMaxHeight(){
				$max = 0;
				foreach ($this->childs as $node) {
					$cache = $this->findHeightOfTree($node);
					if($max < $cache) $max = $cache;
				}
				return $max;
			}
		}


// построение дерева в зависимости от заданных данных
		if ($_POST["choice"] == "user"){
			$input = explode("\n",$_POST["inputVar"]);
		}
		else {
			if ($_POST["size"] > 100 || $_POST["size"] < 0) 
				echo "Похоже кому-то нужен учебник по русскому языку, тк ясно же написано \"Положительное число не больше 100\"";
			else {
				for ($i = 0; $i < $_POST["size"]; $i++) $input[$i] = rand(0, $_POST["size"]*10);
			}
		}
		$binaryTree = new bTree;
		foreach($input as $value) $binaryTree->insert(intval($value));
		$canvasWidth = (count($input)-1)*20+50;
		$canvasHeight = $binaryTree->height*30+30;
//		$binaryTree->testIt();

//вывод дерева "в ширину"
		function output($root, $input){
			$cache; $counterNow = 0; $counterAll = 1;
			$cache[0] = $root;
			while($counterAll < count($input)){
				if(isset($cache[$counterNow]->left)){
					$cache[$counterAll++] = $cache[$counterNow]->left;
				}
				if(isset($cache[$counterNow]->right)){
					$cache[$counterAll++] = $cache[$counterNow]->right;
				}
				$counterNow++;
			}
			for ($i = 0; $i < count($cache)-1; $i++) echo $cache[$i]->value." , ";
			echo $cache[count($cache)-1]->value;
		}

//алгоритм рассчета координат для отрисовки дерева
		function subtreeDraw(bNode $subtree, $heightLvl, $x_up, $y_up, $way){
			if ($way == "left") $x = $x_up-20-20*$subtree->countR;
			if ($way == "right") $x = $x_up+20+20*$subtree->countL;
			$y = $heightLvl*30;
			codeGen($x, $y, $x_up, $y_up, $subtree->value, "B");
			if (isset($subtree->left))  subtreeDraw($subtree->left,  $heightLvl+1, $x, $y, "left");
			if (isset($subtree->right)) subtreeDraw($subtree->right, $heightLvl+1, $x, $y, "right");
		}

//генератор js кода
		function codeGen($x, $y, $x_up, $y_up, $label, $raga){
			$y += 15; $y_up += 15;
			if ($y_up != 14) echo "\t\t\tdraw_line$raga($x+20, $y, $x_up+20, $y_up);\n";
			echo "\t\t\tdraw_circle$raga($x+20, $y);\n";
			if ($x_up > $x) $x -= 15;
			$y -= 6;
			echo "\t\t\tdraw_label$raga($x+20, $y, $label);\n";
		}

//преобразование дерева в лес 
		$forest = new fTree;
		$forest->findNextTree($binaryTree->root, 0);
		$forest->findSubtrees();
		$forest->maxHeight = $forest->findMaxHeight();
		$canvasHeightForest = 30+30*$forest->maxHeight;




//рассчет к-т для отрисовки леса
		function forestDraw($node, $startX, $leftBorder, $rightBorder, $heightLvl, $x_up, $y_up){
			$y = $heightLvl*30;
			$mem = 0;
			$all = 0;
			$right = 0;
			if (isset($node->childs)){
				foreach($node->childs as $child){
					if ($child->allChildsCount == 0) $all++;
					else $all += $child->allChildsCount;
				}
				foreach($node->childs as $children){
					$mem += $right;
					if ($children->allChildsCount != 0) $right = round(($children->allChildsCount / $all)*($rightBorder - $leftBorder));
					else $right = round(($rightBorder - $leftBorder) / $all);
					$x = round($right / 2);
					codeGen($startX+$leftBorder+$mem+$x, $y, $startX+$x_up, $y_up, $children->value, "F");
					forestDraw($children, $startX, $leftBorder+$mem, $leftBorder+$mem+$right, $heightLvl+1, $startX+$leftBorder+$mem+$x, $y);
				}
			}
		}

	?>


	<form>
		<input type="button" value="Показать разделитель уровней" onclick="showLevels(1)">
		<input type="button" value="Скрыть разделитель уровней" onclick="showLevels(0)">
	</form>
	<p>Бинарное дерево</p>
	<canvas id="tree" class="img" <? echo "width=\"".$canvasWidth."\" height=\"".$canvasHeight."\""; ?>></canvas>
	<p>Лес деревьев</p>
	<canvas id="forest" class="img" <? echo "width=\"".$canvasWidth."\" height=\"".$canvasHeightForest."\""; ?>></canvas>
	<p>Вывод бинарного дерева "в ширину"</p>
	<p><? output($binaryTree->root, $input); ?></p>
	<script src="/js/draw_tree.js"></script>
	<script>
		function browser_support(){
			return !!document.createElement("canvas").getContext;
		}

		if (browser_support()){
			var tree = document.getElementById("tree");
			var contextTree = tree.getContext("2d");
			var forest = document.getElementById("forest");
			var contextForest = forest.getContext("2d");
			draw();
			drawF();
		}
		else {
			alert("I can't draw a tree in your browser");
		}

		//отрисовка дерева
		function draw(){
<?php
subtreeDraw($binaryTree->root, 0, $canvasWidth-25, -1, "left");
			?>
		}
		//отрисовка леса
		function drawF(){
<? forestDraw($forest, 0, 0, $canvasWidth-50, 0, -1, -1)?>
		}


	</script>

</body>
</html>