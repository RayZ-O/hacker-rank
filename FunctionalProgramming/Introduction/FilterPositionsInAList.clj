(fn[lst]
  (keep-indexed #(when (odd? %1) %2) lst))
