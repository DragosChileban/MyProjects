<?php 
	session_start();
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name=viewport content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="styles.css">
	<title>ProiectSiteScoala</title>
</head>
<body>

	<header>
		<nav>
			<a class="logo-container" href="#">
				<img src="img/logo.jpg" alt="logo">
			</a>
		</nav>
		<div>
			<?php
				if (isset($_SESSION['userId'])) {
				echo '<form action="includes/logout.inc.php" method="post">
				<button type="submit" name="logout-submit">Deconectare</button>
			</form>';
				}
				else {
					echo '<form class="signin-form" action="includes/login.inc.php" method="post">
					<input type="text" name="mailuid" placeholder="Utilizator">
					<input type="password" name="pwd" placeholder="Parola">
					<button type="submit" name="login-submit">Autentificare</button>
				</form>
				<a class="signup-link" href="signup.php"><h2>Inregistrare</h2></a>';
				}
			?>
			
			
		</div>
	</header>


