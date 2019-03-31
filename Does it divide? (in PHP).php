    <?php
     
    function isPrime($x)
    {
        if($x == 2 || $x == 3)
            return true;
        for($i = 2; $i <= sqrt($x); $i++)
            if($x%$i == 0)
                return false;
        return true;
    }
     
    fscanf(STDIN,"%d",$t);
     
    while($t--)
    {
        fscanf(STDIN,"%d",$n);
     
        if($n == 1)
            echo "YES\n";
        else
            isPrime($n+1) ? print "NO\n" : print "YES\n" ;
    }
     
    ?>
