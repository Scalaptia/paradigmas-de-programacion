structure S = SyncVar
fun main () =
  let val i : int S.mvar = S.mVar ()
  in (
    S.mPut (i, 10);
    S.mGet i; 
    S.mPut (i, 10);
    S.mTake i; 
    S.mPut (i, 0);
    S.mGet i; 
    OS.Process.success
  )
  end
