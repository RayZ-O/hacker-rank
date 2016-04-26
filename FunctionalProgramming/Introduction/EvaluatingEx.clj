(defn fac [n]
  (if (zero? n) 1 (reduce * (range 1 (inc n)))))

(defn evalex [x]
  (reduce (fn[acc i] (+ acc (/ (Math/pow x i) (fac i)))) 0.0 (range 10)))

(let [lines (line-seq (java.io.BufferedReader. *in*))]
  (doall (map #(println (evalex (read-string %))) (rest lines))))
