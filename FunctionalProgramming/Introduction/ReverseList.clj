(fn[lst]
  (reduce (fn[rlst x](cons x rlst)) nil lst))
