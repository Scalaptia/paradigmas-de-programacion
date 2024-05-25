val x = ref 10
val y = ref 20

val _ = x := !x + !y
val _ = !x (* 30 *)

fun ++ (x: int ref) : int = (
    x := !x + 1;
    !x 
)

val x = ref 0
val xNewState = ++x 
val xValue = !x 
