(* Ejemplo de expresion let, la cual permite definir variables locales *)
val lexpr =
    let val x = 1;
        val y = 2;
    in x + y
    end;