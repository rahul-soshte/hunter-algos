 <?php
        $db = new PDO('sqlite::memory:');

    $sql_createtable = "CREATE TABLE `nationalAnimal` (`id` INTEGER PRIMARY KEY AUTOINCREMENT, `country` VARCHAR(255), `animal` VARCHAR(255))";
        $db->exec($sql_createtable);    

         $sql_prepare = "INSERT INTO `nationalAnimal` (`country`, `animal`) VALUES (:country, :animal)";
        /** mutiple inserts with bindParam **/
      //  $stmt = $db->prepare($sql_prepare);
       // $stmt->bindParam(':country', $country, PDO::PARAM_STR);
       // $stmt->bindParam(':animal', $animal, PDO::PARAM_STR);
      //  $foo[] = array('America', 'eagle');
        //$foo[] = array('China', 'dragon');
       // foreach($foo as $data) {
        //  $country = $data[0];
       //   $animal = $data[1];
         // $stmt->execute();
        //}
        
        /** multiple inserts with execute **/ 
        $stmt = $db->prepare($sql_prepare);
        $bar[] = array(':country' => 'England', ':animal' => 'lion');
        $bar[] = array(':country' => 'India', ':animal' => 'tiger');
        foreach($bar as $data) {
         $stmt->execute($data);
          // an alternative method below that (could) result in less typing depending on how the array is constructed
          // $stmt->execute(array(':country' => $data[':country'], ':animal' => $data[':animal']));
        }


//         single insert with bindValue, then execute 
  //      $stmt = $db->prepare($sql_prepare);
    //    $stmt->execute(array(':country' => 'Australia', ':animal' => 'kangaroo');
      //  $stmt->bindValue(':country', 'Norway', PDO::PARAM_STR);
       // $stmt->bindValue(':animal', 'elk', PDO::PARAM_STR);
       // $stmt->execute();

      //  $stmt = $db->query("SELECT `id`, `country`, `animal` FROM `nationalAnimal`");
       // while($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
         // $results[] =  'id:' . $row['id'] . ', country: ' . $row['country'] . ', animal: ' . $row['animal'];
       // }

        //var_dump($results);
        

                $stmt = $db->prepare("SELECT `id`, `country`, `animal` FROM `nationalAnimal` WHERE `id` != :id ORDER BY `country`");
        $stmt->execute(array(":id" => 1));
       $rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
        var_dump($rows);
       // $stmt = $db->prepare("SELECT `country`, `animal` FROM `nationalAnimal` WHERE `id` = :id");
       // $stmt->execute(array(":id" => 3));
       // $rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
    //var_dump($rows);
        
 ?>

