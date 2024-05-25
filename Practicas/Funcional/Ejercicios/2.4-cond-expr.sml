val trueCond =
  if (1 = 1)
  then 1
  else 0

val elseCond =
  if (1 = 0)
  then 1
  else if (1 = 1)
  then ~1
  else 0