<?php
		require "header.php";
?>

	<main>
		<div><h1>Inregistrare</h1></div>
		<form action="includes/signup.inc.php" method="post">
		<ul class="signup-form">
			<li><label><input type="text" name="uid" placeholder="Utilizator"></label></li>
			<li><label><input type="text" name="mail" placeholder="E-mail"></label></li>
			<li><label><input type="password" name="pwd" placeholder="Parola"></label></li>
			<li><label><input type="password" name="pwd-repeat" placeholder="Confirmati Parola"></label></li>
			<li><label><button type="submit" name="signup-submit">Inregistrare</button></label></li>
		</ul>
		</form>
	</main>

<?php
		require "footer.php";
?>