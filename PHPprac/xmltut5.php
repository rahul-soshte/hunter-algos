<?php
// set name of XML file
// normally this would come through GET
// it's hard-wired here for simplicity
$file = "data.xml";
// load file
$xml = simplexml_load_file($file) or die ("Unable to load XML file!");
?>
<html>
<head></head>
<body>
<!-- title and year -->
<h1><?php echo $xml->title; ?> (<?php echo $xml->year; ?>)</h1>
<!-- slug -->
<h3><?php echo $xml->teaser; ?></h3>
<!-- review body -->
<?php echo $xml->body; ?>
<!-- director, cast, duration and rating -->
<p align="right"/>
Director: <b><?php echo $xml->director; ?></b>
Duration: <b><?php echo $xml->duration; ?> min</b>
Cast: <b><?php foreach ($xml->cast->person as $person) { echo "$person "; } ?></b>
Rating: <b><?php echo $xml->rating; ?></b>
</body>
</html>

