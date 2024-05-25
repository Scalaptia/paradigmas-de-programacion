structure S = SyncVar
fun main () =
  let val i : int S.ivar = S.iVar ()
  in (
    S.iGetPoll i; 
    S.iPut (i, 10);
    S.iGetPoll i; 
    S.iPut (i, 10);
    OS.Process.success
  )
  end
