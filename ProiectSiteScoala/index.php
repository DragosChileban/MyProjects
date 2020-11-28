<?php
		require "header.php";
?>

	<main>
		<?php
			if (isset($_SESSION['userId'])) {
				echo '<p>Esti conectat!</p>';
			}
			else {
				echo '<p>Esti deconectat!</p>';
			}
		?>
		
		
	</main>

<?php
		require "footer.php";
?>